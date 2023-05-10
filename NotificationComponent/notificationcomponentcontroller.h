#ifndef NOTIFICATIONCOMPONENTCONTROLLER_H
#define NOTIFICATIONCOMPONENTCONTROLLER_H

#include <QObject>
#include <NotificationComponent/notificationitem.h>

namespace ecilib::notification{

class NotificationComponentController : public QObject
{
    Q_OBJECT
public:
    explicit NotificationComponentController(QObject *parent = nullptr);

    void               pushNotification(const QString& pMessage,const QString& pIconPath, NotificationType pType);
    NotificationItem   currentNotification()const;
    void               closeCurrentNotification();
    NotificationStatus getCurrentStatus(uint64_t id)const;


public slots:
    void onConfirmButtonClicked();
    void onDeclineButtonClicked();

signals:
    void notifcationStatusChanged(uint64_t notificationId,NotificationStatus status);

private:
    std::vector<NotificationItem> mNotificationsQueue;
    static uint64_t  generateUniqueId();


};

}

#endif // NOTIFICATIONCOMPONENTCONTROLLER_H
