#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <memory>
#include "PowerConsumptionComponent/powerconsumtionchartcontroller.h"
#include "GearComponent/gearcontroller.h"

class QQmlApplicationEngine;


namespace ecilib::logic{

    class MainController : public QObject
    {
        Q_OBJECT
    public:
        explicit MainController();
        void init(QQmlApplicationEngine *engine);

    private:
        QQmlApplicationEngine* m_qml_engine = nullptr;
        ecilib::powerconsumtpion::PowerConsumtionChartController* m_power_chart_controller;
        ecilib::gear::GearController* m_gear_controller;



    };

}
#endif // MAINCONTROLLER_H
