#ifndef NOTIFICATIONITEM_H
#define NOTIFICATIONITEM_H
#include <QString>
#include <chrono>
#include <QMetaType>

namespace ecilib::notification{

enum class NotificationType
{
    YesOrNo = 0,
    NoReply = 1,
};

enum class NotificationStatus
{
    None,
    InQueque,
    Displayed,
    Closed,
    Confirmed,
    Declined
};

struct NotificationItem
{
    NotificationItem(int pId, const QString& pMessage,const QString& pIconPath,
                     NotificationType pType,NotificationStatus pStatus,
                     std::chrono::nanoseconds pDisplayTime,std::chrono::milliseconds pDuration):
        mId{pId},
        mMessage{pMessage},
        mIconPath{pIconPath},
        mType{pType},
        mStatus{pStatus},
        mDisplayTime{pDisplayTime},
        mDuration{pDuration}
    {

    }
    NotificationItem():
        mId{},
        mMessage{},
        mIconPath{},
        mType{},
        mStatus{},
        mDisplayTime{},
        mDuration{}
    {

    }

    int                             mId;
    QString                         mMessage;
    QString                         mIconPath;
    NotificationType                mType;
    NotificationStatus              mStatus;
    std::chrono::nanoseconds        mDisplayTime; // ns Timestamp of the first display of the notification.
    std::chrono::milliseconds       mDuration;    // ms   Notification display duration

};

}

Q_DECLARE_METATYPE(ecilib::notification::NotificationItem)
Q_DECLARE_METATYPE(ecilib::notification::NotificationStatus)
Q_DECLARE_METATYPE(ecilib::notification::NotificationType)

#endif // NOTIFICATIONITEM_H
