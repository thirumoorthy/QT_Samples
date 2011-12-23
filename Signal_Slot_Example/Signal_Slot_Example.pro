#-------------------------------------------------
#
# Project created by QtCreator 2011-12-23T11:38:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Signal_Slot_Example
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sender.cpp \
    receiver.cpp \
    uthread.cpp

HEADERS += \
    sender.h \
    receiver.h \
    uthread.h
