/****************************************************************************
** Meta object code from reading C++ file 'KeyService.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../keyboard/inc/KeyService.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KeyService.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KeyService_t {
    const uint offsetsAndSize[16];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_KeyService_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_KeyService_t qt_meta_stringdata_KeyService = {
    {
QT_MOC_LITERAL(0, 10), // "KeyService"
QT_MOC_LITERAL(11, 16), // "parseDataAndSend"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 8), // "uint8_t*"
QT_MOC_LITERAL(38, 5), // "rxBuf"
QT_MOC_LITERAL(44, 14), // "registerKeyMap"
QT_MOC_LITERAL(59, 11), // "KeyMapList*"
QT_MOC_LITERAL(71, 10) // "keyMapList"

    },
    "KeyService\0parseDataAndSend\0\0uint8_t*\0"
    "rxBuf\0registerKeyMap\0KeyMapList*\0"
    "keyMapList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyService[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x08,    1 /* Private */,
       5,    1,   29,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void KeyService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KeyService *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->parseDataAndSend((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1]))); break;
        case 1: _t->registerKeyMap((*reinterpret_cast< std::add_pointer_t<KeyMapList*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject KeyService::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_KeyService.offsetsAndSize,
    qt_meta_data_KeyService,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_KeyService_t
, QtPrivate::TypeAndForceComplete<KeyService, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<KeyMapList *, std::false_type>


>,
    nullptr
} };


const QMetaObject *KeyService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KeyService.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KeyService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
