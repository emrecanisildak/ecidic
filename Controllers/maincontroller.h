#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QScopedPointer>

#include "GearComponent/gearcontroller.h"
#include "PowerConsumptionComponent/powerconsumtionchartcontroller.h"

// Forward Declarations..
class QQmlApplicationEngine;

namespace ecilib::logic{

    class MainController : public QObject
    {
        Q_OBJECT
    public:
        explicit MainController();
        void init(QQmlApplicationEngine *engine);

    private:
         QScopedPointer<ecilib::powerconsumtpion::PowerConsumtionChartController> m_power_chart_controller;
         QScopedPointer<ecilib::gear::GearController> m_gear_controller;
         QQmlApplicationEngine   *mQMLEngine;

        void initPowerConstumptionController();
        void initGearController();

    };

}
#endif // MAINCONTROLLER_H
