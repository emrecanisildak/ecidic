#ifndef GEARCOMPONENTMODEL_H
#define GEARCOMPONENTMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "GearComponent/gearitem.h"

namespace ecilib::gear{
class GearComponentModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles{
        ModeName= Qt::UserRole+1,
        ModeSymbol,
        Status
    };

    GearComponentModel();
    void addGearItem(const GearItem& item);
    void switchMode(const QString& mModeName);

    // QAbstractItemModel interface
    int                    rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant               data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QHash<int, QByteArray> mRoleNames;
    std::vector<GearItem> mData;
};


}

#endif // GEARCOMPONENTMODEL_H
