TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    src/view.cpp \
    src/second_turn.cpp \
    src/player.cpp \
    src/game_interface.cpp \
    src/first_turn.cpp \
    src/field_implementation.cpp \
    src/end_turn.cpp \
    src/card.cpp

HEADERS += \
    include/view.h \
    include/second_turn.h \
    include/player.h \
    include/memory_state.h \
    include/game_interface.h \
    include/first_turn.h \
    include/field_implementation.h \
    include/end_turn.h \
    include/card.h \
    include/view_state.h

