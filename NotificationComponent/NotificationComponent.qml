import QtQuick 2.15
import QtQuick.Window 2.15


Item{
    id:notificationComponent
    states: [
        State {
            name: "YES"
            PropertyChanges { target:notificationComponent; notificationBorderColor:notificationConfirmColor; }
            StateChangeScript {
                         name: "YES"
                         script:
                         {
                             notificationAnim.stop()
                             notificationOpacity:notificationRect.opacity
                             endAnim.start()
                         }
                     }

        },
        State {
            name: "NO"
             PropertyChanges { target:notificationComponent; notificationBorderColor:notificationDeclineColor; }
             StateChangeScript {
                          name: "NO"
                          script:{
                          notificationAnim.stop()
                          notificationOpacity:notificationRect.opacity
                          endAnim.start()
                          }
                      }

        },
        State {
            name: "DEFAULT"
             PropertyChanges { target:notificationComponent; notificationBorderColor:notificationDefaultColor; }
        }

    ]

    // Notification Opacity
    property int    notificationLayer:70
    property double notificationOpacity:0.7

    // Border colors
    property  string  notificationBorderColor:"gray"
    property  string  notificationDefaultColor:"gray"
    property  string  notificationConfirmColor:"green"
    property  string  notificationDeclineColor:"red"

    // Animation Durations
    property int    openingDuration:2000
    property int    closingDuration:2000
    property int    notificationDuration:4000

    // Notification Text
    property string notificationContent:""
    property string textFontFamily:"Inter"
    property string textColor:"white"
    property int    textPointSize:14

    // Icon path
    property string iconPath:""
    property int    symbolSize: 32

    function notify(iconSource, conText, duration){
        notificationComponent.state = "DEFAULT"
        notificationAnim.start()
        notificationDuration = duration
        notificationContent = conText
        iconPath = iconSource
    }

    // Main Rect
    Rectangle
    {
        id:notificationRect
        color:"black"
        x:0
        y:0
        height:parent.height
        width:parent.width
        border.color: notificationBorderColor
        border.width: 1
        radius: 20
        opacity:0
        z:notificationLayer

        // Symbol
        Image{
            id:symbol
            source:iconPath
            x:parent.width/2 - width/2
            y:10
            width:symbolSize
            height:symbolSize
            antialiasing: true
            z:notificationLayer
        }

        // Text
        Text{
            id:notificationText
            anchors.fill:parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: textFontFamily
            font.pointSize: textPointSize
            color:textColor
            text:notificationContent
            z:notificationLayer
        }

        // Top animation rect
        Rectangle{
            id:topRect
            color:"black"
            x:0
            y:0
            height:1
            width:parent.width
            z:notificationLayer+1
        }

        // Top animation rect
        Rectangle{
            id:topRect3
            color:"black"
            x:0
            y:0
            height:1
            width:parent.width
            z:notificationLayer+3
        }

        // Bottom animation rect
        Rectangle{
            id:bottomRect
            color:"black"
            x:0
            y:parent.height-1
            height:1
            width:parent.width
            z:notificationLayer
        }

        // Right Animation Rect
        Rectangle{
            id:righRect
            color:"black"
            x:0
            y:0
            height:parent.height
            width:2
            z:notificationLayer
        }

        // Left Animation Rect
        Rectangle{
            id:leftRect
            color:"black"
            x:parent.width-1
            y:0
            height:parent.height
            width:1
            z:notificationLayer
        }

        // All Animations
        SequentialAnimation {
            id:notificationAnim

            StartingAnimation {
                id: startingAnimation
            }

            DurationAnimation {
                id: durationAnimation
            }

           EndAnimation{
            id:endAnimation
            }

        }

        // This use for interrupt notificationAnim and close notification when come reply
        EndAnimation {
            id: endAnim
        }
    }//end big rect

}
