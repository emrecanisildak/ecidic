import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12
import QtLocation 5.6
import QtPositioning 5.6


Item{
    property int layoutId: 102
    property string backgroundColor:"red"

    id:mapComponent
    z: layoutId
    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        anchors.fill: mapComponent
        plugin: mapPlugin
        zoomLevel: 15
        minimumZoomLevel: 0
        maximumZoomLevel: 20
        center: QtPositioning.coordinate(39.1,33.9)
        activeMapType: supportedMapTypes[3]
        copyrightsVisible :false
    }


    Rectangle{
        id:transationRect
        color:"transparent"
        opacity:0.9
        z:layoutId+1
        width:parent.width
        height:parent.height
        anchors.centerIn: parent
        antialiasing: true


        LinearGradient {
            anchors.fill: parent
            gradient: Gradient {
                GradientStop { position: 0.0; color: backgroundColor }
                GradientStop { position: 0.2; color: "transparent" }
            }
        }

        LinearGradient {
            anchors.fill: parent
            gradient: Gradient {
                orientation: Gradient.Horizontal
                GradientStop { position: 0.0; color: backgroundColor }
                GradientStop { position: 0.2; color: "transparent" }
            }
        }

        LinearGradient {
            anchors.fill: parent
            gradient: Gradient {
                orientation: Gradient.Vertical
                GradientStop { position: 0.8; color: "transparent" }
                GradientStop { position: 1; color:backgroundColor }
            }
        }

        LinearGradient {
            anchors.fill: parent
            gradient: Gradient {
                orientation: Gradient.Horizontal
                GradientStop { position: 0.8; color: "transparent" }
                GradientStop { position: 1; color: backgroundColor }
            }
        }
    }



}
