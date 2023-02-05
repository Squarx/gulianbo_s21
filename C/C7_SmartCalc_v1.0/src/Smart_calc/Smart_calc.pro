QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Smart_calc.c \
    calc.cpp \
    deposit.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    true_deposit.cpp

HEADERS += \
    ../Smart_calc.h \
    calc.h \
    deposit.h \
    mainwindow.h \
    qcustomplot.h \
    true_deposit.h

FORMS += \
    calc.ui \
    deposit.ui \
    mainwindow.ui \
    true_deposit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
