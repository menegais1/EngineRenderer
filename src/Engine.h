//
// Created by menegais1 on 12/07/2020.
//

#ifndef CARENGINE_ENGINE_H
#define CARENGINE_ENGINE_H


#include "Base3DObjects/Cylinder.h"

class Engine : public Object3D {
public:

    Engine(Transform transform,Shader shader, Cylinder *crank);

    Object3D *crank;
    std::vector<Object3D *> pistonPins;
    std::vector<Object3D *> pistons;
    std::vector<Object3D *> shirts;
    float rpm;

    void keyboard(int key, int scancode, int action, int mods) override;

private:
    bool showFaceNormals = false;
    bool showVertexNormals = false;
    bool showShirts = true;
    bool showPistons = true;
    bool showPistonPins = true;
    bool showCrank = true;

    float angularVelocity;

    void render() override;

    int pistonQuantity = 1;

    float calculateAngularVelocity(float rpm);

    fvec3 calculatePistonPinPosition(Object3D *pin, Object3D *piston, float radius, float angle, float l);

    fvec3 calculatePistonPosition(Object3D *piston, float radius, float angle) const;

    fvec3 calculatePistonRotation(Object3D *piston, fvec3 pinPosition, fvec3 pinOnCrankPosition);
};


#endif //CARENGINE_ENGINE_H
