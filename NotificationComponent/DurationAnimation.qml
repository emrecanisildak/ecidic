import QtQuick 2.15
import QtQuick.Window 2.15


NumberAnimation  {
    id: durationAnim;
    target:notificationRect;
    property: "opacity";
    from: notificationOpacity;
    to: notificationOpacity;
    duration: notificationDuration;
}
