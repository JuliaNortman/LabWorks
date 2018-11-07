/****************************************************************************
** Meta object code from reading C++ file 'dice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dice_t {
    QByteArrayData data[12];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dice_t qt_meta_stringdata_Dice = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Dice"
QT_MOC_LITERAL(1, 5, 21), // "on_side1_valueChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "arg1"
QT_MOC_LITERAL(4, 33, 21), // "on_side2_valueChanged"
QT_MOC_LITERAL(5, 55, 21), // "on_side3_valueChanged"
QT_MOC_LITERAL(6, 77, 21), // "on_side5_valueChanged"
QT_MOC_LITERAL(7, 99, 21), // "on_side4_valueChanged"
QT_MOC_LITERAL(8, 121, 21), // "on_side6_valueChanged"
QT_MOC_LITERAL(9, 143, 26), // "on_diceModelButton_clicked"
QT_MOC_LITERAL(10, 170, 7), // "hideGif"
QT_MOC_LITERAL(11, 178, 27) // "on_statisticsButton_clicked"

    },
    "Dice\0on_side1_valueChanged\0\0arg1\0"
    "on_side2_valueChanged\0on_side3_valueChanged\0"
    "on_side5_valueChanged\0on_side4_valueChanged\0"
    "on_side6_valueChanged\0on_diceModelButton_clicked\0"
    "hideGif\0on_statisticsButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       5,    1,   65,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,
       8,    1,   74,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dice *_t = static_cast<Dice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_side1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_side2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_side3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_side5_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_side4_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_side6_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_diceModelButton_clicked(); break;
        case 7: _t->hideGif(); break;
        case 8: _t->on_statisticsButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dice::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dice.data,
      qt_meta_data_Dice,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Dice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dice.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
