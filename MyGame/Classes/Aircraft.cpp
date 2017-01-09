#include "Aircraft.h"

int Aircraft::getHealthPoints() const {
    return healthPoints;
}

cocos2d::ui::LoadingBar * Aircraft::getHealthPointsBar() const {
    return healthPointsBar;
}

double Aircraft::getHealthPointsDelta() const {
    return healthPointsDelta;
}

void Aircraft::setHealthPoints(int healthPoints) {
    Aircraft::healthPoints = healthPoints;
}

void Aircraft::setHealthPointsBar(cocos2d::ui::LoadingBar * healthPointsBar) {
    Aircraft::healthPointsBar = healthPointsBar;
}

void Aircraft::setHealthPointsDelta(double healthPointsDelta) {
    Aircraft::healthPointsDelta = healthPointsDelta;
}

Aircraft * Aircraft::createAircraft(const std::string & filename) {
    Aircraft * aircraft = new Aircraft();
    if (aircraft && aircraft->initWithSpriteFrameName(filename)) {
        aircraft->autorelease();
        return aircraft;
    }
    CC_SAFE_DELETE(aircraft);
    return nullptr;
}

