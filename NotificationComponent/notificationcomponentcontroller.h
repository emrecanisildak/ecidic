#ifndef NOTIFICATIONCOMPONENTCONTROLLER_H
#define NOTIFICATIONCOMPONENTCONTROLLER_H

#include <QObject>
#include <any>
#include <NotificationComponent/notificationitem.h>

namespace ecilib::notification{

class NotificationComponentController : public QObject
{
    Q_OBJECT
public:
    explicit NotificationComponentController(QObject *parent = nullptr);

    uint64_t           pushNotification(const QString& message,const QString& iconPath, NotificationType type,int duration);
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

    void closeToQMLItem(CloseType type);



};

}

#endif // NOTIFICATIONCOMPONENTCONTROLLER_H
