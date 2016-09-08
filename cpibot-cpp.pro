QT += core network
QT -= gui

CONFIG += c++11

TARGET = cpibot-cpp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    conn.cpp \
    message.cpp \
    members.cpp \
    bot.cpp

HEADERS += \
    conn.h \
    message.h \
    members.h \
    bot.h
