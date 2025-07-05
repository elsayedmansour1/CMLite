#include "networkmanager.hpp"
#include "../dbus/EthernetManagerAdaptor.h"


networkmanager::networkmanager(QObject *parent)
    :QObject(parent)
    ,mdbusnetworkmanager(new dbusnetworkmanager(this))
{
    qInfo () << "i'm the network manager welcome elsayed (:";
    // 1. Create adaptor
    
    new EthernetmanagerAdaptor(mdbusnetworkmanager);
    
    // 2. Get D-Bus connection
    QString customBusAddress = "unix:path=/tmp/custom-bus.socket";
    QDBusConnection connection = QDBusConnection::connectToBus(customBusAddress, "CUSTOM_BUS");
    // QDBusConnection connection = QDBusConnection::sessionBus();
    if (!connection.isConnected()) {
        qWarning() << "Failed to connect to session bus:" << connection.lastError().message();
        return;
    }
    // 3. Register service
    if (!connection.registerService("com.cmlite")) {
        qInfo() << "Service registration failed:" << connection.lastError();
    }

    // 4. Register object
    if (!connection.registerObject("/com/cmlite/Ethernet", mdbusnetworkmanager)) {
        qInfo() << "Object registration failed:" << connection.lastError();
    }

}

networkmanager::~networkmanager() = default;

ethernetmanager& networkmanager::accessToEthernet(){
    return mEthernetManager;
}
