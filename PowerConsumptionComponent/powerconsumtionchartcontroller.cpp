#include "powerconsumtionchartcontroller.h"


#include <QQmlContext>
#include <QQmlApplicationEngine>

ecilib::powerconsumtpion::PowerConsumtionChartController::PowerConsumtionChartController()
{

}

ecilib::powerconsumtpion::PowerConsumtionChartController::PowerConsumtionChartController(QQmlApplicationEngine* engine)
{
    // SET DEFAULT VAL
    setMinChartTDT(-30);
    setMaxChartTDT(0);
    setMinChartPowerConsumption(-300);
    setMaxChartPowerConsumption(500);
    setAVGConsumption(300);

    mModel  = new PowerConsumptionChartModel();
    mMapper = new QVXYModelMapper();
    mMapper->setModel(mModel);

    mMapper->setXColumn(0);
    mMapper->setYColumn(1);

    engine->rootContext()->setContextProperty("power_cc_model", mModel);
    engine->rootContext()->setContextProperty("power_cc_mapper", mMapper);
}

void ecilib::powerconsumtpion::PowerConsumtionChartController::onConsumptionDataOccured(double pTDT, double pConsumption)
{
    mModel->addNewData(PowerConsumtionItem{pTDT,pConsumption});
}


int ecilib::powerconsumtpion::PowerConsumtionChartController::maxChartPowerConsumption() const
{
    return mMaxChartPowerConsumption;
}

void ecilib::powerconsumtpion::PowerConsumtionChartController::setMaxChartPowerConsumption(int newMaxChartPowerConsumption)
{
    if (mMaxChartPowerConsumption == newMaxChartPowerConsumption)
        return;
    mMaxChartPowerConsumption = newMaxChartPowerConsumption;
    emit maxChartPowerConsumptionChanged();
}


int ecilib::powerconsumtpion::PowerConsumtionChartController::minChartPowerConsumption() const
{
    return mMinChartPowerConsumption;
}

void ecilib::powerconsumtpion::PowerConsumtionChartController::setMinChartPowerConsumption(int newMinChartPowerConsumption)
{
    if (mMinChartPowerConsumption == newMinChartPowerConsumption)
        return;
    mMinChartPowerConsumption = newMinChartPowerConsumption;
    emit minChartPowerConsumptionChanged();
}

int ecilib::powerconsumtpion::PowerConsumtionChartController::maxChartTDT() const
{
    return mMaxChartTDT;
}

void ecilib::powerconsumtpion::PowerConsumtionChartController::setMaxChartTDT(int newMaxChartTDT)
{
    if (mMaxChartTDT == newMaxChartTDT)
        return;
    mMaxChartTDT = newMaxChartTDT;
    emit maxChartTDTChanged();
}


int ecilib::powerconsumtpion::PowerConsumtionChartController::minChartTDT() const
{
    return mMinChartTDT;
}

void ecilib::powerconsumtpion::PowerConsumtionChartController::setMinChartTDT(int newMinChartTDT)
{
    if (mMinChartTDT == newMinChartTDT)
        return;
    mMinChartTDT = newMinChartTDT;
    emit minChartTDTChanged();
}

double ecilib::powerconsumtpion::PowerConsumtionChartController::aVGConsumption() const
{
    return mAVGConsumption;
}

void ecilib::powerconsumtpion::PowerConsumtionChartController::setAVGConsumption(double newAVGConsumption)
{
    if (qFuzzyCompare(mAVGConsumption, newAVGConsumption))
        return;
    mAVGConsumption = newAVGConsumption;
    emit aVGConsumptionChanged();


    // TODO FROM QML
    calculateYPOSAVG(mAVGConsumption);
}


double ecilib::powerconsumtpion::PowerConsumtionChartController::yPosAVGLine() const
{
    return mYPosAVGLine;
}

void ecilib::powerconsumtpion::PowerConsumtionChartController::setYPosAVGLine(double newYPosAVGLine)
{
    if (qFuzzyCompare(mYPosAVGLine, newYPosAVGLine))
        return;
    mYPosAVGLine = newYPosAVGLine;
    emit yPosAVGLineChanged();
}


void ecilib::powerconsumtpion::PowerConsumtionChartController::calculateYPOSAVG(double AVG)
{
    QRectF rect(69, 52.5, 388, 448.5);

    // Calculate YPOS
    double y = (mAVGConsumption - mMinChartPowerConsumption) / (mMaxChartPowerConsumption - mMinChartPowerConsumption);
    y =  y*(rect.height());
    y =rect.height() - y + rect.y();

    setYPosAVGLine(y);
}







