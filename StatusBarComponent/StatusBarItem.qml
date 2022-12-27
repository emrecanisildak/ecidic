import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

Item{
    id:statusBarItem
    property string symbolText:""
    property string iconPath :""
    Image{
        id:visualImage
        source:iconPath
        width:18
        height:18
        anchors.centerIn: parent
    }

    // Text
    Text {
        id:visualText
        anchors.left: visualImage.right
        anchors.verticalCenter: visualImage.verticalCenter
        padding: 5
        text: symbolText
        font.pixelSize : 18
        font.weight: Font.Normal
        font.family : "Inter"
        color:"gray"
    }
}
