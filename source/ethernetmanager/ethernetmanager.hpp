#ifndef ETHERNETMANAGER_HPP
#define ETHERNETMANAGER_HPP

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "../WrapperLib/QDBus/iQDBusInterface.hpp"
#include <QObject>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QProcess>
#include <QDBusReply>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QTimer>
#include <QTextStream>
#include <QDir>
enum eWiFiFormatType{
    FormatType_IPV4 = 2,
    FormatType_IPV6 = 10,
    FormatType_MAC_ADDRESS
};
class ethernetmanager: public QObject{
    Q_OBJECT
public:
    explicit ethernetmanager(QObject* parent = nullptr);
    ~ethernetmanager();

    QString getIPv4forEthernet();
    QString getIPv4SubnetforEthernet();
    QString getIPv4GatewayforEthernet();
    QString getIPv4DNSforEthernet();
    QString getIPv6GatewayforEthernet();
    QString getIPv6forEthernet();
    int     getIPv6PrefixLengthforEthernet();
    QString getIPv6DNSforEthernet();
    void enableDHCP();
    void SetEth0StaticConfig(QString add,QString gateway ,int prefix);
signals:

protected:
    explicit ethernetmanager(QDBusInterfaceWrapperInterface* dbusInterface);

private slots: // <-- Slots section
    void init(); // <-- Ensure this matches the implementation
    void onPropertiesChanged(QString interfaceName, QVariantMap changedProps, QStringList invalidatedProps);
private:
    QString getCurrectInterfaceLinkForEth();
    QString getAllInfoForEth();
    QJsonDocument parseNetworkInfo(QString reply);
    QString convertQJsonArrayToQStringFormat(const QJsonArray &array, int formatType);
    QString ExucProcess(QString CMD,QStringList list);
    QString prefixToSubnetMask(int prefixLength);




    QString mPathEth0;
    QString m_sMaCAddress;
    QString m_sDNSv4;
    QString m_sIPv4;
    QString m_sSubnetMaskIPv4;
    QString m_sIPv4Gateway;
    QString m_sIPv6;
    int m_iPrefixLengthIPv6;
    QString m_sIPv6Gateway;
    QString m_sDNSv6;
    QDBusInterfaceWrapperInterface* m_pDbusInterface = nullptr;

};

#endif // ETHERNETMANAGER_HPP