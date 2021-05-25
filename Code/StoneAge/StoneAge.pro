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
    cardbonusview.cpp \
    civilisation.cpp \
    civilisationview.cpp \
    dicebonus.cpp \
    dicebonusview.cpp \
    field.cpp \
    gather.cpp \
    hut.cpp \
    main.cpp \
    mainwindow.cpp \
    miscbonus.cpp \
    miscbonusview.cpp \
    otherplaceview.cpp \
    payciv.cpp \
    payfood.cpp \
    pickbonus.cpp \
    pickbonusview.cpp \
    pickresources.cpp \
    pickrolled.cpp \
    place.cpp \
    player.cpp \
    playerview.cpp \
    resourceplaceview.cpp \
    rollbonus.cpp \
    rollresources.cpp \
    setbonus.cpp \
    setbonusview.cpp \
    setbuilding.cpp \
    setbuildingpay.cpp \
    showbonus.cpp \
    showcivreward.cpp \
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
    cardbonusview.h \
    civbonuses.h \
    civilisation.h \
    civilisationview.h \
    colour.h \
    dicebonus.h \
    dicebonusview.h \
    field.h \
    gather.h \
    hut.h \
    mainwindow.h \
    miscbonus.h \
    miscbonusview.h \
    otherplaceview.h \
    payciv.h \
    payfood.h \
    pickbonus.h \
    pickbonusview.h \
    pickresources.h \
    pickrolled.h \
    place.h \
    player.h \
    playerview.h \
    resourceplaceview.h \
    resources.h \
    rollbonus.h \
    rollresources.h \
    setbonus.h \
    setbonusview.h \
    setbuilding.h \
    setbuildingpay.h \
    showbonus.h \
    showcivreward.h \
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
    pickrolled.ui \
    rollresources.ui \
    setbuildingpay.ui \
    showbonus.ui \
    showcivreward.ui \
    varbuildingpay.ui \
    workeradd.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    saves.qrc
