#ifndef DBUSNETWORKMANAGER_HPP
#define DBUSNETWORKMANAGER_HPP

#include "../networkmanager/networkmanager.hpp"
#include <QObject>

class dbusnetworkmanager :public QObject
{
    Q_OBJECT
private:
    /* data */
    networkmanager* mNetworkmanager;
public:
    explicit dbusnetworkmanager(networkmanager *parent);
    ~dbusnetworkmanager();
public Q_SLOTS: // METHODS
    QString getIPv4GatewayforEthernet();
    QString getIPv4SubnetforEthernet();
    QString getIPv4forEthernet();
    QString getIPv4DNSforEthernet();
    QString getIPv6GatewayforEthernet();
    int getIPv6PrefixLengthforEthernet();
    QString getIPv6forEthernet();
    void SetEth0StaticConfig(const QString &add, const QString &gateway, int prefix);
    void enableDHCP();
    QString getIPv6DNSforEthernet();

};


#endif