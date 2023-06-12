#include "notificationcomponentcontroller.h"
#include "Common/utility.h"

ecilib::notification::NotificationComponentController::NotificationComponentController(QObject *parent)
{

}

uint64_t ecilib::notification::NotificationComponentController::pushNotification(const QString& message,
                                                                                 const QString& iconPath,
                                                                                 NotificationType type,
                                                                                 int duration)
{
    // epoch is used for unique id.
    auto epoch_ms = ecilib::utility::current_epoch_ms();
    NotificationItem item{epoch_ms,message,iconPath,type,NotificationStatus::InQueque,duration,0};
    mNotificationsQueue.push_back(std::move(item));
    return epoch_ms;
}

ecilib::notification::NotificationItem  ecilib::notification::NotificationComponentController::currentNotification() const
{
    auto isDisplayed = [](const NotificationItem& notification){return notification.mStatus == NotificationStatus::Displayed;};

    if(auto itr = std::find_if(begin(mNotificationsQueue),end(mNotificationsQueue),isDisplayed); itr != end(mNotificationsQueue))
        return currentNotification() = (*itr);

    return NotificationItem{};
}

void ecilib::notification::NotificationComponentController::closeCurrentNotification()
{
   closeToQMLItem(CloseType::NO_ANIMATION);
}

void ecilib::notification::NotificationComponentController::onConfirmButtonClicked()
{
    auto current_notification = currentNotification();

    if(!current_notification.isValidNotification())
        return;

    if(!(current_notification.mType == NotificationType::YesOrNo))
        return;

    closeToQMLItem(CloseType::YES);

}

void ecilib::notification::NotificationComponentController::onDeclineButtonClicked()
{    
    auto current_notification = currentNotification();

    if(!current_notification.isValidNotification())
        return;

    if(!(current_notification.mType == NotificationType::YesOrNo))
        return;

    closeToQMLItem(CloseType::NO);

}

void ecilib::notification::NotificationComponentController::closeToQMLItem(CloseType type)
{
    auto isCurrent = [](const NotificationItem& notification){return notification.mStatus == NotificationStatus::Displayed;};

//    if(auto itr = std::find_if(begin(mNotificationsQueue),end(mNotificationsQueue),isCurrent); itr != end(mNotificationsQueue))
//    {
//    }
}
