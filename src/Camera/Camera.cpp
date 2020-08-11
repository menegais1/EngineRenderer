//
// Created by menegais1 on 01/07/2020.
//

#include "Camera.h"
#include <cmath>
//#include "../Utilities.h"

fMatrix Camera::generateViewMatrix(fvec3 eye, fvec3 at, fvec3 up) {
    fvec3 forward = (eye - at).unit();
    fvec3 right = up.cross(forward).unit();
    up = forward.cross(right).unit();

    fMatrix T(4, 4);
    T.m = {{1, 0, 0, -eye.x},
           {0, 1, 0, -eye.y},
           {0, 0, 1, -eye.z},
           {0, 0, 0, 1}};
    fMatrix R = fMatrix::identity(4);

    R.setRow(right.toVector4(0), 0);
    R.setRow(up.toVector4(0), 1);
    R.setRow(forward.toVector4(0), 2);
    View = R * T;
    this->right = right;
    this->forward = -forward;
    this->up = up;
    this->center = eye;
    this->at = at;
    return View;
}

fMatrix Camera::generateProjectionMatrix(float fov, float aspectRatio, float _near, float _far) {
    fMatrix P = fMatrix::identity(4);
    P.m = {{1.0 / (std::tan(fov / 2.0) * aspectRatio), 0,                         0,                                       0},
           {0,                                         1.0 / std::tan(fov / 2.0), 0,                                       0},
           {0,                                         0,                       ( - (_near + _far) )/ (float) (_far - _near), (-2 * _near * _far) / (float) (_far - _near)},
           {0,                                         0,                         -1,                                      0}};
    Projection = P;

    this->_fov = fov;
    this->_aspectRatio = aspectRatio;
    this->_near = _near;
    this->_far = _far;
    this->_height = std::tan(fov / 2.0) * ((_far + _near) / 2.0);
    this->_width = _height;
    return Projection;
}

fMatrix
Camera::generateOrtographicProjectionMatrix(float width, float height, float aspectRatio, float _near, float _far) {
    fMatrix P = fMatrix::identity(4);
    P.m = {{1.0 / ((height * aspectRatio)), 0,                  0,                    0},
           {0,                                  1.0 / (height), 0,                    0},
           {0,                                  0,                  -2.0 / (_far - _near), -(_near + _far) /
                                                                                          (_far - _near)},
           {0,                                  0,                  0,                    1}};
    Projection = P;
    this->_aspectRatio = aspectRatio;
    this->_width = width;
    this->_height = height;
    this->_near = _near;
    this->_far = _far;
    return Projection;
}

void Camera::setViewport(int width, int height, int x, int y) {
    this->Vx = x;
    this->Vy = y;
    this->Vheight = height;
    this->Vwidth = width;
}
Camera *Camera::getInstance() {
    static Camera *c = new Camera();
    return c;
}

Camera::Camera() {
    cameraType = CameraType::Perspective;
}

float Camera::getNear() const {
    return _near;
}

float Camera::getFar() const {
    return _far;
}

float Camera::getFov() const {
    return _fov;
}

float Camera::getAspectRatio() const {
    return _aspectRatio;
}

float Camera::getWidth() const {
    return _width;
}

float Camera::getHeight() const {
    return _height;
}


