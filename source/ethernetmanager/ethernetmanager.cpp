
#include "ethernetmanager.hpp"

ethernetmanager::ethernetmanager(QObject* parent)
{
    qInfo () << "i'm the ethernet manager welcome elsayed (:";
    QTimer::singleShot(0, this, SLOT(init())); 
}

// Protected constructor implementation
ethernetmanager::ethernetmanager(QDBusInterfaceWrapperInterface* dbusInterface)
    : ethernetmanager()
{
    // Common initialization logic
    qInfo() << "Initializing testable ethernet manager...";
    m_pDbusInterface = dbusInterface;    
}

void ethernetmanager::init(){
    qInfo() << "Stating the Initialization...";
    mPathEth0 = getCurrectInterfaceLinkForEth();
    if (m_pDbusInterface == nullptr){
        m_pDbusInterface = new iQDBusInterface(
        "org.freedesktop.network1",
        mPathEth0, // Ensure mPathEth0 is a valid object path
        "org.freedesktop.network1.Link",
        QDBusConnection::systemBus()
        );
    } else {
        qInfo () << "i'm already initalize";
    }
    qInfo() << "####" << mPathEth0;

    parseNetworkInfo(getAllInfoForEth());

    QDBusConnection systemBus = QDBusConnection::systemBus();
    qInfo() << "#####################" ;
    if (!systemBus.isConnected()) {
        qInfo() << "#####################" ;
    qInfo() << "Failed to connect to system bus:" << systemBus.lastError().message();
    return;
    }   

    bool connected = systemBus.connect(
        "org.freedesktop.network1", // Any service
        mPathEth0, // Object path
        "org.freedesktop.DBus.Properties", // Interface
        "PropertiesChanged", // Signal name
        this,
        SLOT(onPropertiesChanged(QString, QVariantMap, QStringList)));

    if (connected) {
        qInfo() << "Successfully connected to PropertiesChanged signal.";
    } else {
        qInfo() << "Failed to connect to PropertiesChanged signal:" << systemBus.lastError().message();
    }
}


ethernetmanager::~ethernetmanager() = default;

void ethernetmanager::onPropertiesChanged(QString interfaceName, QVariantMap changedProps, QStringList invalidatedProps) {
    for (auto it = changedProps.begin(); it != changedProps.end(); ++it) {
        if( it.key() == QString("IPv4AddressState")){
            if (it.value().toString() == "off"){
                qInfo() << "clearing all eth0 info";
                m_sMaCAddress = QString();
                m_sIPv4 = QString();
                m_sSubnetMaskIPv4 = QString();
                m_sIPv4Gateway= QString();
                m_sDNSv4= QString();
                m_sIPv6= QString();
                m_iPrefixLengthIPv6 = int();
            } else if (it.value().toString() == "routable"){
                parseNetworkInfo(getAllInfoForEth());
            }
        } else if (it.key() == QString("IPv6AddressState")){
            if (it.value().toString() == "routable") {
                parseNetworkInfo(getAllInfoForEth());
            }
        }
        
    }
}

QString ethernetmanager::getCurrectInterfaceLinkForEth() {

    QDBusInterface iface(
        "org.freedesktop.network1",
        "/org/freedesktop/network1",
        "org.freedesktop.network1.Manager",
        QDBusConnection::systemBus()
    );
    if(!iface.isValid()){
        qInfo() << "the dbus interface is not valid";
        return QString();
    }
    QDBusMessage reply = iface.call(QString("GetLinkByName"), QString("eth0"));


    QDBusObjectPath path = reply.arguments().at(1).value<QDBusObjectPath>();
    return path.path();
}

QString ethernetmanager::getAllInfoForEth(){
    if(m_pDbusInterface->isValid())
    {
        QDBusReply<QString> reply = m_pDbusInterface->call("Describe");
        QString jsonData = reply.value();
        return jsonData;
    } else {
        return QString();
    }

}

QString ethernetmanager::getIPv4GatewayforEthernet()
{
    return m_sIPv4Gateway;
}

QString ethernetmanager::getIPv4SubnetforEthernet()
{
    return m_sSubnetMaskIPv4;
}

QString ethernetmanager::getIPv4forEthernet()
{
    qInfo() << "getIPv4forEthernet" << m_sIPv4;
    return m_sIPv4;
}

QString ethernetmanager::getIPv4DNSforEthernet()
{
    return m_sDNSv4;
}

QString ethernetmanager::getIPv6GatewayforEthernet()
{
    return QString();
}

int ethernetmanager::getIPv6PrefixLengthforEthernet()
{
    return m_iPrefixLengthIPv6;
}

QString ethernetmanager::getIPv6forEthernet()
{
    return m_sIPv6;
}
QString ethernetmanager::getIPv6DNSforEthernet()
{
    return m_sDNSv6;
}
QJsonDocument ethernetmanager::parseNetworkInfo(QString reply)
{
    QJsonDocument networkConfig = QJsonDocument::fromJson(reply.toUtf8());
    qInfo() << "Parsing network configuration.";
    QJsonDocument doc;

    if (!networkConfig.isNull()) {
        if (networkConfig.isObject()) {
            QJsonArray macAddressArray = networkConfig["PermanentHardwareAddress"].toArray();
            QJsonArray dnsArray = networkConfig["DNS"].toArray();
            QJsonArray routersArray = networkConfig["Routes"].toArray();
            QJsonArray addressArray = networkConfig["Addresses"].toArray();
            // qInfo() <<  "dnsArray" << dnsArray;

            //for fetching ip and PrefixLength (v4 and v6)
            foreach (QJsonValue address, addressArray) {
                if (address.toObject()["Family"].toInt() == eWiFiFormatType::FormatType_IPV4
                    && (!address.toObject()["Address"].toArray().isEmpty())) {
                    QJsonArray ipv4 = address.toObject()["Address"].toArray();
                    int prefix = address.toObject()["PrefixLength"].toInt();
                    m_sSubnetMaskIPv4 = prefixToSubnetMask(prefix);
                    m_sIPv4 = convertQJsonArrayToQStringFormat(ipv4, eWiFiFormatType::FormatType_IPV4);
                    qInfo() << "ethernet info" << QString("ipv4= %1 and Subnet= %2").arg(m_sIPv4).arg(m_sSubnetMaskIPv4);
                    
                } else if (address.toObject()["Family"].toInt() == eWiFiFormatType::FormatType_IPV6
                    && (!address.toObject()["Address"].toArray().isEmpty())
                    && (address.toObject()["ScopeString"].toString() == "global")) {
                    QJsonArray ipv6 = address.toObject()["Address"].toArray();
                    m_iPrefixLengthIPv6 = address.toObject()["PrefixLength"].toInt();
                    m_sIPv6 = convertQJsonArrayToQStringFormat(ipv6, eWiFiFormatType::FormatType_IPV6);
                    qInfo() << "ethernet info" << QString("ipv6= %1 and prefix= %2").arg(m_sIPv6).arg(m_iPrefixLengthIPv6);
 
                }      
            }
            //for fetching the gateway (v4 and v6)
            foreach (QJsonValue router, routersArray) {
                if (!router.toObject()["Gateway"].toArray().isEmpty()) {
                    if (router.toObject()["Family"].toInt() == eWiFiFormatType::FormatType_IPV4){
                        QJsonArray ipv4_GatewayArray = router.toObject()["Gateway"].toArray();
                        m_sIPv4Gateway = convertQJsonArrayToQStringFormat(ipv4_GatewayArray, eWiFiFormatType::FormatType_IPV4);
                        qInfo() << "ethernet info" << QString("IPv4Gateway= %1 ").arg(m_sIPv4Gateway);

                    } else if (router.toObject()["Family"].toInt() == eWiFiFormatType::FormatType_IPV6){
                        QJsonArray ipv6_GatewayArray = router.toObject()["Gateway"].toArray();
                        m_sIPv6Gateway = convertQJsonArrayToQStringFormat(ipv6_GatewayArray, eWiFiFormatType::FormatType_IPV6);
                        qInfo() << "ethernet info" << QString("IPv6Gateway= %1 ").arg(m_sIPv6Gateway);
                    }
                } 
            }
            //for fetching the DNS (v4 and v6)
            foreach (QJsonValue dns, dnsArray) {
                if((!dns.toObject()["Address"].toArray().isEmpty())){
                    if (dns.toObject()["Family"].toInt() == eWiFiFormatType::FormatType_IPV4){
                        QJsonArray DNSv4 = dns.toObject()["Address"].toArray();
                        m_sDNSv4 = convertQJsonArrayToQStringFormat(DNSv4, eWiFiFormatType::FormatType_IPV4);
                        qInfo() << "ethernet info" << QString("DNSv4= %1").arg(m_sDNSv4);
                    } else if (dns.toObject()["Family"].toInt() == eWiFiFormatType::FormatType_IPV6){
                        QJsonArray DNSv6 = dns.toObject()["Address"].toArray();
                        m_sDNSv6 = convertQJsonArrayToQStringFormat(DNSv6, eWiFiFormatType::FormatType_IPV6);
                        qInfo() << "ethernet info" << QString("DNSv6= %1").arg(m_sDNSv6);
                    }
                }
            }
        } else {
        qInfo() << "Condition 2 not met";
    }
    } else {
        qInfo() << "Condition 1 not met";
    }
    return QJsonDocument();
}

QString ethernetmanager::convertQJsonArrayToQStringFormat(const QJsonArray &array, int formatType)
{
    // qInfo() << "Converting QJsonArray to QString with formatType:" << formatType;

    QString ipParts = QString("");

    int index = 0;
    int formatWidth = (formatType == eWiFiFormatType::FormatType_IPV6) ? 2 : 1;

    for (const QJsonValue &value : array) {
        if (value.isDouble()) {
            int number = value.toInt();

            if (formatType == eWiFiFormatType::FormatType_IPV6 || formatType == eWiFiFormatType::FormatType_MAC_ADDRESS) {
                if (index % formatWidth == 0 && index > 0 && index < array.count()) {
                    ipParts.append(":");
                }
                ipParts.append(QString("%1").arg(number, 2, 16, QLatin1Char('0')));

            } else if (formatType == eWiFiFormatType::FormatType_IPV4) {
                if (index % formatWidth == 0 && index > 0 && index < array.count()) {
                    ipParts.append(".");
                }
                ipParts.append(QString::number(number));

            } else {
                qInfo() << "Invalid formatType: " << formatType;
            }

        } else {
            qInfo() << "The QJsonArray contains non-integer elements.";
            return QString();
        }

        index++;
    }

    return ipParts;
}

QString ethernetmanager::prefixToSubnetMask(int prefixLength) {

    if (prefixLength < 0 || prefixLength > 32) {
        return QString(); // Invalid prefix
    }
    uint32_t mask;
    if (prefixLength == 0) {
        mask = 0;
    } else {
        mask = (0xFFFFFFFF << (32 - prefixLength)) & 0xFFFFFFFF;
    }

    // Split into 4 octets
    int octet1 = (mask >> 24) & 0xFF;
    int octet2 = (mask >> 16) & 0xFF;
    int octet3 = (mask >> 8) & 0xFF;
    int octet4 = mask & 0xFF;

    return QString::number(octet1) + "." + QString::number(octet2) + "." 
         + QString::number(octet3) + "." + QString::number(octet4);
}

void ethernetmanager::SetEth0StaticConfig(QString add,QString gateway ,int prefix){
    QFile file;
    QStringList str;
    QTextStream text(&file);
    QDir::setCurrent("/etc/systemd/network");
    file.setFileName("20-wired.network");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return ;
    // Step1 :reading file containt
    while (!text.atEnd()) {
        QString line = text.readLine();
        qInfo() << "############" << line;
        if(!line.contains("DHCP"))
        //Step 2:update string with the all containt in text except DHCP key
            str << (line + "\n");
    }
    //Step3:add your static configurations to string
    //1-address with prefixlength
    QStringList filteredList;
    for (const QString& line : str) {
        QString trimmedLine = line.trimmed();
        // Skip lines starting with "address=" or "gateway="
        bool isAddress = trimmedLine.startsWith("Address=");
        bool isGateway = trimmedLine.startsWith("Gateway=");
        if (!isAddress && !isGateway) {
            filteredList.append(line);  // Keep the line if it's not address/gateway
        }
    }
    str = filteredList;
    
    QString Address = "Address=" + add + "/" + QString::number(prefix) +"\n";
    qInfo() << "address" << Address;
    str << Address;
    //2-gateway
    QString Gateway = "Gateway=" + gateway + "\n";
    qInfo() << "Gateway" << Gateway;
    str << Gateway;
    //Step4:update text with string
    qInfo() << "The Whole String Containt is: " << str;
    file.resize(0);
    text << str.join("");
    file.close();
    //Step5:restart systemd-networkd systemctl restart systemd-networkd
    ExucProcess("systemctl",QStringList() << "restart" << "systemd-networkd");
    ExucProcess("networkctl",QStringList() << "reconfigure" << "eth0");
}

QString ethernetmanager::ExucProcess(QString CMD,QStringList list){
    QProcess prog;
    qInfo() << CMD << list;
    prog.start(CMD,list);
    prog.waitForFinished();
    qInfo() <<"output: " <<  QString::fromUtf8(prog.readAllStandardOutput());
    qInfo() <<"error: " << QString::fromUtf8(prog.readAllStandardError());

    return QString();
}

void ethernetmanager::enableDHCP(){
    QFile file;
    QStringList str;
    QTextStream text(&file);
    QDir::setCurrent("/etc/systemd/network");
    file.setFileName("20-wired.network");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return ;
    str << "[Match]" <<"\n" << "Name=eth0" << "\n" << "\n" << "[Network]" << "\n" << "DHCP=yes" <<"\n";
    file.resize(0);
    text << str.join("");
    file.close();
    // Step5:restart systemd-networkd
    ExucProcess("systemctl",QStringList() << "restart" << "systemd-networkd");
} 
