import QtQuick 2.15
import QtQuick.Window 2.15


ParallelAnimation {
    id:startingAnim

    NumberAnimation  {
        id: openingNotification;
        target:notificationRect;
        property: "opacity";
        from: 0;
        to: notificationOpacity;
        duration: openingDuration;
    }
    NumberAnimation  {
        id: bottomAnim;
        target:bottomRect;
        property: "width";
        from: notificationComponent.width;
        to: 0;
        duration: openingDuration;
        easing.type: Easing.InOutCubic
    }
    NumberAnimation  {
        id: topAnim;
        target:topRect;
        property: "width";
        from: notificationComponent.width;
        to: 0; duration: openingDuration;
        easing.type: Easing.InOutCubic
    }
    NumberAnimation  {
        id: rightAnim;
        target:righRect;
        property: "height";
        from: notificationComponent.height;
        to: 0;
        duration: openingDuration;
        easing.type: Easing.InOutCubic
    }
    NumberAnimation  {
        id: leftAnim;
        target:leftRect;
        property: "height";
        from: notificationComponent.height;
        to: 0; duration: openingDuration;
        easing.type: Easing.InOutCubic
    }

}
