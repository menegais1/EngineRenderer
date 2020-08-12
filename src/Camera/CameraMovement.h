//
// Created by menegais1 on 12/07/2020.
//

#ifndef CARENGINE_CAMERAMOVEMENT_H
#define CARENGINE_CAMERAMOVEMENT_H


#include "../Base/CanvasObject.h"
#include "Camera.h"

class CameraMovement : public CanvasObject {
private:
    Camera *camera;
    fvec2 lastMousePosition;
    bool isDragging = false;
    fvec2 angle;

    fvec3 eye;
    fvec3 at;
    fvec3 up;
public:

    static float mouseSensitivity;
    static float cameraSpeed;

    CameraMovement(Camera *camera);

    void keyboard(int key, int scancode, int action, int mods) override;

    void mouseButton(int button, int action, int modifier) override;

    void mouseMovement(double xpos, double ypos) override;

    void render() override;

};


#endif //CARENGINE_CAMERAMOVEMENT_H
