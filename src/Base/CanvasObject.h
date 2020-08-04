#ifndef CANVAS_OBJECT_H
#define CANVAS_OBJECT_H

#include "../Utilities.h"
#include "Interfaces/ITransformable.h"
#include "../Vectors/Vector3.h"

class CanvasObject{
public:

    bool isValid;

    virtual void render();

    virtual void keyboard(int key, int scancode, int action, int mods);

    virtual void mouseButton(int button, int action, int modifier);

    virtual void mouseMovement(double xpos, double ypos);

    virtual void setObjectOrder(int zIndex);

    int getObjectOrder();

    CanvasObject();

    virtual ~CanvasObject();

    virtual void setActive(bool isActive);

    bool getActive();

    bool checkIfCanExecuteCallback();

protected:
    bool isActive;
    int objectId;

private:
    int objectOrder;
    bool lastActiveState;

};

#endif
