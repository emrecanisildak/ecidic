QT += quick charts

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++2a

SOURCES += \
        Controllers/maincontroller.cpp \
        GearComponent/Model/gearcomponentmodel.cpp \
        GearComponent/gearcontroller.cpp \
        NotificationComponent/notificationcomponentcontroller.cpp \
        PowerConsumptionComponent/Models/powerconsumptionchartmodel.cpp \
        PowerConsumptionComponent/powerconsumtionchartcontroller.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Controllers/maincontroller.h \
    GearComponent/Model/gearcomponentmodel.h \
    GearComponent/gearcontroller.h \
    GearComponent/gearitem.h \
    NotificationComponent/notificationcomponentcontroller.h \
    NotificationComponent/notificationitem.h \
    PowerConsumptionComponent/Models/powerconsumptionchartmodel.h \
    PowerConsumptionComponent/powerconsumtionchartcontroller.h \
    PowerConsumptionComponent/powerconsumtionitem.h
