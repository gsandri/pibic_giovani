TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        ./src/stock.cpp \
        ./src/wallet.cpp \
    definicoes.cpp

HEADERS += \
        ./include/stock.h \
        ./include/wallet.h \
    definicoes.h

INCLUDEPATH += ./include
