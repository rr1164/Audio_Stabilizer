/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../backend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackEnd_t {
    const uint offsetsAndSize[40];
    char stringdata0[330];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_BackEnd_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_BackEnd_t qt_meta_stringdata_BackEnd = {
    {
QT_MOC_LITERAL(0, 7), // "BackEnd"
QT_MOC_LITERAL(8, 12), // "valueChanged"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 11), // "after_value"
QT_MOC_LITERAL(34, 24), // "set_division_coefficient"
QT_MOC_LITERAL(59, 20), // "division_Coefficient"
QT_MOC_LITERAL(80, 24), // "get_division_coefficient"
QT_MOC_LITERAL(105, 23), // "get_before_slider_value"
QT_MOC_LITERAL(129, 15), // "set_delay_value"
QT_MOC_LITERAL(145, 11), // "delay_Value"
QT_MOC_LITERAL(157, 23), // "set_before_slider_value"
QT_MOC_LITERAL(181, 12), // "slider_value"
QT_MOC_LITERAL(194, 15), // "get_delay_value"
QT_MOC_LITERAL(210, 19), // "set_increased_value"
QT_MOC_LITERAL(230, 12), // "increase_low"
QT_MOC_LITERAL(243, 19), // "get_increased_value"
QT_MOC_LITERAL(263, 18), // "set_decrease_value"
QT_MOC_LITERAL(282, 13), // "decrease_high"
QT_MOC_LITERAL(296, 19), // "get_decreased_value"
QT_MOC_LITERAL(316, 13) // "getaftervalue"

    },
    "BackEnd\0valueChanged\0\0after_value\0"
    "set_division_coefficient\0division_Coefficient\0"
    "get_division_coefficient\0"
    "get_before_slider_value\0set_delay_value\0"
    "delay_Value\0set_before_slider_value\0"
    "slider_value\0get_delay_value\0"
    "set_increased_value\0increase_low\0"
    "get_increased_value\0set_decrease_value\0"
    "decrease_high\0get_decreased_value\0"
    "getaftervalue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackEnd[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   89,    2, 0x0a,    3 /* Public */,
       6,    0,   92,    2, 0x0a,    5 /* Public */,
       7,    0,   93,    2, 0x0a,    6 /* Public */,
       8,    1,   94,    2, 0x0a,    7 /* Public */,
      10,    1,   97,    2, 0x0a,    9 /* Public */,
      12,    0,  100,    2, 0x0a,   11 /* Public */,
      13,    1,  101,    2, 0x0a,   12 /* Public */,
      15,    0,  104,    2, 0x0a,   14 /* Public */,
      16,    1,  105,    2, 0x0a,   15 /* Public */,
      18,    0,  108,    2, 0x0a,   17 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      19,    0,  109,    2, 0x02,   18 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Float,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Bool,

 // methods: parameters
    QMetaType::Int,

       0        // eod
};

void BackEnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BackEnd *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->set_division_coefficient((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: { float _r = _t->get_division_coefficient();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->get_before_slider_value();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->set_delay_value((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->set_before_slider_value((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: { int _r = _t->get_delay_value();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->set_increased_value((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: { bool _r = _t->get_increased_value();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->set_decrease_value((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: { bool _r = _t->get_decreased_value();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->getaftervalue();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BackEnd::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BackEnd::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BackEnd.offsetsAndSize,
    qt_meta_data_BackEnd,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_BackEnd_t
, QtPrivate::TypeAndForceComplete<BackEnd, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<int, std::false_type>

>,
    nullptr
} };


const QMetaObject *BackEnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackEnd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackEnd.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BackEnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void BackEnd::valueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
