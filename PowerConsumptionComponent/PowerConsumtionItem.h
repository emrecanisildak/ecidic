#ifndef POWERCONSUMTIONITEM_H
#define POWERCONSUMTIONITEM_H


namespace ecilib::powerconsumtpion
{
struct PowerConsumtionItem
{
    PowerConsumtionItem():mTDT{},mIPC{} {}
    PowerConsumtionItem(double pTDT, double pIPC):mTDT(pTDT),mIPC(pIPC){}
    double mTDT;  // total distance travveled (km)
    double mIPC; // instantaneous power consumption (kW)
};
}

#endif // POWERCONSUMTIONITEM_H
