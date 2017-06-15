#ifndef MYGAME_AIRCRAFT_H
#define MYGAME_AIRCRAFT_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Aircraft : public cocos2d::Sprite {
public:
    int getHealthPoints() const;
    cocos2d::ui::LoadingBar * getHealthPointsBar() const;
    double getHealthPointsDelta() const;

    void setHealthPoints(int healthPoints);
    void setHealthPointsBar(cocos2d::ui::LoadingBar * healthPointsBar);
    void setHealthPointsDelta(double healthPointsDelta);

    static Aircraft * createAircraft(const std::string & filename);
private:
    int healthPoints;
    cocos2d::ui::LoadingBar * healthPointsBar;
    double healthPointsDelta;
};


#endif //MYGAME_AIRCRAFT_H
