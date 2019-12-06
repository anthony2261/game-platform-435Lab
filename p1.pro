QT+=widgets
#QT+=testlib

CONFIG += qt warn_on release
CONFIG += c++11

HEADERS += \
    mainwidget.h \
    signupwidget.h \
    loggedwidget.h \
	user.h \
    gamewidget.h \
    scoreswidget.h \
    snakesandladders.h \
    snake.h \
    ladder.h \
    cabo.h \
    caboplayer.h \
    cabocard.h

SOURCES += \
    mainwidget.cpp \
    main.cpp \
    signupwidget.cpp \
	user.cpp \
	loggedwidget.cpp \
    gamewidget.cpp \
    scoreswidget.cpp \
    snakesandladders.cpp \
    snake.cpp \
    ladder.cpp \
    cabo.cpp \
    caboplayer.cpp \
    cabocard.cpp
