#ifndef POWERCONSUMPTIONCHARTMODEL_H
#define POWERCONSUMPTIONCHARTMODEL_H


// Qt Libs
#include <QAbstractTableModel>
#include <QObject>
#include <QTimer>

// Standart
#include <vector>

// User Defined
#include "PowerConsumptionComponent/powerconsumtionitem.h"

namespace ecilib::powerconsumtpion
{
class PowerConsumptionChartModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    PowerConsumptionChartModel();
    void                   addNewData(const PowerConsumtionItem& item);
    int                    rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int                    columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant               data(const QModelIndex &index, int role) const override;

private slots:
    void onTimeOut();

private:
    enum MyRoles :int {
        TotalDistanceTravveled = 0,
        InstantaneousPowerConsumption = 1,
        };

    std::vector<PowerConsumtionItem> mData;
    QTimer mTimer;

    double mCurrentTDT{0.0};
    double mChartMaxTDT{30.0};

};
}

#endif // POWERCONSUMPTIONCHARTMODEL_H
