//
// Created by menegais1 on 12/07/2020.
//

#include "Engine.h"


#include "Camera/Camera.h"
#include "Managers/GlobalManager.h"
#include "Engine.h"
#include "Base3DObjects/OpenEndedCylinder.h"
#include "FileManagers/FileLoader.h"
#include <GLFW/glfw3.h>

float Engine::calculateAngularVelocity(float rpm) {
    return (2.0 * PI * rpm) / 60.0;
}

fvec3 Engine::calculatePistonPinPosition(Object3D *pin, Object3D *piston, float radius, float angle, float l) {
    fvec3 pinPosition = pin->transform.position;
    pinPosition.y =
            radius * std::cos(angle) + std::sqrt((l * l) - ((radius * radius) * (std::sin(angle) * std::sin(angle))));
    return pinPosition;
}

fvec3 Engine::calculatePistonPosition(Object3D *piston, float radius, float angle) const {
    fvec3 pinOnCrankPosition = piston->transform.position;
    pinOnCrankPosition.x = crank->transform.position.x + radius * cos(angle + 90 * PI / 180);
    pinOnCrankPosition.y = crank->transform.position.y + radius * sin(angle + 90 * PI / 180);

    return pinOnCrankPosition;
}

fvec3 Engine::calculatePistonRotation(Object3D *piston, fvec3 pinPosition, fvec3 pinOnCrankPosition) {
    fvec2 vec = pinPosition - pinOnCrankPosition;
    float angle = std::atan2(vec.y, vec.x);
    fvec3 rotation = piston->transform.rotation;
    rotation.z = angle * 180.0 / PI + 90;
    return rotation;
};

void Engine::render() {
    angularVelocity = calculateAngularVelocity(rpm);
    crank->transform.rotation.z += angularVelocity * GlobalManager::getInstance()->deltaTime;
    float radius = crank->transform.scale.z;

    for (int i = 0; i < pistons.size(); ++i) {
        float angle = crank->transform.rotation.z * PI / 180.0;
        if (i % 2 != 0) angle = angle + 180 * PI / 180.0;
        float l = pistons[i]->transform.scale.y;
        fvec3 pinPosition = calculatePistonPinPosition(pistonPins[i], pistons[i], radius, angle, l) +
                            fvec3(0, crank->transform.position.y, 0);
        fvec3 pistonPosition = calculatePistonPosition(pistons[i], radius, angle);
        fvec3 pistonRotation = calculatePistonRotation(pistons[i], pinPosition, pistonPosition);
        pistons[i]->transform.position = ((pinPosition + pistonPosition) / 2);
        pistons[i]->transform.rotation = pistonRotation;
        pistonPins[i]->transform.position = pinPosition;
    }
    shader.activateShader();
    shader.setUniform("UNIFORM_lightPosition", fvec3(0, 2, 0));
    Object3D::render();
}

Engine::Engine(Transform transform, Shader shader) : Object3D(transform, shader) {
    rpm = 100;
    Shader goraudShader(Shader::createVertexShader(FileLoader::getPath("Resources/Shaders/Goraud/GoraudVertex.glsl")),
                        Shader::createFragmentShader(FileLoader::getPath("Resources/Shaders/Goraud/GoraudFragment.glsl")));
    shader = goraudShader;
    this->crank = new Cylinder(Transform(fvec3(4, 2, 0), fvec3(90, 0, 0), fvec3(0.2, 2, 0.2)), shader);
    pistons.push_back(new Cylinder(Transform(crank->transform.position + fvec3(0, crank->transform.scale.z + 1,
                                                                               crank->transform.position.z +
                                                                               crank->transform.scale.y / 2),
                                             fvec3(0, 0, 0), fvec3(0.1, 2, 0.1)), shader));
    pistonPins.push_back(new Cylinder(Transform(crank->transform.position + fvec3(0, crank->transform.scale.z + 1,
                                                                                  crank->transform.position.z +
                                                                                  crank->transform.scale.y / 2),
                                                fvec3(0, 0, 0), fvec3(0.3, 0.5, 0.3)), shader));

    float radius = crank->transform.scale.z;
    float l = pistons[0]->transform.scale.y;
    fvec3 pos = calculatePistonPinPosition(pistons[0], pistonPins[0], radius, 0, l);
    shirts.push_back(new OpenEndedCylinder(Transform(pos + fvec3(0, crank->transform.position.y, 0),
                                                     fvec3(0, 0, 180), fvec3(0.32, 0.6, 0.32)), shader));

    pistons.push_back(new Cylinder(
            Transform(crank->transform.position + fvec3(0, crank->transform.scale.z + 1, crank->transform.position.z),
                      fvec3(0, 0, 0), fvec3(0.1, 2, 0.1)), shader));
    pistonPins.push_back(new Cylinder(
            Transform(crank->transform.position + fvec3(0, crank->transform.scale.z + 1, crank->transform.position.z),
                      fvec3(0, 0, 0), fvec3(0.3, 0.5, 0.3)), shader));
    pos = calculatePistonPinPosition(pistons[1], pistonPins[1], radius, 0, l);
    shirts.push_back(new OpenEndedCylinder(Transform(pos + fvec3(0, crank->transform.position.y, 0),
                                                     fvec3(0, 0, 180), fvec3(0.32, 0.6, 0.32)), shader));

    pistons.push_back(new Cylinder(Transform(crank->transform.position + fvec3(0, crank->transform.scale.z + 1,
                                                                               crank->transform.position.z -
                                                                               crank->transform.scale.y / 2),
                                             fvec3(0, 0, 0), fvec3(0.1, 2, 0.1)), shader));
    pistonPins.push_back(new Cylinder(Transform(crank->transform.position + fvec3(0, crank->transform.scale.z + 1,
                                                                                  crank->transform.position.z -
                                                                                  crank->transform.scale.y / 2),
                                                fvec3(0, 0, 0), fvec3(0.3, 0.5, 0.3)), shader));
    pos = calculatePistonPinPosition(pistons[2], pistonPins[2], radius, 0, l);
    shirts.push_back(new OpenEndedCylinder(Transform(pos + fvec3(0, crank->transform.position.y, 0),
                                                     fvec3(0, 0, 180), fvec3(0.32, 0.6, 0.32)), shader));

}

void Engine::keyboard(int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_1) {
        pistonQuantity = 1;
        for (int i = 0; i < 1; ++i) {
            pistons[i]->setActive(showPistons);
            pistonPins[i]->setActive(showPistonPins);
            shirts[i]->setActive(showShirts);
        }
        for (int i = 1; i < pistons.size(); ++i) {
            pistons[i]->setActive(false);
            pistonPins[i]->setActive(false);
            shirts[i]->setActive(false);
        }
    }
    if (key == GLFW_KEY_2) {
        pistonQuantity = 2;
        for (int i = 0; i < 2; ++i) {
            pistons[i]->setActive(showPistons);
            pistonPins[i]->setActive(showPistonPins);
            shirts[i]->setActive(showShirts);
        }
        for (int i = 2; i < pistons.size(); ++i) {
            pistons[i]->setActive(false);
            pistonPins[i]->setActive(false);
            shirts[i]->setActive(false);
        }
    }
    if (key == GLFW_KEY_3) {
        pistonQuantity = 3;
        for (int i = 0; i < 3; ++i) {
            pistons[i]->setActive(showPistons);
            pistonPins[i]->setActive(showPistonPins);
            shirts[i]->setActive(showShirts);
        }
        for (int i = 3; i < pistons.size(); ++i) {
            pistons[i]->setActive(false);
            pistonPins[i]->setActive(false);
            shirts[i]->setActive(false);
        }
    }

    if (key == GLFW_KEY_Z) {
        showPistons = !showPistons;
        for (int i = 0; i < pistonQuantity; ++i) {
            pistons[i]->setActive(showPistons);
        }
    }
    if (key == GLFW_KEY_X) {
        showPistonPins = !showPistonPins;
        for (int i = 0; i < pistonQuantity; ++i) {
            pistonPins[i]->setActive(showPistonPins);
        }
    }
    if (key == GLFW_KEY_C) {
        showShirts = !showShirts;
        for (int i = 0; i < pistonQuantity; ++i) {
            shirts[i]->setActive(showShirts);
        }
    }
    if (key == GLFW_KEY_V) {
        showCrank = !showCrank;
        crank->setActive(showCrank);

    }

//    if (key == GLFW_KEY_N) {
//        showVertexNormals = !showVertexNormals;
//        for (int i = 0; i < pistons.size(); ++i) {
//            pistons[i]->showVertexNormals = showVertexNormals;
//            shirts[i]->showVertexNormals = showVertexNormals;
//            pistonPins[i]->showVertexNormals = showVertexNormals;
//        }
//        crank->showVertexNormals = showVertexNormals;
//    }
//    if (key == GLFW_KEY_F) {
//        showFaceNormals = !showFaceNormals;
//        for (int i = 0; i < pistons.size(); ++i) {
//            pistons[i]->showFaceNormals = showFaceNormals;
//            shirts[i]->showFaceNormals = showFaceNormals;
//            pistonPins[i]->showFaceNormals = showFaceNormals;
//        }
//        crank->showFaceNormals = showFaceNormals;
//    }
}

