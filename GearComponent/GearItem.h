#ifndef GEARITEM_H
#define GEARITEM_H

#include <QString>

namespace ecilib::gear{
struct GearItem
{
    GearItem(const QString& pModeName, const QString& pModeSymbol, bool pStatus):
        mModeName{pModeName},
        mModeSymbol{pModeSymbol},
        mStatus{pStatus}
    {

    }
    GearItem(){}

    QString mModeName;
    QString mModeSymbol;
    bool    mStatus;

};
}
#endif // GEARITEM_H
