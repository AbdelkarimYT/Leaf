QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    categorydialog.cpp \
    chashform.cpp \
    clientsform.cpp \
    customerdialog.cpp \
    familydialog.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    orderdialog.cpp \
    ordersform.cpp \
    prodectdialog.cpp \
    prodectsform.cpp \
    sellingform.cpp \
    supplierdialog.cpp \
    suppliersform.cpp \
    userdialog.cpp

HEADERS += \
    categorydialog.h \
    chashform.h \
    clientsform.h \
    customerdialog.h \
    familydialog.h \
    logindialog.h \
    mainwindow.h \
    models.h \
    orderdialog.h \
    ordersform.h \
    prodectdialog.h \
    prodectsform.h \
    sellingform.h \
    supplierdialog.h \
    suppliersform.h \
    userdialog.h

FORMS += \
    categorydialog.ui \
    chashform.ui \
    clientsform.ui \
    customerdialog.ui \
    familydialog.ui \
    logindialog.ui \
    mainwindow.ui \
    orderdialog.ui \
    ordersform.ui \
    prodectdialog.ui \
    prodectsform.ui \
    sellingform.ui \
    supplierdialog.ui \
    suppliersform.ui \
    userdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    res/add.png \
    res/app.jpg \
    res/barcode.png \
    res/category.png \
    res/customer.png \
    res/delete.png \
    res/family-tree.png \
    res/trolley.png \
    res/update.png \
    res/user.png
