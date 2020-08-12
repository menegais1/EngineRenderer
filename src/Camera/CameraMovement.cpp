//
// Created by menegais1 on 12/07/2020.
//

#include <sstream>
#include "../IMGui/imgui.h"
#include "CameraMovement.h"
#include "../Utilities.h"
#include "../Managers/GlobalManager.h"
#include "../Backend/GraphicsLibrary.h"
#include <GLFW/glfw3.h>


CameraMovement::CameraMovement(Camera *camera) : camera(camera), angle(0, 0) {
    setObjectOrder(10000);
    eye = camera->center;
    at = camera->at;
    up = camera->up;
}

void CameraMovement::keyboard(int key, int scancode, int action, int mods) {
    double moveSpeed = cameraSpeed * GlobalManager::getInstance()->deltaTime;

    if (key == GLFW_KEY_O) {
        camera->cameraType = CameraType::Orthographic;
        camera->generateOrtographicProjectionMatrix(camera->getWidth(), camera->getHeight(), camera->getAspectRatio(),
                                                    camera->getNear(), camera->getFar());
    }

    if (key == GLFW_KEY_P) {
        camera->cameraType = CameraType::Perspective;
        Camera::getInstance()->generateProjectionMatrix(camera->getFov(), camera->getAspectRatio(), camera->getNear(),
                                                        camera->getFar());
    }

    if (key == GLFW_KEY_W && camera->cameraType == CameraType::Perspective) {
        eye = camera->center + camera->forward * moveSpeed;
        at = camera->at + camera->forward * moveSpeed;
        up = fvec3(0, 1, 0);

    } else if (key == GLFW_KEY_S && camera->cameraType == CameraType::Perspective) {
        eye = camera->center + camera->forward * -moveSpeed;
        at = camera->at + camera->forward * -moveSpeed;
        up = fvec3(0, 1, 0);
    } else if (key == GLFW_KEY_D) {
        eye = camera->center + camera->right * moveSpeed;
        at = camera->at + camera->right * moveSpeed;
        up = fvec3(0, 1, 0);

    } else if (key == GLFW_KEY_A) {
        eye = camera->center + camera->right * -moveSpeed;
        at = camera->at + camera->right * -moveSpeed;
        up = fvec3(0, 1, 0);
    } else if (key == GLFW_KEY_Q) {
        eye = camera->center + fvec3(0, 1, 0) * moveSpeed;
        at = camera->at + fvec3(0, 1, 0) * moveSpeed;
        up = fvec3(0, 1, 0);

    } else if (key == GLFW_KEY_E) {
        eye = camera->center + fvec3(0, 1, 0) * -moveSpeed;
        at = camera->at + fvec3(0, 1, 0) * -moveSpeed;
        up = fvec3(0, 1, 0);
    }
}

void CameraMovement::mouseButton(int button, int action, int modifier) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        isDragging = true;
    } else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
        isDragging = false;
    }
}

void CameraMovement::mouseMovement(double xpos, double ypos) {
    if (isDragging && camera->cameraType == CameraType::Perspective) {

        float xDelta = (xpos - lastMousePosition.x);
        float yDelta = (ypos - lastMousePosition.y);
        float xOffset = xDelta * mouseSensitivity;
        float yOffset = yDelta * mouseSensitivity;

        angle.x += yOffset;
        angle.y += xOffset;

        if (angle.x >= 89) {
            angle.x = 89;
        } else if (angle.x <= -89) {
            angle.x = -89;
        }

        fvec3 direction;
        direction.x = cos(angle.y  * PI / 180.0) * cos(angle.x * PI / 180.0);
        direction.y = sin(angle.x * PI / 180.0);
        direction.z = sin(angle.y  * PI / 180.0) * cos(angle.x * PI / 180.0);

        at = eye + direction.unit();
    }
    lastMousePosition = fvec2(xpos, ypos);

}

float CameraMovement::mouseSensitivity = 1;
float CameraMovement::cameraSpeed = 5;

void CameraMovement::render() {
    camera->generateViewMatrix(eye, at, up);

    GraphicsLibrary::line(fvec3(0, 0, 0), fvec3(10, 0, 0));
    GraphicsLibrary::line(fvec3(0, 0, 0), fvec3(0, 10, 0));
    GraphicsLibrary::line(fvec3(0, 0, 0), fvec3(0, 0, 10));
}

