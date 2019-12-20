TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Game.cpp \
    Trainer.cpp \
        Player.cpp \
        main.cpp \
    battle.cpp \
    Pokemon.cpp \
    utility.cpp

HEADERS += \
    Game.h \
    Player.h \
    Trainer.h \
    battle.h \
    Pokemon.h \
    utility.h

RESOURCES += \
    music.qrc
