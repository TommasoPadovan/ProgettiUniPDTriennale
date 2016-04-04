/****************************************************************************
** Meta object code from reading C++ file 'win_admin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/win_admin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win_admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_win_admin_t {
    QByteArrayData data[12];
    char stringdata[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_win_admin_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_win_admin_t qt_meta_stringdata_win_admin = {
    {
QT_MOC_LITERAL(0, 0, 9), // "win_admin"
QT_MOC_LITERAL(1, 10, 9), // "close_win"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "add"
QT_MOC_LITERAL(4, 25, 18), // "show_from_allusers"
QT_MOC_LITERAL(5, 44, 17), // "del_from_allusers"
QT_MOC_LITERAL(6, 62, 16), // "ch_from_allusers"
QT_MOC_LITERAL(7, 79, 20), // "modify_type_allusers"
QT_MOC_LITERAL(8, 100, 13), // "find_username"
QT_MOC_LITERAL(9, 114, 9), // "find_name"
QT_MOC_LITERAL(10, 124, 12), // "find_surname"
QT_MOC_LITERAL(11, 137, 17) // "send_to_main_list"

    },
    "win_admin\0close_win\0\0add\0show_from_allusers\0"
    "del_from_allusers\0ch_from_allusers\0"
    "modify_type_allusers\0find_username\0"
    "find_name\0find_surname\0send_to_main_list"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_win_admin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void win_admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        win_admin *_t = static_cast<win_admin *>(_o);
        switch (_id) {
        case 0: _t->close_win(); break;
        case 1: _t->add(); break;
        case 2: _t->show_from_allusers(); break;
        case 3: _t->del_from_allusers(); break;
        case 4: _t->ch_from_allusers(); break;
        case 5: _t->modify_type_allusers(); break;
        case 6: _t->find_username(); break;
        case 7: _t->find_name(); break;
        case 8: _t->find_surname(); break;
        case 9: _t->send_to_main_list(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject win_admin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_win_admin.data,
      qt_meta_data_win_admin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *win_admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *win_admin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_win_admin.stringdata))
        return static_cast<void*>(const_cast< win_admin*>(this));
    return QWidget::qt_metacast(_clname);
}

int win_admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
