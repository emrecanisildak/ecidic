#include "gearcontroller.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "Model/gearcomponentmodel.h"


ecilib::gear::GearController::GearController()
{
}

ecilib::gear::GearController::GearController(QQmlApplicationEngine *engine)
{
    mModeMap[PARK]    = "Park";
    mModeMap[REVERSE] = "Reverse";
    mModeMap[NEUTRAL] = "Neutral";
    mModeMap[DRIVE]   = "Drive";
    mModeMap[SPEED]   = "Speed";

    initGearModel();
    engine->rootContext()->setContextProperty("gear_model", mModel);
}

void ecilib::gear::GearController::switchMode(GearModes mode)
{
    if(const auto& itr = mModeMap.find(mode); itr != mModeMap.end())
        mModel->switchMode(mModeMap[mode]);
    else
        qWarning()<<"Gear Mode could not find!";
}

void ecilib::gear::GearController::initGearModel()
{
    mModel = new GearComponentModel();

    for(const auto &p : mModeMap)
    {
        mModel->addGearItem(GearItem{p.second,p.second.at(0),false});
    }
}
