//
// Created by menegais1 on 12/07/2020.
//

#include "../Camera/Camera.h"
#include "Cylinder.h"
#include "../Utilities.h"
#include "../FileManagers/ModelLoader.h"
#include "../FileManagers/FileLoader.h"

Cylinder::Cylinder(Transform transform, Shader shader) : Object3D(transform, shader) {

    ObjectInfo info = ModelLoader::loadObj(FileLoader::getPath("Resources/Meshes/cylinder.obj"));
    vertices = info.vertices;
    faces = info.faces;
    normals = info.normals;
    uvs = info.uv;
    Object3D::setupRendering();
}



