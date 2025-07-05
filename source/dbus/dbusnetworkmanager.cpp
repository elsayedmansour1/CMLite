#include "dbusnetworkmanager.hpp"


dbusnetworkmanager::dbusnetworkmanager(networkmanager *parent)
    :QObject(parent)
    ,mNetworkmanager(parent)
{
}

dbusnetworkmanager::~dbusnetworkmanager() = default;

QString dbusnetworkmanager::getIPv4GatewayforEthernet()
{
    return mNetworkmanager->accessToEthernet().getIPv4GatewayforEthernet();
}

QString dbusnetworkmanager::getIPv4SubnetforEthernet()
{
    return mNetworkmanager->accessToEthernet().getIPv4SubnetforEthernet();
}

QString dbusnetworkmanager::getIPv4forEthernet()
{
    return mNetworkmanager->accessToEthernet().getIPv4forEthernet();
}

QString dbusnetworkmanager::getIPv4DNSforEthernet()
{
    return mNetworkmanager->accessToEthernet().getIPv4DNSforEthernet();
}

QString dbusnetworkmanager::getIPv6GatewayforEthernet()
{
    return mNetworkmanager->accessToEthernet().getIPv6GatewayforEthernet();
}

QString dbusnetworkmanager::getIPv6SubnetforEthernet()
{
    return mNetworkmanager->accessToEthernet().getIPv6SubnetforEthernet();
}

QString dbusnetworkmanager::getIPv6forEthernet()
{
    return mNetworkmanager->accessToEthernet().getIPv6forEthernet();
}

void dbusnetworkmanager::SetEth0StaticConfig(const QString &add, const QString &gateway, int prefix)
{
    return mNetworkmanager->accessToEthernet().SetEth0StaticConfig(add, gateway, prefix);
}

void dbusnetworkmanager::enableDHCP()
{
    mNetworkmanager->accessToEthernet().enableDHCP();
}