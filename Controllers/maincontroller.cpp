#include "maincontroller.h"
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "GearComponent/gearcontroller.h"
#include "PowerConsumptionComponent/powerconsumtionchartcontroller.h"


#define TEST

#ifdef TEST
#include <QTimer>
#include <QRandomGenerator64>
#endif

ecilib::logic::MainController::MainController():
    mQMLEngine(nullptr)
{


#ifdef TEST
    QTimer* timer = new QTimer(this);
    timer->start(100);

    QTimer* timer2 = new QTimer(this);
    timer2->start(5000);

    connect(timer2,&QTimer::timeout,[&](){
        m_gear_controller->switchMode((gear::GearModes)QRandomGenerator::global()->bounded(0,5));

    });



    // 00 -30
    connect(timer,&QTimer::timeout,[&](){
        static double ttD = 400;
        ttD += 0.05;
        static double power = 0;
        auto val3 = QRandomGenerator::global()->bounded(-3,10);
        power += val3;
        if(power > 400)
            power = 0.0;
        m_power_chart_controller->onConsumptionDataOccured(ttD,power);
    });


#endif

}

ecilib::logic::MainController::~MainController()
{
}

void ecilib::logic::MainController::init(QQmlApplicationEngine *engine)
{
    mQMLEngine = engine;
    initPowerConstumptionController();
    initGearController();
}

void ecilib::logic::MainController::initPowerConstumptionController()
{
    using namespace ecilib::powerconsumtpion;

    m_power_chart_controller.reset(new powerconsumtpion::PowerConsumtionChartController(mQMLEngine));
    qmlRegisterType<PowerConsumtionChartController>("com.ecicompany.powerconsumptionchart", 1, 0, "PowerController");
}

void ecilib::logic::MainController::initGearController()
{
    using namespace ecilib::gear;

    qmlRegisterType<GearController>("com.ecicompany.gearcontroller", 1, 0, "GearController");
    m_gear_controller.reset( new GearController(mQMLEngine));
}
