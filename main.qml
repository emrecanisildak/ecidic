import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12
import QtLocation 5.6
import QtPositioning 5.6

import QtQuick.Controls 2.0

import "SpeedComponent"
import "GearComponent"
import "StatusBarComponent"
import "MapComponent"
import "NotificationComponent"


Window {
    property string backgroundColor: "black"
    x:100
    y:100
    visible: true
    width: 1800
    height: 800

    color: backgroundColor
    flags: Qt.FramelessWindowHint




    MySpeedComponent {
        id: speedComponent
        width: parent.width
        height: parent.height
        x:0
        y:0
        leftMargin:75
        topMargin:120
        bottomMargin:100
        componentPadding:20

        // Z Value Component
        layoutId: 100

        // Colors
        backgroundColor:backgroundColor
        componentColor:"red"
        componentHighlightColor:"white"


        // TODO : Bind speed
        speed: 20

    }

    // Map Component
    MapComponent {
        id: mapComponent
        x: 510
        y: parent.height/5.7
        width:parent.width/2.4
        height:parent.height/1.4
        opacity:1
        layoutId: 102
        backgroundColor:"black"

    }

    // Gear Component
    GearComponent {
        id: gearComponent
        x: 500 + mapComponent.x-gearComponent.width-60
        y: parent.height -60
    }

    // Material Status Component
    StatusBarComponent {
        id: statusBarComponent
        x: 400
        y: 40
    }

    NotificationComponent {
        id: notificationComponent
        anchors.top: mapComponent.top
        anchors.horizontalCenter: mapComponent.horizontalCenter
        width: 650
        height:150
        z:103
    }

    // TEST CODE FOR NOTIFICATION
//    Row{
//    Button {
//        text: "Ok"
//        onClicked: notificationComponent.notify("qrc:/NotificationComponent/icons/lightning.png","Arabanızın sarjı bitmek üzere",1000)
//    }

//    Button {
//        text: "YES"
//        onClicked: notificationComponent.state = "YES"
//    }

//    Button {
//        text: "NO"
//        onClicked: notificationComponent.state = "NO"
//    }
//   }


}
