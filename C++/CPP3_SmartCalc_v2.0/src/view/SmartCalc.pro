QT       += core gui printsupport concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/controller.cc \
    ../model/calcmodel.cc \
    ../model/creditmodel.cc \
    ../model/debetmodel.cc \
    creditcalc.cc \
    debetcalc.cc \
    ../main.cc \
    mainwindow.cc \
    qcustomplot.cc \
    qplot.cc \
    smartcalc.cc

HEADERS += \
    ../common/myqdoublevalidator.h \
    ../controller/controller.h \
    ../model/calcmodel.h \
    ../model/creditmodel.h \
    ../model/debetmodel.h \
    creditcalc.h \
    debetcalc.h \
    mainwindow.h \
    qcustomplot.h \
    qplot.h \
    smartcalc.h

FORMS += \
    creditcalc.ui \
    debetcalc.ui \
    mainwindow.ui \
    qplot.ui \
    smartcalc.ui


win32:RC_FILE = ../icons/file.rc
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES +=
