#include "notificationcomponentcontroller.h"

ecilib::notification::NotificationComponentController::NotificationComponentController(QObject *parent)
{

}

void ecilib::notification::NotificationComponentController::pushNotification(const QString &pMessage,
                                                                             const QString &pIconPath,
                                                                             NotificationType pType)
{

}

ecilib::notification::NotificationItem ecilib::notification::NotificationComponentController::currentNotification() const
{
    return NotificationItem{};
}

void ecilib::notification::NotificationComponentController::closeCurrentNotification()
{

}

void ecilib::notification::NotificationComponentController::onConfirmButtonClicked()
{

}

void ecilib::notification::NotificationComponentController::onDeclineButtonClicked()
{

}

uint64_t  ecilib::notification::NotificationComponentController::generateUniqueId()
{
    std::chrono::high_resolution_clock m_clock;
    return std::chrono::duration_cast<std::chrono::nanoseconds>(m_clock.now().time_since_epoch()).count();
}
