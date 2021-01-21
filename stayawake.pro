HEADERS       = window.h
SOURCES       = main.cpp \
                window.cpp
RESOURCES     = \
    stayawake.qrc

RC_ICONS = appicon.ico

include(singleapplication/singleapplication.pri)
DEFINES += QAPPLICATION_CLASS=QApplication

QT += widgets
CONFIG += static
CONFIG += ltcg
CONFIG += c++17

DISTFILES += LICENSE README.md
