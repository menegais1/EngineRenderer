//
// Created by menegais1 on 12/07/2020.
//

#ifndef CARENGINE_OBJECT3D_H
#define CARENGINE_OBJECT3D_H


#include "../CanvasObject.h"
#include "Transform.h"
#include "../../Bitmap/Bitmap.h"
#include "../../Base3DObjects/ModelLoader.h"

class Object3D : public CanvasObject {
private:
    bool showFaceNormals = false;
    bool showVertexNormals = false;

protected:
    Object3D(Transform transform);

    dMatrix Model;
    dMatrix InvModel;
    std::vector<dvec3> vertices;
    std::vector<ObjectFace> faces;
    std::vector<dvec3> normals;
    std::vector<dvec3> uvs;

    void computeCenter();

    void setCenter(dvec3 center);

    void render() override;


public:
    Transform transform;

    dvec3 calculateNormal(int i0, int i1, int i2);

    void setNormal(int i, dvec3 normal);

};


#endif //CARENGINE_OBJECT3D_H
