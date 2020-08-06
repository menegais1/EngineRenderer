//
// Created by menegais1 on 25/07/2020.
//

#include "OpenEndedCylinder.h"
#include "../Base/3D/Transform.h"
#include "../FileManagers/ModelLoader.h"
#include "../FileManagers/FileLoader.h"


OpenEndedCylinder::OpenEndedCylinder(Transform transform, Shader shader) : Object3D(transform, shader) {
    ObjectInfo info = ModelLoader::loadObj(FileLoader::getPath("Resources/Meshes/open_cylinder.obj"));
    vertices = info.vertices;
    faces = info.faces;
    normals = info.normals;
    uvs = info.uv;
    Object3D::setupRendering();
}

