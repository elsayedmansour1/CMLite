#ifndef QDBUSINTERFACEWRAPPERINTERFACE
#define QDBUSINTERFACEWRAPPERINTERFACE
#include <QDBusReply>

class QDBusInterfaceWrapperInterface
{
private:
    /* data */
public:
    QDBusInterfaceWrapperInterface(/* args */){};
    virtual ~QDBusInterfaceWrapperInterface(){};
    virtual QDBusReply<QString> call(const QString& method) = 0 ;  // Removed `override`
    virtual bool isValid() = 0;
};

#endif