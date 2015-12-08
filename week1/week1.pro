QT += core
QT += core sql
QT -= gui

TARGET = week1
CONFIG += console
CONFIG -= app_bundle
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cpp \
    models/scientist.cpp \
    repositories/scientistrepository.cpp \
    services/scientistservice.cpp \
    ui/consoleui.cpp \
    Computer.cpp \
    ConnectTab.cpp

HEADERS += \
    models/scientist.h \
    repositories/scientistrepository.h \
    services/scientistservice.h \
    ui/consoleui.h \
    Computer.h \
    ConnectTab.h

