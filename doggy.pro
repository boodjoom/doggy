TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    leg.cpp \
    point.cpp \
    link.cpp \
    utils.cpp \
    stepplanner.cpp \
    body.cpp \
    servo.cpp \
    walker.cpp \
    motor.cpp

HEADERS += \
    leg.h \
    point.h \
    link.h \
    utils.h \
    config.h \
    stepplanner.h \
    body.h \
    servo.h \
    walker.h \
    motor.h

