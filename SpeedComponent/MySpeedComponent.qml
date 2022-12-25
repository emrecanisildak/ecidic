import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12


Item{
    id:speedComponent

    // Base Value
    property int    speed:120
    property string speedUnit:"km/h"


    // Design Public Variable
    property int    leftMargin:30             // pixel
    property int    topMargin:50              // pixel
    property int    bottomMargin:50           // pixel
    property int    componentPadding:20       // pixel
    property string backgroundColor:"black"
    property string componentColor:"red"
    property string componentHighlightColor:"white"
    property int    layoutId:100



    // Private variable
    Item{
        id:privateVar
        property int    highBorderWidth:2
        property int    borderWidth:1
        property int    rectRadius:130
        property double rectOpacity:0.6



        property int    componentHeight: parent.height - topMargin - bottomMargin
        property int    topWidth:300
        property int    bottomWidth:200

    }

    Rectangle{
        id:speedValue
        x:leftMargin + privateVar.topWidth/3
        y: privateVar.componentHeight/2
        z:layoutId+2
        width:150
        height:200
        color:backgroundColor
        border.color: "blue"
        radius:200
        border.width: 2
        antialiasing: true
    }

//    Text{
//        id:speedText
//        x:leftMargin + 100
//        y:topMargin + 150
//        z:layoutId +3
//        text:speed.toString()
//        font.family: "Helvetica"
//        font.pointSize: 60
//        color: componentHighlightColor
//    }

//    Text{
//        id:speedUnitText
//        text:speedUnit
//        x:leftMargin + 100
//        y:topMargin + 150
//        z:layoutId +3
//        font.family: "Helvetica"
//        font.pointSize: 30
//        color: componentHighlightColor
//    }


    // Cover Rect
    Rectangle{
        id:coverRect
        width:parent.width - 2*leftMargin
        height: privateVar.componentHeight //parent.height - topMargin - bottomMargin
        x:leftMargin + privateVar.topWidth
        y:topMargin
        color:backgroundColor
        z:layoutId+1
    }

    Rectangle{
        id:coverRect2
        width:parent.width - 2*leftMargin
        height:privateVar.componentHeight
        x:leftMargin + privateVar.bottomWidth
        y:topMargin + parent.height - topMargin - bottomMargin-componentPadding
        color:backgroundColor
        z:layoutId+1
    }



    // Outer Highlight Element
    Rectangle{
        id:rect1
        width:parent.width - 2*leftMargin  // 1750
        height:privateVar.componentHeight
        x:leftMargin
        y:topMargin
        z:layoutId
        radius: privateVar.rectRadius
        color: backgroundColor
        border.color: componentHighlightColor
        border.width: privateVar.highBorderWidth //2
        antialiasing: true
    }

    // Outer Rect Element
    Rectangle{
        id:rect2
        width:parent.width - 2*leftMargin
        height:privateVar.componentHeight
        x:leftMargin
        y:topMargin
        z:layoutId
        radius:   privateVar.rectRadius
        color: backgroundColor
        border.color: componentColor
        border.width: privateVar.borderWidth //1
        opacity:privateVar.rectOpacity
        antialiasing: true
    }

      // Inner Highlight Element
    Rectangle{
        id:rect3
        width:parent.width - 2*leftMargin-componentPadding
        height:privateVar.componentHeight-componentPadding
        x:leftMargin+componentPadding/2
        y:topMargin+componentPadding/2
        z:layoutId
        radius: privateVar.rectRadius
        color: backgroundColor
        border.color: componentHighlightColor
        border.width: privateVar.highBorderWidth
        antialiasing: true
    }

    // Inner Rect Element
    Rectangle{
        id:rect4
        width:parent.width - 2*leftMargin-componentPadding
        height:privateVar.componentHeight-componentPadding
        x:leftMargin+componentPadding/2
        y:topMargin+componentPadding/2
        z:layoutId
        radius: privateVar.rectRadius
        color: backgroundColor
        border.color: componentColor
        border.width: privateVar.borderWidth
        opacity:privateVar.rectOpacity
        antialiasing: true
    }





}
