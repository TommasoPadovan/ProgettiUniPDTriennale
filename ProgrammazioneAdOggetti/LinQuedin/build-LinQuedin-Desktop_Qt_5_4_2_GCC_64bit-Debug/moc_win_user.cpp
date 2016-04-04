/****************************************************************************
** Meta object code from reading C++ file 'win_user.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/win_user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win_user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_win_user_t {
    QByteArrayData data[11];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_win_user_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_win_user_t qt_meta_stringdata_win_user = {
    {
QT_MOC_LITERAL(0, 0, 8), // "win_user"
QT_MOC_LITERAL(1, 9, 9), // "close_win"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 14), // "change_profile"
QT_MOC_LITERAL(4, 35, 12), // "rem_contatto"
QT_MOC_LITERAL(5, 48, 11), // "view_friend"
QT_MOC_LITERAL(6, 60, 13), // "find_username"
QT_MOC_LITERAL(7, 74, 9), // "find_name"
QT_MOC_LITERAL(8, 84, 12), // "find_surname"
QT_MOC_LITERAL(9, 97, 12), // "add_contatto"
QT_MOC_LITERAL(10, 110, 12) // "view_foreign"

    },
    "win_user\0close_win\0\0change_profile\0"
    "rem_contatto\0view_friend\0find_username\0"
    "find_name\0find_surname\0add_contatto\0"
    "view_foreign"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_win_user[] = {

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
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

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

       0        // eod
};

void win_user::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        win_user *_t = static_cast<win_user *>(_o);
        switch (_id) {
        case 0: _t->close_win(); break;
        case 1: _t->change_profile(); break;
        case 2: _t->rem_contatto(); break;
        case 3: _t->view_friend(); break;
        case 4: _t->find_username(); break;
        case 5: _t->find_name(); break;
        case 6: _t->find_surname(); break;
        case 7: _t->add_contatto(); break;
        case 8: _t->view_foreign(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject win_user::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_win_user.data,
      qt_meta_data_win_user,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *win_user::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *win_user::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_win_user.stringdata))
        return static_cast<void*>(const_cast< win_user*>(this));
    return QWidget::qt_metacast(_clname);
}

int win_user::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
