//
// Created by menegais1 on 12/07/2020.
//

#ifndef CARENGINE_TRANSFORM_H
#define CARENGINE_TRANSFORM_H


#include "../../Vectors/Vector3.h"

class Transform {
public:
    fvec3 position;
    fvec3 rotation;
    fvec3 scale;

    Transform(const fvec3 &position, const fvec3 &rotation, const fvec3 &scale);
    Transform();
};


#endif //CARENGINE_TRANSFORM_H
