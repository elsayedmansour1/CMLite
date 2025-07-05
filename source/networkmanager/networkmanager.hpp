#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include "QObject"
#include <QDBusInterface>
#include <QDBusReply>
#include <QDBusConnection>
#include <QDBusMessage>
#include "../wifimanager/wifimanager.hpp"
#include "../ltemanager/ltemanager.hpp"
#include "../hotspotmanager/hotspotmanager.hpp"
#include "../ethernetmanager/ethernetmanager.hpp"

class dbusnetworkmanager;
class networkmanager : public QObject
{
    Q_OBJECT
public:
    networkmanager(QObject *parent = nullptr);
    virtual ~networkmanager();
    ethernetmanager& accessToEthernet();
protected:

private:
    /* data */
    dbusnetworkmanager *mdbusnetworkmanager;
    ethernetmanager mEthernetManager;
    wifimanager mWifimanager;
};

#endif  // NETWORKMANAGER_HPP