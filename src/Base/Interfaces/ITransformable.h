#ifndef ITRANSFORMABLE_H
#define ITRANSFORMABLE_H

#include "../../Vectors/Vector3.h"

class ITransformable {
public:
    virtual void translate(fvec3 translationAmount) = 0;

    virtual void rotateX(float angle) = 0;

    virtual void rotateZ(float angle) = 0;

    virtual void rotateY(float angle) = 0;

    virtual void rescale(fvec3 scale) = 0;
};

#endif
