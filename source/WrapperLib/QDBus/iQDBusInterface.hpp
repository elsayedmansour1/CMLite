#include <QDBusInterface>
#include <QDBusMessage>
#include <QObject>
#include <QDBusReply>
#include "../../wrapperLibInterface/QDBusInterfaceWrapperInterface.hpp"

class iQDBusInterface : public QDBusInterfaceWrapperInterface{
private:
    QDBusInterface* m_interface;

public:
    iQDBusInterface(
        const QString& service,
        const QString& path,
        const QString& interface = QString(),
        const QDBusConnection& connection = QDBusConnection::sessionBus(),
        QObject* parent = nullptr
    );

    ~iQDBusInterface();
    QDBusReply<QString> call(const QString& method) override;
    bool isValid() override;

};
