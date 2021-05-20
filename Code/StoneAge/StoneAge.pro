QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    boardview.cpp \
    building.cpp \
    buildingview.cpp \
    cardbonus.cpp \
    civilisation.cpp \
    dicebonus.cpp \
    field.cpp \
    gather.cpp \
    hut.cpp \
    main.cpp \
    mainwindow.cpp \
    miscbonus.cpp \
    otherplaceview.cpp \
    payciv.cpp \
    payfood.cpp \
    pickbonus.cpp \
    pickresources.cpp \
    place.cpp \
    player.cpp \
    playerview.cpp \
    resourceplaceview.cpp \
    rollbonus.cpp \
    rollresources.cpp \
    setbonus.cpp \
    setbuilding.cpp \
    setbuildingpay.cpp \
    showbonus.cpp \
    tool.cpp \
    toolbonus.cpp \
    toolshed.cpp \
    varbuilding.cpp \
    varbuildingpay.cpp \
    workeradd.cpp

HEADERS += \
    board.h \
    boardview.h \
    building.h \
    buildingview.h \
    cardbonus.h \
    civbonuses.h \
    civilisation.h \
    colour.h \
    dicebonus.h \
    field.h \
    gather.h \
    hut.h \
    mainwindow.h \
    miscbonus.h \
    otherplaceview.h \
    payciv.h \
    payfood.h \
    pickbonus.h \
    pickresources.h \
    place.h \
    player.h \
    playerview.h \
    resourceplaceview.h \
    resources.h \
    rollbonus.h \
    rollresources.h \
    setbonus.h \
    setbuilding.h \
    setbuildingpay.h \
    showbonus.h \
    tool.h \
    toolbonus.h \
    toolshed.h \
    varbuilding.h \
    varbuildingpay.h \
    workeradd.h

FORMS += \
    mainwindow.ui \
    payciv.ui \
    payfood.ui \
    pickresources.ui \
    rollresources.ui \
    setbuildingpay.ui \
    showbonus.ui \
    varbuildingpay.ui \
    workeradd.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    saves.qrc
