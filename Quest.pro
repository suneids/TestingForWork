QT       += core gui opengl
macx:{
    LIBS += -framework OpenGL
    QT += openglwidgets
}
win32:{
    QT += openglwidgets
    LIBS += -lopengl32 -lglu32
}


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    elipse.cpp \
    graphicwidget.cpp \
    helix.cpp \
    mainwindow.cpp\
    main.cpp \
    circle.cpp \
    figure.cpp \
    point.cpp

HEADERS += \
    elipse.h \
    graphicwidget.h \
    helix.h \
    mainwindow.h\
    circle.h \
    figure.h \
    point.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
