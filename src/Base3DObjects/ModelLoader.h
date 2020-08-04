//
// Created by menegais1 on 25/07/2020.
//

#ifndef CARENGINE_MODELLOADER_H
#define CARENGINE_MODELLOADER_H


#include <vector>
#include "../Vectors/Vector3.h"
#include "../Base/3D/ObjectFace.h"

struct ObjectInfo {
    std::vector<dvec3> vertices;
    std::vector<dvec3> normals;
    std::vector<dvec3> uv;
    std::vector<ObjectFace> faces;
};


struct FileString {
    std::string file;
    int curPos;
    int _eof;

    void getLine(std::string &s, char delimiter) {
        s = std::string();
        while (file[curPos] != delimiter) {
            s.append(1, file[curPos]);
            curPos++;
        }
        curPos++;
    }

    bool eof() {
        return curPos == _eof;
    }
};

class ModelLoader {
public:
    static ObjectInfo loadObj(std::string filename);

private:

    static std::vector<ObjectFace> readFaces(FileString &file);

    static std::vector<dvec3> readVerticesNormals(FileString &file);

    static std::vector<dvec3> readVertices(FileString &file);

    static std::vector<dvec3> readTextureCoordinates(FileString &file);
};


#endif //CARENGINE_MODELLOADER_H
