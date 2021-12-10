QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adward.cpp \
    challenge.cpp \
    children.cpp \
    createchellenge.cpp \
    dbmanager.cpp \
    gatheringinf.cpp \
    main.cpp \
    mainwindow.cpp \
    mycheckbox.cpp \
    qtreewidgetutil.cpp \
    start.cpp \
    treeview.cpp \
    userinfo.cpp

HEADERS += \
    adward.h \
    challenge.h \
    children.h \
    createchellenge.h \
    dbmanager.h \
    gatheringinf.h \
    mainwindow.h \
    mycheckbox.h \
    qtreewidgetutil.h \
    start.h \
    treeview.h \
    userinfo.h

FORMS += \
    adward.ui \
    createchellenge.ui \
    gatheringinf.ui \
    mainwindow.ui \
    start.ui \
    treeview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES +=
