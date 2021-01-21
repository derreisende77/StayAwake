HEADERS       = window.h
SOURCES       = main.cpp \
                window.cpp
RESOURCES     = \
    stayawake.qrc

RC_ICONS = appicon.ico

# disable all the deprecated APIs in Qt <= 6.0.0
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
DEFINES += QT_DEPRECATED_WARNINGS

include(singleapplication/singleapplication.pri)
DEFINES += QAPPLICATION_CLASS=QApplication

QT += widgets
CONFIG += static
CONFIG += ltcg
CONFIG += c++17

DISTFILES += LICENSE README.md
