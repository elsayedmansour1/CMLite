/****************************************************************************
** Meta object code from reading C++ file 'EthernetManagerAdaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../source/dbus/EthernetManagerAdaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EthernetManagerAdaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EthernetmanagerAdaptor_t {
    QByteArrayData data[18];
    char stringdata0[1443];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EthernetmanagerAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EthernetmanagerAdaptor_t qt_meta_stringdata_EthernetmanagerAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 22), // "EthernetmanagerAdaptor"
QT_MOC_LITERAL(1, 23, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 39, 18), // "cm.Ethernetmanager"
QT_MOC_LITERAL(3, 58, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 78, 1151), // "  <interface name=\"cm.Ethern..."
QT_MOC_LITERAL(5, 1121, 19), // "SetEth0StaticConfig"
QT_MOC_LITERAL(6, 1141, 0), // ""
QT_MOC_LITERAL(7, 1142, 3), // "add"
QT_MOC_LITERAL(8, 1146, 7), // "gateway"
QT_MOC_LITERAL(9, 1154, 6), // "prefix"
QT_MOC_LITERAL(10, 1161, 10), // "enableDHCP"
QT_MOC_LITERAL(11, 1172, 21), // "getIPv4DNSforEthernet"
QT_MOC_LITERAL(12, 1194, 25), // "getIPv4GatewayforEthernet"
QT_MOC_LITERAL(13, 1220, 24), // "getIPv4SubnetforEthernet"
QT_MOC_LITERAL(14, 1245, 18), // "getIPv4forEthernet"
QT_MOC_LITERAL(15, 1264, 25), // "getIPv6GatewayforEthernet"
QT_MOC_LITERAL(16, 1290, 24), // "getIPv6SubnetforEthernet"
QT_MOC_LITERAL(17, 1315, 18) // "getIPv6forEthernet"

    },
    "EthernetmanagerAdaptor\0D-Bus Interface\0"
    "cm.Ethernetmanager\0D-Bus Introspection\0"
    "  <interface name=\"cm.Ethernetmanager\">\n    <method name=\"getIPv4f"
    "orEthernet\">\n      <arg direction=\"out\" type=\"s\" name=\"path\"/>"
    "\n    </method>\n    <method name=\"getIPv4GatewayforEthernet\">\n    "
    "  <arg direction=\"out\" type=\"s\" name=\"path\"/>\n    </method>\n  "
    "  <method name=\"getIPv4SubnetforEthernet\">\n      <arg direction=\"o"
    "ut\" type=\"s\" name=\"path\"/>\n    </method>\n    <method name=\"get"
    "IPv4DNSforEthernet\">\n      <arg direction=\"out\" type=\"s\" name=\""
    "path\"/>\n    </method>\n    <method name=\"getIPv6forEthernet\">\n   "
    "   <arg direction=\"out\" type=\"s\" name=\"path\"/>\n    </method>\n "
    "   <method name=\"getIPv6GatewayforEthernet\">\n      <arg direction=\""
    "out\" type=\"s\" name=\"path\"/>\n    </method>\n    <method name=\"ge"
    "tIPv6SubnetforEthernet\">\n      <arg direction=\"out\" type=\"s\" nam"
    "e=\"path\"/>\n    </method>\n    <method name=\"SetEth0StaticConfig\">"
    "\n      <arg direction=\"in\" type=\"s\" name=\"add\"/>\n      <arg di"
    "rection=\"in\" type=\"s\" name=\"gateway\"/>\n      <arg direction=\"i"
    "n\" type=\"i\" name=\"prefix\"/>\n    </method>\n    <method name=\"en"
    "ableDHCP\"/>\n  </interface>\n\0"
    "SetEth0StaticConfig\0\0add\0gateway\0"
    "prefix\0enableDHCP\0getIPv4DNSforEthernet\0"
    "getIPv4GatewayforEthernet\0"
    "getIPv4SubnetforEthernet\0getIPv4forEthernet\0"
    "getIPv6GatewayforEthernet\0"
    "getIPv6SubnetforEthernet\0getIPv6forEthernet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EthernetmanagerAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       9,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // slots: name, argc, parameters, tag, flags
       5,    3,   63,    6, 0x0a /* Public */,
      10,    0,   70,    6, 0x0a /* Public */,
      11,    0,   71,    6, 0x0a /* Public */,
      12,    0,   72,    6, 0x0a /* Public */,
      13,    0,   73,    6, 0x0a /* Public */,
      14,    0,   74,    6, 0x0a /* Public */,
      15,    0,   75,    6, 0x0a /* Public */,
      16,    0,   76,    6, 0x0a /* Public */,
      17,    0,   77,    6, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    7,    8,    9,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,

       0        // eod
};

void EthernetmanagerAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EthernetmanagerAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetEth0StaticConfig((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->enableDHCP(); break;
        case 2: { QString _r = _t->getIPv4DNSforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->getIPv4GatewayforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getIPv4SubnetforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getIPv4forEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getIPv6GatewayforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getIPv6SubnetforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->getIPv6forEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EthernetmanagerAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_EthernetmanagerAdaptor.data,
    qt_meta_data_EthernetmanagerAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EthernetmanagerAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EthernetmanagerAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EthernetmanagerAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int EthernetmanagerAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
