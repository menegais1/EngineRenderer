//
// Created by menegais1 on 01/07/2020.
//

#ifndef PROJECTIONEXERCISE_CAMERA_H
#define PROJECTIONEXERCISE_CAMERA_H


#include "../Vectors/Vector3.h"

enum class CameraType {
    Orthographic,
    Perspective
};

class Camera {
public:

    fMatrix View;
    fMatrix Projection;

    CameraType cameraType;

    static Camera *getInstance();

    fMatrix generateViewMatrix(fvec3 eye, fvec3 at, fvec3 up);

    fMatrix generateProjectionMatrix(float fov, float aspectRatio, float near, float far);

    fvec3 convertNDCToViewport(fvec3 ndc);

    void setViewport(int width, int height, int x, int y);

    fvec3 convertWorldToView(fvec3 vertex);

    fMatrix generateOrtographicProjectionMatrix(float width, float height, float aspectRatio, float near, float far);

    fvec4 convertViewToClipSpace(fvec3 vertex);

    fvec3 convertClipSpaceToNDC(fvec4 vertex);

    float clipLineSegmentOnNear(fvec4 p0, fvec4 p1, bool &p0Out, bool &p1Out);

    void line(fvec3 p0, fvec3 p1);

    float getNear() const;

    float getFar() const;

    float getFov() const;

    float getAspectRatio() const;

    float getWidth() const;

    float getHeight() const;

    fvec3 center;
    fvec3 up;
    fvec3 forward;
    fvec3 right;
    fvec3 at;
private:
    int Vx;
    int Vy;
    int Vheight;
    int Vwidth;
    float _near;
    float _far;
    float _fov;
    float _aspectRatio;
    float _width;
    float _height;

    Camera();


};


#endif //PROJECTIONEXERCISE_CAMERA_H
