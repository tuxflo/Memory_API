TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    lib/src/player.cpp \
    ../Memory_API_build/main.cpp

HEADERS += \
    lib/includes/player.h \
    lib/includes/card.h \
    lib/includes/board.h

