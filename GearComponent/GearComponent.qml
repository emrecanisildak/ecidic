import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12


Item{
    property color  activeColor: "#909090"
    property color  deactiveColor: "#383838"
    property int    textPixelSize: 25
    property int    layoutSpacing: 20
    property int    activeBorderRadius: 4
    property int    activeBorderWidth:1

    id:gearComponent
    width: 200
    height:200

    ListView {
        anchors.fill: parent
        orientation: ListView.Horizontal
        model: gear_model
        delegate: gearDelegate
        spacing: gearComponent.layoutSpacing

    }

    // Delegate
    Component {
        id: gearDelegate

        // Border
        Rectangle{
            id:gearDelegateItem
            width:symbolText.contentWidth+10
            height:symbolText.contentHeight+1
            color:"transparent"
            border.color:  isActive ? gearComponent.activeColor : "transparent"
            border.width: gearComponent.activeBorderWidth
            radius: gearComponent.activeBorderRadius

            // Text
            Text {
                id:symbolText
                anchors.centerIn: parent
                text: symbol
                font.pixelSize : gearComponent.textPixelSize
                font.weight: isActive ?  Font.Normal : Font.ExtraLight
                font.family : "Inter"
                color: isActive ? gearComponent.activeColor : gearComponent.deactiveColor
            }
        }
    }



}
