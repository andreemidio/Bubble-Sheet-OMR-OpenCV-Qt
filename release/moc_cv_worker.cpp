/****************************************************************************
** Meta object code from reading C++ file 'cv_worker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cv_worker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cv_worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cv_worker_t {
    QByteArrayData data[11];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cv_worker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cv_worker_t qt_meta_stringdata_cv_worker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "cv_worker"
QT_MOC_LITERAL(1, 10, 8), // "finished"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "error"
QT_MOC_LITERAL(4, 26, 6), // "errStr"
QT_MOC_LITERAL(5, 33, 7), // "sendImg"
QT_MOC_LITERAL(6, 41, 3), // "img"
QT_MOC_LITERAL(7, 45, 13), // "transportImgs"
QT_MOC_LITERAL(8, 59, 19), // "std::vector<QImage>"
QT_MOC_LITERAL(9, 79, 4), // "imgs"
QT_MOC_LITERAL(10, 84, 7) // "process"

    },
    "cv_worker\0finished\0\0error\0errStr\0"
    "sendImg\0img\0transportImgs\0std::vector<QImage>\0"
    "imgs\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cv_worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,
       5,    1,   43,    2, 0x06 /* Public */,
       7,    1,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void cv_worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cv_worker *_t = static_cast<cv_worker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->transportImgs((*reinterpret_cast< std::vector<QImage>(*)>(_a[1]))); break;
        case 4: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cv_worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cv_worker::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (cv_worker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cv_worker::error)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (cv_worker::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cv_worker::sendImg)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (cv_worker::*)(std::vector<QImage> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cv_worker::transportImgs)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cv_worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cv_worker.data,
      qt_meta_data_cv_worker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cv_worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cv_worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cv_worker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cv_worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void cv_worker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void cv_worker::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void cv_worker::sendImg(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void cv_worker::transportImgs(std::vector<QImage> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
