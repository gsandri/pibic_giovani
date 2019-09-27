TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        ./src/stock.cpp

HEADERS += \
        ./include/stock.h

INCLUDEPATH += ./include
