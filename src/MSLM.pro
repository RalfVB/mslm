QT+=core gui concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#--------------------------------------------------------------------------------------------------
TARGET = MSLM
TEMPLATE = app
#--------------------------------------------------------------------------------------------------
DEFINES += QT_DEPRECATED_WARNINGS
#--------------------------------------------------------------------------------------------------
SOURCES += main.cpp \
    mainwindow.cpp \
    folderview.cpp \
    fileview.cpp \
    filemodel.cpp \
    software.cpp \
    infobox.cpp \
    infoboxpanel.cpp \
    filepathbox.cpp
#--------------------------------------------------------------------------------------------------
HEADERS += mainwindow.h \
    folderview.h \
    fileview.h \
    filemodel.h \
    software.h \
    infobox.h \
    infoboxpanel.h \
    filepathbox.h
#--------------------------------------------------------------------------------------------------
include(Editor/Editor.pri)