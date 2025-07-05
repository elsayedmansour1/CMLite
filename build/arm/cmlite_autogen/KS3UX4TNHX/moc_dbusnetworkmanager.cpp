/****************************************************************************
** Meta object code from reading C++ file 'dbusnetworkmanager.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../source/dbus/dbusnetworkmanager.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbusnetworkmanager.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dbusnetworkmanager_t {
    QByteArrayData data[14];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dbusnetworkmanager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dbusnetworkmanager_t qt_meta_stringdata_dbusnetworkmanager = {
    {
QT_MOC_LITERAL(0, 0, 18), // "dbusnetworkmanager"
QT_MOC_LITERAL(1, 19, 25), // "getIPv4GatewayforEthernet"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 24), // "getIPv4SubnetforEthernet"
QT_MOC_LITERAL(4, 71, 18), // "getIPv4forEthernet"
QT_MOC_LITERAL(5, 90, 21), // "getIPv4DNSforEthernet"
QT_MOC_LITERAL(6, 112, 25), // "getIPv6GatewayforEthernet"
QT_MOC_LITERAL(7, 138, 24), // "getIPv6SubnetforEthernet"
QT_MOC_LITERAL(8, 163, 18), // "getIPv6forEthernet"
QT_MOC_LITERAL(9, 182, 19), // "SetEth0StaticConfig"
QT_MOC_LITERAL(10, 202, 3), // "add"
QT_MOC_LITERAL(11, 206, 7), // "gateway"
QT_MOC_LITERAL(12, 214, 6), // "prefix"
QT_MOC_LITERAL(13, 221, 10) // "enableDHCP"

    },
    "dbusnetworkmanager\0getIPv4GatewayforEthernet\0"
    "\0getIPv4SubnetforEthernet\0getIPv4forEthernet\0"
    "getIPv4DNSforEthernet\0getIPv6GatewayforEthernet\0"
    "getIPv6SubnetforEthernet\0getIPv6forEthernet\0"
    "SetEth0StaticConfig\0add\0gateway\0prefix\0"
    "enableDHCP"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dbusnetworkmanager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    3,   66,    2, 0x0a /* Public */,
      13,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   10,   11,   12,
    QMetaType::Void,

       0        // eod
};

void dbusnetworkmanager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dbusnetworkmanager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->getIPv4GatewayforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->getIPv4SubnetforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->getIPv4forEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->getIPv4DNSforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getIPv6GatewayforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getIPv6SubnetforEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getIPv6forEthernet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->SetEth0StaticConfig((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->enableDHCP(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dbusnetworkmanager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_dbusnetworkmanager.data,
    qt_meta_data_dbusnetworkmanager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dbusnetworkmanager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dbusnetworkmanager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dbusnetworkmanager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int dbusnetworkmanager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
