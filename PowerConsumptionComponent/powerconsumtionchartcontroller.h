#ifndef POWERCONSUMTIONCHARTCONTROLLER_H
#define POWERCONSUMTIONCHARTCONTROLLER_H

#include <QObject>
#include <QRectF>


// Forward Declarations..
namespace QtCharts{class QVXYModelMapper;};
namespace ecilib::powerconsumtpion {class PowerConsumptionChartModel;}
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
    Q_PROPERTY(QRectF scopeAreaRect READ scopeAreaRect WRITE setScopeAreaRect NOTIFY scopeAreaRectChanged)


public:
    PowerConsumtionChartController();
    explicit PowerConsumtionChartController(QQmlApplicationEngine* engine);
    ~PowerConsumtionChartController();

    void   setAVGConsumption(double newAVGConsumption);
    double aVGConsumption() const;

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
    void   setScopeAreaRect(const QRectF& rect);


    const QRectF &scopeAreaRect() const;

public slots:
    void onConsumptionDataOccured(double pTDT, double pConsumption);

signals:
    void aVGConsumptionChanged();
    void minChartTDTChanged();
    void maxChartTDTChanged();
    void minChartPowerConsumptionChanged();
    void maxChartPowerConsumptionChanged();
    void yPosAVGLineChanged();
    void scopeAreaRectChanged();


private:
    double mAVGConsumption;
    double mYPosAVGLine;
    int    mMinChartTDT;
    int    mMaxChartTDT;
    int    mMinChartPowerConsumption;
    int    mMaxChartPowerConsumption;
    void   calculateYPOSAVG();

    QRectF mScopeAreaRect;

    QScopedPointer<PowerConsumptionChartModel> mModel;
    QScopedPointer<QtCharts::QVXYModelMapper> mMapper;

    Q_DISABLE_COPY(PowerConsumtionChartController)
};

}

#endif // POWERCONSUMTIONCHARTCONTROLLER_H
