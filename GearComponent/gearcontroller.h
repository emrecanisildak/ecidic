#ifndef GEARCONTROLLER_H
#define GEARCONTROLLER_H

#include <QObject>
#include <map>
#include <QVariant>
#include <QPointer>

class QQmlApplicationEngine;

namespace ecilib::gear{
class GearComponentModel;

enum GearModes{
    PARK,
    REVERSE,
    NEUTRAL,
    DRIVE,
    SPEED
};

class GearController : public QObject
{
public:
    explicit GearController(QQmlApplicationEngine* engine);
    GearController();
    void     switchMode(GearModes mode);

private:
    QPointer<GearComponentModel> mModel;
    std::map<GearModes,QString> mModeMap;
    void     initGearModel();

};
}

#endif // GEARCONTROLLER_H
