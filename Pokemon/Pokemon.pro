TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Creature.cpp \
        Player.cpp \
        main.cpp \
    battle.cpp \
    Pokemon.cpp

HEADERS += \
    Creature.h \
    Player.h \
    battle.h \
    Pokemon.h
