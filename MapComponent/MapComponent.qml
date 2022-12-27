import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12
import QtLocation 5.6
import QtPositioning 5.6


Rectangle{
    id:mapComponent
    width:700
    height:500
    z: 102
    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        anchors.fill: mapComponent
        plugin: mapPlugin
        zoomLevel: 8
        minimumZoomLevel: 0
        maximumZoomLevel: 15
        center: QtPositioning.coordinate(39.32,34)
        activeMapType: supportedMapTypes[4]
    }
}
