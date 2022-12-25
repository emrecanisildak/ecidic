import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12

import "SpeedComponent"

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
        leftMargin:75               // pixel  // 75
        topMargin:120               // pixel  // 120
        bottomMargin:100            // pixel  // 100
        componentPadding:20         // pixel  // 20

        layoutId: 100

        // Colors
        backgroundColor:"black"   // const
        componentColor:"red"
        componentHighlightColor:"white"


    }

}
