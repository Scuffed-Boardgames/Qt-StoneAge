QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    boardview.cpp \
    main.cpp \
    mainwindow.cpp \
    placeview.cpp \
    player.cpp \
    playerview.cpp \
    resources.cpp \
    rollresources.cpp \
    worker.cpp \
    workeradd.cpp

HEADERS += \
    board.h \
    boardview.h \
    colour.h \
    mainwindow.h \
    placeview.h \
    player.h \
    playerview.h \
    resources.h \
    rollresources.h \
    worker.h \
    workeradd.h

FORMS += \
    mainwindow.ui \
    rollresources.ui \
    workeradd.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
