/****************************************************************************
** Meta object code from reading C++ file 'setzhuanquanform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Robot_Find_Leakage/setzhuanquanform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setzhuanquanform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetZhuanQuanForm_t {
    QByteArrayData data[10];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetZhuanQuanForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetZhuanQuanForm_t qt_meta_stringdata_SetZhuanQuanForm = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SetZhuanQuanForm"
QT_MOC_LITERAL(1, 17, 11), // "setLineEdit"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "sandToSetCar"
QT_MOC_LITERAL(4, 43, 16), // "receiveParameter"
QT_MOC_LITERAL(5, 60, 1), // "r"
QT_MOC_LITERAL(6, 62, 3), // "vJD"
QT_MOC_LITERAL(7, 66, 3), // "dir"
QT_MOC_LITERAL(8, 70, 2), // "sn"
QT_MOC_LITERAL(9, 73, 24) // "on_pushButton_ok_clicked"

    },
    "SetZhuanQuanForm\0setLineEdit\0\0"
    "sandToSetCar\0receiveParameter\0r\0vJD\0"
    "dir\0sn\0on_pushButton_ok_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetZhuanQuanForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,
       3,    4,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    4,   52,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int,    5,    6,    7,    8,
    QMetaType::Void,

       0        // eod
};

void SetZhuanQuanForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetZhuanQuanForm *_t = static_cast<SetZhuanQuanForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setLineEdit((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->sandToSetCar((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->receiveParameter((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->on_pushButton_ok_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SetZhuanQuanForm::*_t)(float , float , float , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetZhuanQuanForm::setLineEdit)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SetZhuanQuanForm::*_t)(float , float , float , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SetZhuanQuanForm::sandToSetCar)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SetZhuanQuanForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SetZhuanQuanForm.data,
      qt_meta_data_SetZhuanQuanForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SetZhuanQuanForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetZhuanQuanForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SetZhuanQuanForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SetZhuanQuanForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SetZhuanQuanForm::setLineEdit(float _t1, float _t2, float _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SetZhuanQuanForm::sandToSetCar(float _t1, float _t2, float _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
