/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.15.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // F:/Programming/C++/Sudoku/puzzleCollection.txt
  0x0,0x0,0x0,0x4b,
  0x0,
  0x0,0x3,0x5f,0x78,0x9c,0x33,0xd4,0x31,0xd2,0x31,0xd6,0x31,0xd1,0x31,0xd5,0x31,
  0xd3,0x31,0xd7,0xb1,0xd0,0xb1,0xe4,0xe5,0xb2,0x4,0x52,0xe6,0x40,0xae,0x29,0x50,
  0xd8,0x18,0x28,0x6d,0xc8,0xcb,0x65,0x48,0x94,0x2a,0x3,0x1d,0x34,0x88,0x55,0x15,
  0xd9,0xc6,0xf3,0x72,0x19,0xd,0x25,0xc7,0x1a,0xf,0x25,0xc7,0x9a,0xc,0x25,0xc7,
  0x9a,0xe,0x1d,0xc7,0x2,0x0,0x6d,0x57,0x95,0x4a,
  
};

static const unsigned char qt_resource_name[] = {
  // puzzleCollection.txt
  0x0,0x14,
  0x0,0xc0,0xb0,0x14,
  0x0,0x70,
  0x0,0x75,0x0,0x7a,0x0,0x7a,0x0,0x6c,0x0,0x65,0x0,0x43,0x0,0x6f,0x0,0x6c,0x0,0x6c,0x0,0x65,0x0,0x63,0x0,0x74,0x0,0x69,0x0,0x6f,0x0,0x6e,0x0,0x2e,
  0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/puzzleCollection.txt
  0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x84,0x6,0x47,0xe4,0x9a,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#if defined(__ELF__) || defined(__APPLE__)
static inline unsigned char qResourceFeatureZlib()
{
    extern const unsigned char qt_resourceFeatureZlib;
    return qt_resourceFeatureZlib;
}
#else
unsigned char qResourceFeatureZlib();
#endif

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_qmake_immediate)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_qmake_immediate)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_qmake_immediate)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_qmake_immediate)()
{
    int version = 3;
    version += QT_RCC_PREPEND_NAMESPACE(qResourceFeatureZlib());
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_qmake_immediate)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_qmake_immediate)(); }
   } dummy;
}