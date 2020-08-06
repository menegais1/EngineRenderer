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

fvec3 Camera::convertNDCToViewport(fvec3 ndc) {
    return fvec3(((ndc.x + 1) * Vwidth / 2.0) + Vx, ((ndc.y + 1) * Vheight / 2.0) + Vy, ndc.z);
}

//https://dl.acm.org/doi/pdf/10.1145/965139.807398 implemented from http://medialab.di.unipi.it/web/IUM/Waterloo/node51.html
float Camera::clipLineSegmentOnNear(fvec4 p0, fvec4 p1, bool &p0Out, bool &p1Out) {
    if (-p0.z + p0.w > 0 && -p1.z + p1.w > 0) {
        p0Out = p1Out = false;
        return 0;
    }
    if (-p0.z + p0.w <= 0 && -p1.z + p1.w <= 0) {
        p0Out = p1Out = true;
        return 0;
    } else if (-p0.z + p0.w < 0) {
        float t = -((p0.w - p0.z) / ((p0.z + p1.w) - (p0.w + p1.z)));
        p0Out = true;
        p1Out = false;
        return t;
    } else {
        float t = -((p0.w - p0.z) / ((p0.z + p1.w) - (p0.w + p1.z)));
        p0Out = false;
        p1Out = true;
        return t;
    }
}

fvec3 Camera::convertWorldToView(fvec3 vertex) {
    auto projectedPoint = View * vertex.toVector4(1);
    return projectedPoint.toVector3();
}

fvec4 Camera::convertViewToClipSpace(fvec3 vertex) {
    auto projectedPoint = Projection * vertex.toVector4(1);
    return projectedPoint.toVector4();
}

fvec3 Camera::convertClipSpaceToNDC(fvec4 vertex) {
    return fvec3(vertex.x / vertex.w, vertex.y / vertex.w, vertex.z / vertex.w);
}
//
//void Camera::line(fvec3 p0, fvec3 p1) {
//    fvec4 clipP0 = convertViewToClipSpace(convertWorldToView(p0));
//    fvec4 clipP1 = convertViewToClipSpace(convertWorldToView(p1));
//    bool p0Out = false, p1Out = false;
//    float t = clipLineSegmentOnNear(clipP0, clipP1, p0Out, p1Out);
//    if (p0Out && p1Out) return;
//    if (!p1Out && !p0Out) {
//        p0 = convertNDCToViewport(convertClipSpaceToNDC(clipP0));
//        p1 = convertNDCToViewport(convertClipSpaceToNDC(clipP1));
//        CV::line(p0, p1);
//    } else if (p0Out && !p1Out) {
//        clipP0 = lerp(clipP0, clipP1, t);
//        p0 = convertNDCToViewport(convertClipSpaceToNDC(clipP0));
//        p1 = convertNDCToViewport(convertClipSpaceToNDC(clipP1));
//        CV::line(p0, p1);
//    } else if (!p0Out && p1Out) {
//        clipP1 = lerp(clipP0, clipP1, t);
//        p0 = convertNDCToViewport(convertClipSpaceToNDC(clipP0));
//        p1 = convertNDCToViewport(convertClipSpaceToNDC(clipP1));
//        CV::line(p0, p1);
//
//    }
//}

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


