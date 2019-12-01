QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

CONFIG += c++11
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    compilecontrol.cpp \
        compstmt.cpp \
    createcontrol.cpp \
        declintstmt.cpp \
        endstmt.cpp \
    executecontrol.cpp \
        filemanager.cpp \
        identifier.cpp \
        jmorestmt.cpp \
        jmpstmt.cpp \
        label.cpp \
        main.cpp \
        mainwindow.cpp \
    opencontrol.cpp \
        operand.cpp \
    preferencemanager.cpp \
        preferences.cpp \
        printstmt.cpp \
        program.cpp \
    proxypreferences.cpp \
        readstmt.cpp \
    realpreferences.cpp \
    renamecontrol.cpp \
    savecontrol.cpp \
        statement.cpp \
        uimanager.cpp \
        variable.cpp \
 	Create.cpp \
        Save.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    compilecontrol.h \
    compstmt.h \
    createcontrol.h \
    declintstmt.h \
    endstmt.h \
    executecontrol.h \
    filemanager.h \
    identifier.h \
    jmorestmt.h \
    jmpstmt.h \
    label.h \
    mainwindow.h \
    opencontrol.h \
    operand.h \
    preferencemanager.h \
    preferences.h \
    printstmt.h \
    program.h \
    proxypreferences.h \
    readstmt.h \
    realpreferences.h \
    renamecontrol.h \
    savecontrol.h \
    statement.h \
    uimanager.h \
    variable.h \
    Create.h \
    Save.h \

FORMS += \
    mainwindow.ui

DISTFILES += \
    ../README.md \
    ../localRepo/test1.txt \
    ../localRepo/test2.json \
    ../localRepo/test2.txt
