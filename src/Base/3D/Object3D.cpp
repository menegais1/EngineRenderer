//
// Created by menegais1 on 12/07/2020.
//

#include "../../Camera/Camera.h"
#include "Object3D.h"
#include "../../Utilities.h"


Object3D::Object3D(Transform transform, Shader shader) : shader(shader) {
    Model = fMatrix::identity(4);
    this->transform = transform;
}

void Object3D::setCenter(fvec3 center) {
    Model.setCol(center.toVector4(1), 3);
    this->transform.position = center;
}

void Object3D::computeCenter() {
    this->transform.position = fvec3(0, 0, 0);
    for (int i = 0; i < vertices.size(); ++i) {
        this->transform.position.x += vertices[i].x;
        this->transform.position.y += vertices[i].y;
        this->transform.position.z += vertices[i].z;
    }
    this->transform.position = this->transform.position / vertices.size();
    setCenter(this->transform.position);

}

fvec3 Object3D::calculateNormal(int i0, int i1, int i2) {
    fvec3 v0 = vertices[i0];
    fvec3 v1 = vertices[i1];
    fvec3 v2 = vertices[i2];
    fvec3 normal = (v1 - v0).cross(v2 - v0).unit();
    return normal;
}

void Object3D::setNormal(int i, fvec3 normal) {
    if (normals[i].equalZero()) normals[i] = normal;
    else normals[i] = (normals[i] + normal) / 2;
}

void Object3D::render() {
    if (faces.size() == 0) return;
    if (std::abs(transform.rotation.x) >= 360) transform.rotation.x = (int) transform.rotation.x % 360;
    if (std::abs(transform.rotation.y) >= 360) transform.rotation.y = (int) transform.rotation.y % 360;
    if (std::abs(transform.rotation.z) >= 360) transform.rotation.z = (int) transform.rotation.z % 360;

    auto S = fMatrix::scale(transform.scale);
    auto T = fMatrix::translate(transform.position);
    auto Rx = fMatrix::rotateX(transform.rotation.x * PI / 180.0);
    auto Ry = fMatrix::rotateY(transform.rotation.y * PI / 180.0);
    auto Rz = fMatrix::rotateZ(transform.rotation.z * PI / 180.0);
    Model = T * Rz * Ry * Rx * S;
    InvModel = Model.invert();
    fvec3 cameraPos = (InvModel * Camera::getInstance()->center).toVector3();
    int cont = 0;

    shader.activateShader();
    shader.setUniform("UNIFORM_MVP",Camera::getInstance()->Projection * Camera::getInstance()->View * Model);
    shader.setUniform("UNIFORM_InverseModel",Model.invert());
    renderObject->render();
}

void Object3D::setShader(Shader shader){
    this->shader = shader;
    renderObject->shader = shader;
}

void Object3D::setupRendering() {
    renderObject = new ObjectGL(shader, vertices, faces, normals, uvs);
}
