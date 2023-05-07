#include "powerconsumptionchartmodel.h"

#include <QTimer>

ecilib::powerconsumtpion::PowerConsumptionChartModel::PowerConsumptionChartModel()
{
    mTimer.reset(new QTimer);
    mData.reserve(1000);
    mTimer->start(mTimerTickInterval);
    connect(mTimer.get(), &QTimer::timeout, this,[&](){onTimeOut();});
}

void ecilib::powerconsumtpion::PowerConsumptionChartModel::addNewData(const PowerConsumtionItem &item)
{
    mCurrentTDT = item.mTDT;

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mData.push_back(item);
    endInsertRows();
}

int ecilib::powerconsumtpion::PowerConsumptionChartModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(mData.size());
}

int ecilib::powerconsumtpion::PowerConsumptionChartModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mColumnCount;
}

QVariant ecilib::powerconsumtpion::PowerConsumptionChartModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)
    switch (index.column()) {
    case TotalDistanceTravveled:
        return mData[index.row()].mTDT-mCurrentTDT;
    case InstantaneousPowerConsumption:
        return mData[index.row()].mIPC;
    default:
        return QVariant{};
    }

}


void ecilib::powerconsumtpion::PowerConsumptionChartModel::onTimeOut()
{
    beginResetModel();
    auto isAgeOut = [&](const PowerConsumtionItem& item) {return mCurrentTDT - item.mTDT > mChartMaxTDT;} ;
    std::erase_if(mData,isAgeOut);
    endResetModel();
}
