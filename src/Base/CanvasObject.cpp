#include "CanvasObject.h"
#include "../Managers/GlobalManager.h"
#include "../Utilities.h"
#include <iostream>
#include "../Vectors/Vector3.h"

void CanvasObject::render() {
}

void CanvasObject::setActive(bool isActive) {
    lastActiveState = this->isActive;
    this->isActive = isActive;
}

bool CanvasObject::getActive() {
    return this->isActive;
}

bool CanvasObject::checkIfCanExecuteCallback() {
    if (!isValid) return false;
    if (lastActiveState != isActive) {
        bool tmp = lastActiveState;
        lastActiveState = isActive;
        return tmp;
    }
    return this->isActive;
}

void CanvasObject::setObjectOrder(int zIndex) {
    this->objectOrder = zIndex;
    GlobalManager::getInstance()->changeObjectOrder(this);
}

int CanvasObject::getObjectOrder() {
    return objectOrder;
}

CanvasObject::CanvasObject() {
    objectOrder = 0;
    isValid = true;
    isActive = true;
    lastActiveState = false;
    objectId = GlobalManager::getInstance()->registerObject(this);
}

CanvasObject::~CanvasObject() {
    GlobalManager::getInstance()->unregisterObject(this);
}

void CanvasObject::keyboard(int key, int scancode, int action, int mods) {

}

void CanvasObject::mouseButton(int button, int action, int modifier) {

}

void CanvasObject::mouseMovement(double xpos, double ypos) {

}
