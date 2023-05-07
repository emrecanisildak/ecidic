#ifndef GEARCONTROLLER_H
#define GEARCONTROLLER_H

#include <QObject>
#include <QScopedPointer>
#include <map>

namespace ecilib::gear{class GearComponentModel;}
class QQmlApplicationEngine;

namespace ecilib::gear{

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
    ~GearController();
    void     switchMode(GearModes mode);

private:
    QScopedPointer<GearComponentModel> mModel;
    std::map<GearModes,QString> mModeMap;
    void     initGearModel();

    Q_DISABLE_COPY(GearController)
};
}

#endif // GEARCONTROLLER_H
