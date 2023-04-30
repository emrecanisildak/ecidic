import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.15

Rectangle{
    property string backgroundColor:"black"

    id:statusBarComponent
    width: 550
    height: 20
    color:backgroundColor
    RowLayout
    {
        id:statusBarLayout
        anchors.fill: parent
        spacing:4


        StatusBarItem {
            id: time
            symbolText:"18.03"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 200
            Layout.minimumWidth: 200
        }


        StatusBarItem {
            id: temperautre
            symbolText:"25°"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 200
            Layout.minimumWidth: 200
        }

        StatusBarItem {
            id: user
            symbolText:"Emrecan"
            iconPath: "qrc:/StatusBarComponent/icon_statusbar/user.png"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 200
            Layout.minimumWidth: 200
        }

        Rectangle {
            color: 'transparent'
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            Layout.minimumWidth: 150

        }

        StatusBarItem {
            id: bluetooth
            symbolText:""
            iconPath:"qrc:/StatusBarComponent/icon_statusbar/bluetooth.png"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 20
            Layout.minimumWidth: 20
        }

        StatusBarItem {
            id: wireless
            symbolText:""
            iconPath:"qrc:/StatusBarComponent/icon_statusbar/wifi.png"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 20
            Layout.minimumWidth: 20
        }

        StatusBarItem {
            id: phone
            symbolText:""
            iconPath: "qrc:/StatusBarComponent/icon_statusbar/phone.png"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 20
            Layout.minimumWidth: 20
        }

        StatusBarItem {
            id: signal
            symbolText:""
            iconPath:"qrc:/StatusBarComponent/icon_statusbar/signal.png"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 20
            Layout.minimumWidth: 20
        }
    }//layout-end
}
