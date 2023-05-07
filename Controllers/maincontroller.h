#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QScopedPointer>

namespace ecilib::powerconsumtpion{ class PowerConsumtionChartController;}
namespace ecilib::gear {class GearController;}
class QQmlApplicationEngine;

namespace ecilib::logic{
class MainController : public QObject
{
    Q_OBJECT
public:
    MainController();
    ~MainController();
    void init(QQmlApplicationEngine *engine);

private:
    QScopedPointer<ecilib::powerconsumtpion::PowerConsumtionChartController> m_power_chart_controller;
    QScopedPointer<ecilib::gear::GearController> m_gear_controller;
    QQmlApplicationEngine   *mQMLEngine;

    void initPowerConstumptionController();
    void initGearController();

    Q_DISABLE_COPY(MainController)

};

}
#endif // MAINCONTROLLER_H
