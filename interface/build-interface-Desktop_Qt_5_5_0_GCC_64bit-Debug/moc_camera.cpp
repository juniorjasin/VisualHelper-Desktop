/****************************************************************************
** Meta object code from reading C++ file 'camera.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/processor/camera.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Camera_t {
    QByteArrayData data[12];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Camera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Camera_t qt_meta_stringdata_Camera = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Camera"
QT_MOC_LITERAL(1, 7, 16), // "positionDetected"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "index"
QT_MOC_LITERAL(4, 31, 17), // "selectionDetected"
QT_MOC_LITERAL(5, 49, 21), // "signal_newCameraFrame"
QT_MOC_LITERAL(6, 71, 8), // "cv::Mat*"
QT_MOC_LITERAL(7, 80, 13), // "cameraTexture"
QT_MOC_LITERAL(8, 94, 22), // "signal_nonFaceDetected"
QT_MOC_LITERAL(9, 117, 29), // "signal_nonFaceDetectedForBack"
QT_MOC_LITERAL(10, 147, 7), // "process"
QT_MOC_LITERAL(11, 155, 9) // "calibrate"

    },
    "Camera\0positionDetected\0\0index\0"
    "selectionDetected\0signal_newCameraFrame\0"
    "cv::Mat*\0cameraTexture\0signal_nonFaceDetected\0"
    "signal_nonFaceDetectedForBack\0process\0"
    "calibrate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Camera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,
       8,    0,   58,    2, 0x06 /* Public */,
       9,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   60,    2, 0x08 /* Private */,
      11,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Camera *_t = static_cast<Camera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionDetected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->selectionDetected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signal_newCameraFrame((*reinterpret_cast< cv::Mat*(*)>(_a[1]))); break;
        case 3: _t->signal_nonFaceDetected(); break;
        case 4: _t->signal_nonFaceDetectedForBack(); break;
        case 5: _t->process(); break;
        case 6: _t->calibrate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Camera::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::positionDetected)) {
                *result = 0;
            }
        }
        {
            typedef void (Camera::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::selectionDetected)) {
                *result = 1;
            }
        }
        {
            typedef void (Camera::*_t)(cv::Mat * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::signal_newCameraFrame)) {
                *result = 2;
            }
        }
        {
            typedef void (Camera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::signal_nonFaceDetected)) {
                *result = 3;
            }
        }
        {
            typedef void (Camera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::signal_nonFaceDetectedForBack)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Camera::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Camera.data,
      qt_meta_data_Camera,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Camera.stringdata0))
        return static_cast<void*>(const_cast< Camera*>(this));
    return QObject::qt_metacast(_clname);
}

int Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Camera::positionDetected(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Camera::selectionDetected(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Camera::signal_newCameraFrame(cv::Mat * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Camera::signal_nonFaceDetected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Camera::signal_nonFaceDetectedForBack()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
