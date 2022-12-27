import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12
import QtLocation 5.6
import QtPositioning 5.6

import "SpeedComponent"
import "GearComponent"
import "StatusBarComponent"
import "MapComponent"


Window {
    property string backgroundColor: "black"
    width: 1800
    height: 800
    visible: true
    color: backgroundColor
    flags: Qt.FramelessWindowHint
    x:100
    y:100


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
        layoutId: 100
        // Colors
        backgroundColor:backgroundColor
        componentColor:"red"
        componentHighlightColor:"white"

        speed: 20

    }

    // Map Component
    MapComponent {
        id: mapComponent
        x: 500
        y: 150
        opacity:0.8

    }

    // Gear Component
    GearComponent {
        id: gearComponent
        x: parent.width/2 -width
        y: parent.height -100
    }

    // Material Status Component
    StatusBarComponent {
        id: statusBarComponent
        x: 400
        y: 40
    }

}
