//
// Created by menegais1 on 12/07/2020.
//

#ifndef CARENGINE_OBJECT3D_H
#define CARENGINE_OBJECT3D_H


#include "../CanvasObject.h"
#include "Transform.h"
#include "../../Bitmap/Bitmap.h"
#include "../../Base3DObjects/ModelLoader.h"
#include "../../ObjectGL.h"

class Object3D : public CanvasObject {
private:
    bool showFaceNormals = false;
    bool showVertexNormals = false;
    ObjectGL *renderObject;
    Shader shader;
protected:
    Object3D(Transform transform, Shader shader);

    fMatrix Model;
    fMatrix InvModel;
    std::vector<fvec3> vertices;
    std::vector<ObjectFace> faces;
    std::vector<fvec3> normals;
    std::vector<fvec3> uvs;

    void computeCenter();

    void setCenter(fvec3 center);

    void render() override;

    void setupRendering();

public:
    Transform transform;

    fvec3 calculateNormal(int i0, int i1, int i2);

    void setNormal(int i, fvec3 normal);

};


#endif //CARENGINE_OBJECT3D_H
