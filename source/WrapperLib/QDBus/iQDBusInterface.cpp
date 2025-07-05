
#include "iQDBusInterface.hpp"

// Constructor: Initialize with QDBusInterface (not QDBusInterface_!)
iQDBusInterface::iQDBusInterface(
    const QString& service,
    const QString& path,
    const QString& interface,
    const QDBusConnection& connection,
    QObject* parent
) : m_interface(new QDBusInterface(service, path, interface, connection, parent)) {}  // Fixed: QDBusInterface

// Correct method definition with class scope
QDBusReply<QString> iQDBusInterface::call(const QString& method) {
    return m_interface->call(method);
}

bool iQDBusInterface::isValid(){
    return m_interface->isValid();
}
// Destructor: Clean up the raw pointer
iQDBusInterface::~iQDBusInterface() {
    delete m_interface;
}