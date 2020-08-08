/****************************************************************************
** Meta object code from reading C++ file 'viewconsultarpessoa.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/view/viewconsultarpessoa.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewconsultarpessoa.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewConsultarPessoa_t {
    QByteArrayData data[6];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewConsultarPessoa_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewConsultarPessoa_t qt_meta_stringdata_ViewConsultarPessoa = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ViewConsultarPessoa"
QT_MOC_LITERAL(1, 20, 6), // "manter"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "Model*"
QT_MOC_LITERAL(4, 35, 1), // "m"
QT_MOC_LITERAL(5, 37, 17) // "on_pbNovo_clicked"

    },
    "ViewConsultarPessoa\0manter\0\0Model*\0m\0"
    "on_pbNovo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewConsultarPessoa[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ViewConsultarPessoa::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewConsultarPessoa *_t = static_cast<ViewConsultarPessoa *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->manter((*reinterpret_cast< Model*(*)>(_a[1]))); break;
        case 1: _t->on_pbNovo_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Model* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViewConsultarPessoa::*_t)(Model * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewConsultarPessoa::manter)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ViewConsultarPessoa::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ViewConsultarPessoa.data,
      qt_meta_data_ViewConsultarPessoa,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ViewConsultarPessoa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewConsultarPessoa::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ViewConsultarPessoa.stringdata0))
        return static_cast<void*>(const_cast< ViewConsultarPessoa*>(this));
    return QWidget::qt_metacast(_clname);
}

int ViewConsultarPessoa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ViewConsultarPessoa::manter(Model * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
