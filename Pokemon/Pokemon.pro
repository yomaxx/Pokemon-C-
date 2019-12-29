TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Game.cpp \
    main.cpp \
    battle.cpp \
    utility.cpp \
    PokemonData.cpp \
    Trainer.cpp

HEADERS += \
    battle.h \
    utility.h \
    PokemonData.h \
    Game.h \
    Trainer.h

RESOURCES += \
    music.qrc
