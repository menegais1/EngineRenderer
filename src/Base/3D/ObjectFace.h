//
// Created by Roberto on 08/04/20.
//

#ifndef RENDERERENGINE_OBJECTFACE_H
#define RENDERERENGINE_OBJECTFACE_H


#include "../../Vectors/Vector3.h"

class ObjectFace {
public:
    ivec3 vertices;
    ivec3 normals;
    ivec3 uv;

public:
    ObjectFace(const ivec3 &vertices, const ivec3 &normals, const ivec3 &uv);

};


#endif //RENDERERENGINE_OBJECTFACE_H
