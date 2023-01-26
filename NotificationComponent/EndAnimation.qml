import QtQuick 2.15
import QtQuick.Window 2.15


ParallelAnimation {
    id:endAnim
    NumberAnimation  {
        id: c1;
        target:notificationRect;
        property: "opacity";
        to: 0;
        from: notificationOpacity;
        duration: closingDuration;
    }
    NumberAnimation  {
        id: b2;
        target:bottomRect;
        property: "width";
        to: notificationComponent.width;
        from: 0;
        duration: closingDuration;
        easing.type: Easing.InOutCubic
    }
    NumberAnimation  {
        id: t2;
        target:topRect;
        property: "width";
        to: notificationComponent.width;
        from: 0;
        duration: closingDuration;
        easing.type: Easing.InOutCubic
    }
    NumberAnimation  {
        id: r2;
        target:righRect;
        property: "height";
        to: notificationComponent.height;
        from: 0;
        duration: closingDuration;
        easing.type: Easing.InOutCubic
    }
    NumberAnimation  {
        id: l2;
        target:leftRect;
        property: "height";
        to: notificationComponent.height;
        from: 0;
        duration: closingDuration;
        easing.type: Easing.InOutCubic
    }

}
