#ifndef POWERCONSUMTIONCHARTCONTROLLER_H
#define POWERCONSUMTIONCHARTCONTROLLER_H

// Qt's Lib
#include <QObject>
#include <QScopedPointer>
#include <QVXYModelMapper>
#include  "Models/powerconsumptionchartmodel.h"


// Forward Declarations..
class QQmlApplicationEngine;

namespace ecilib::powerconsumtpion{
class PowerConsumtionChartController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double aVGConsumption READ aVGConsumption WRITE setAVGConsumption  NOTIFY aVGConsumptionChanged)
    Q_PROPERTY(int minChartTDT READ minChartTDT WRITE setMinChartTDT NOTIFY minChartTDTChanged)
    Q_PROPERTY(int maxChartTDT READ maxChartTDT WRITE setMaxChartTDT  NOTIFY maxChartTDTChanged)
    Q_PROPERTY(int minChartPowerConsumption READ minChartPowerConsumption WRITE setMinChartPowerConsumption NOTIFY minChartPowerConsumptionChanged)
    Q_PROPERTY(int maxChartPowerConsumption READ maxChartPowerConsumption WRITE setMaxChartPowerConsumption NOTIFY maxChartPowerConsumptionChanged)
    Q_PROPERTY(double yPosAVGLine READ yPosAVGLine WRITE setYPosAVGLine NOTIFY yPosAVGLineChanged)

public:
    PowerConsumtionChartController();
    explicit PowerConsumtionChartController(QQmlApplicationEngine* engine);


    double aVGConsumption() const;
    void   setAVGConsumption(double newAVGConsumption);
    double yPosAVGLine() const;
    void   setYPosAVGLine(double newYPosAVGLine);
    int    minChartTDT() const;
    void   setMinChartTDT(int newMinChartTDT);
    int    maxChartTDT() const;
    void   setMaxChartTDT(int newMaxChartTDT);
    int    minChartPowerConsumption() const;
    void   setMinChartPowerConsumption(int newMinChartPowerConsumption);
    int    maxChartPowerConsumption() const;
    void   setMaxChartPowerConsumption(int newMaxChartPowerConsumption);



public slots:
    void onConsumptionDataOccured(double pTDT, double pConsumption);

signals:
    void aVGConsumptionChanged();
    void minChartTDTChanged();
    void maxChartTDTChanged();
    void minChartPowerConsumptionChanged();
    void maxChartPowerConsumptionChanged();
    void yPosAVGLineChanged();


private:
    double mAVGConsumption;
    double mYPosAVGLine;
    int    mMinChartTDT;
    int    mMaxChartTDT;
    int    mMinChartPowerConsumption;
    int    mMaxChartPowerConsumption;
    void   calculateYPOSAVG(double AVG);

    QScopedPointer<PowerConsumptionChartModel> mModel;
    QScopedPointer<QtCharts::QVXYModelMapper> mMapper;
};

}

#endif // POWERCONSUMTIONCHARTCONTROLLER_H
