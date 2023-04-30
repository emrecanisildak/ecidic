#include "gearcomponentmodel.h"

#include <QDebug>

ecilib::gear::GearComponentModel::GearComponentModel()
{
    mRoleNames[ModeSymbol] = "symbol";
    mRoleNames[ModeName]   = "name";
    mRoleNames[Status]     = "isActive";
}

void ecilib::gear::GearComponentModel::addGearItem(const GearItem &item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mData.push_back(item);
    endInsertRows();
}

void ecilib::gear::GearComponentModel::switchMode(const QString &mModeName)
{
    beginResetModel();
    for(auto&& g : mData)
    {
        if(mModeName == g.mModeName)
            g.mStatus = true;
        else
            g.mStatus = false;
    }
    endResetModel();
}

int ecilib::gear::GearComponentModel::rowCount(const QModelIndex &parent) const
{
    return mData.size();
}

QVariant ecilib::gear::GearComponentModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role)
    {
    case ModeName:
        return mData.at(index.row()).mModeName;
    case ModeSymbol:
        return mData.at(index.row()).mModeSymbol;
    case Status:
        return mData.at(index.row()).mStatus;
    default:
        return QVariant{};
    }
}

QHash<int, QByteArray> ecilib::gear::GearComponentModel::roleNames() const
{
    return mRoleNames;
}
