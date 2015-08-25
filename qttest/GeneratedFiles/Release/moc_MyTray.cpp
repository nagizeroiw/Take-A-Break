/****************************************************************************
** Meta object code from reading C++ file 'MyTray.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyTray.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyTray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyTray_t {
    QByteArrayData data[12];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTray_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTray_t qt_meta_stringdata_MyTray = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MyTray"
QT_MOC_LITERAL(1, 7, 14), // "userOpenConfig"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "timeoutMessage"
QT_MOC_LITERAL(4, 38, 9), // "stopTimer"
QT_MOC_LITERAL(5, 48, 10), // "startTimer"
QT_MOC_LITERAL(6, 59, 11), // "reviveTimer"
QT_MOC_LITERAL(7, 71, 16), // "setBreaktimemsec"
QT_MOC_LITERAL(8, 88, 9), // "new_index"
QT_MOC_LITERAL(9, 98, 10), // "openConfig"
QT_MOC_LITERAL(10, 109, 18), // "revive_window_open"
QT_MOC_LITERAL(11, 128, 4) // "quit"

    },
    "MyTray\0userOpenConfig\0\0timeoutMessage\0"
    "stopTimer\0startTimer\0reviveTimer\0"
    "setBreaktimemsec\0new_index\0openConfig\0"
    "revive_window_open\0quit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTray[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    1,   64,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyTray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTray *_t = static_cast<MyTray *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userOpenConfig(); break;
        case 1: _t->timeoutMessage(); break;
        case 2: _t->stopTimer(); break;
        case 3: _t->startTimer(); break;
        case 4: _t->reviveTimer(); break;
        case 5: _t->setBreaktimemsec((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->openConfig(); break;
        case 7: _t->revive_window_open(); break;
        case 8: _t->quit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTray::userOpenConfig)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MyTray::staticMetaObject = {
    { &QSystemTrayIcon::staticMetaObject, qt_meta_stringdata_MyTray.data,
      qt_meta_data_MyTray,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyTray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTray::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyTray.stringdata0))
        return static_cast<void*>(const_cast< MyTray*>(this));
    return QSystemTrayIcon::qt_metacast(_clname);
}

int MyTray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSystemTrayIcon::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MyTray::userOpenConfig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
