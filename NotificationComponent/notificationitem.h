#ifndef NOTIFICATIONITEM_H
#define NOTIFICATIONITEM_H
#include <QString>
#include <chrono>
#include <QMetaType>

namespace ecilib::notification{

enum class CloseType
{
    NO_ANIMATION,
    YES = 0,
    NO = 1
};


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
    NotificationItem(uint64_t pId, const QString& pMessage,const QString& pIconPath,
                     NotificationType pType,NotificationStatus pStatus,
                     int pDuration,uint64_t pDisplayTime):
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
        mId{0},
        mMessage{},
        mIconPath{},
        mType{},
        mStatus{NotificationStatus::None},
        mDisplayTime{},
        mDuration{}
    {

    }

    bool isValidNotification()const
    {
        return mId > 0;
    }

    uint64_t                        mId;
    QString                         mMessage;
    QString                         mIconPath;
    NotificationType                mType;
    NotificationStatus              mStatus;
    uint64_t                        mDisplayTime; // ms   Timestamp of the first display of the notification.
    int                             mDuration;    // ms   Notification display duration

};

}

Q_DECLARE_METATYPE(ecilib::notification::NotificationItem)
Q_DECLARE_METATYPE(ecilib::notification::NotificationStatus)
Q_DECLARE_METATYPE(ecilib::notification::NotificationType)

#endif // NOTIFICATIONITEM_H
