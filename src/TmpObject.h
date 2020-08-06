//
// Created by Roberto on 08/04/20.
//

#ifndef RENDERERENGINE_TMPOBJECT_H
#define RENDERERENGINE_TMPOBJECT_H


#include "Base/CanvasObject.h"
#include "Backend/ObjectGL.h"

class TmpObject : public CanvasObject {
public:
    bool show_demo_window = false;
    bool show_another_window = false;
    ObjectGL *temp;
    Shader shader;
    Texture2D texture2D;
    void render() override;

    TmpObject(Shader shader);
};


#endif //RENDERERENGINE_TMPOBJECT_H
