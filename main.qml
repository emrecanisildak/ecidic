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
        leftMargin:75               // pixel
        topMargin:120               // pixel
        bottomMargin:100            // pixel
        componentPadding:20         // pixel

        // Colors
        backgroundColor:"black"   // const
        componentColor:"blue"
        componentHighlightColor:"white"


    }

}
