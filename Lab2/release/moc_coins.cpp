/****************************************************************************
** Meta object code from reading C++ file 'coins.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../coins.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coins.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Coins_t {
    QByteArrayData data[9];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Coins_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Coins_t qt_meta_stringdata_Coins = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Coins"
QT_MOC_LITERAL(1, 6, 22), // "on_ModelButton_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "on_Coin1_valueChanged"
QT_MOC_LITERAL(4, 52, 4), // "arg1"
QT_MOC_LITERAL(5, 57, 21), // "on_Coin2_valueChanged"
QT_MOC_LITERAL(6, 79, 25), // "on_coinPrevButton_clicked"
QT_MOC_LITERAL(7, 105, 7), // "hideGif"
QT_MOC_LITERAL(8, 113, 27) // "on_statisticsButton_clicked"

    },
    "Coins\0on_ModelButton_clicked\0\0"
    "on_Coin1_valueChanged\0arg1\0"
    "on_Coin2_valueChanged\0on_coinPrevButton_clicked\0"
    "hideGif\0on_statisticsButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Coins[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    1,   45,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Coins::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Coins *_t = static_cast<Coins *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ModelButton_clicked(); break;
        case 1: _t->on_Coin1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_Coin2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_coinPrevButton_clicked(); break;
        case 4: _t->hideGif(); break;
        case 5: _t->on_statisticsButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Coins::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Coins.data,
      qt_meta_data_Coins,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Coins::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Coins::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Coins.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Coins::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
