import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12


Item{
    id:speedComponent

    // 1800 800
    property int    leftMargin:30             // pixel
    property int    topMargin:50              // pixel
    property int    bottomMargin:50           // pixel
    property int    componentPadding:20       // pixel
    property string backgroundColor:"black"
    property string componentColor:"red"
    property string componentHighlightColor:"white"


    // Outer Highlight Element
    Rectangle{
        id:rect1
        width:parent.width - 2*leftMargin  // 1750
        height:parent.height - topMargin - bottomMargin
        x:leftMargin
        y:topMargin
        radius:130
        color: backgroundColor
        border.color: componentHighlightColor
        border.width: 2
        antialiasing: true
    }

    // Outer Rect Element
    Rectangle{
        id:rect2
        width:parent.width - 2*leftMargin
        height:parent.height - topMargin - bottomMargin
        x:leftMargin
        y:topMargin
        radius:130
        color: backgroundColor
        border.color: componentColor
        border.width: 1
        opacity:0.6
        antialiasing: true
    }

      // Inner Highlight Element
    Rectangle{
        id:rect3
        width:parent.width - 2*leftMargin-componentPadding
        height:parent.height - topMargin - bottomMargin-componentPadding
        x:leftMargin+componentPadding/2
        y:topMargin+componentPadding/2
        radius:130
        color: backgroundColor
        border.color: componentHighlightColor
        border.width: 2
        antialiasing: true
    }

    // Inner Rect Element
    Rectangle{
        id:rect4
        width:parent.width - 2*leftMargin-componentPadding
        height:parent.height - topMargin - bottomMargin-componentPadding
        x:leftMargin+componentPadding/2
        y:topMargin+componentPadding/2
        radius:130
        color: backgroundColor
        border.color: componentColor
        border.width: 1
        opacity:0.6
        antialiasing: true
    }
}
