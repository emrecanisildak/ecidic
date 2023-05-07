#include "gearcontroller.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Model/gearcomponentmodel.h"


ecilib::gear::GearController::GearController()
{
}

ecilib::gear::GearController::~GearController()
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
    engine->rootContext()->setContextProperty("gear_model", mModel.get());
}

void ecilib::gear::GearController::switchMode(GearModes mode)
{
    if(const auto& itr = mModeMap.find(mode); itr != mModeMap.end())
        mModel->switchMode(mModeMap[mode]);
    else
    {
        // TODO LOGGER : Switch Mode not found..

    }
}

void ecilib::gear::GearController::initGearModel()
{
    mModel.reset(new GearComponentModel());

    for(const auto &p : mModeMap)
    {
        mModel->addGearItem(GearItem{p.second,p.second.at(0),false});
    }
}
