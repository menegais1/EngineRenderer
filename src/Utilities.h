///Utilities file, has some common structs and functions used in the program

#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include "Vectors/Vector2.h"
#include "Vectors/Vector3.h"
#include "Vectors/Vector4.h"

#define PI        3.14159265358979323846    /* pi */
#define PI_2        2 * PI   /* pi */

enum Channel {
    Red = 0,
    Green = 1,
    Blue = 2,
    Alpha = 3
};

enum MouseButton {
    Left = 0,
    ScrollClick = 1,
    Right = 2,
    ScrollUp = 3,
    ScrollDown = 4
};

enum MouseState {
    Down = 0,
    Up = 1,
    None = -2
};

bool isPointInsideBounds(fvec2 point, fvec2 position, fvec2 scale);

bool isPointInsideCircle(fvec2 point, fvec2 center, float radius);

int isLeft(fvec3 P0, fvec3 P1, fvec3 P2);

bool isPointInsidePolygon(fvec2 P, std::vector<fvec3> vertices, int n);

std::vector<fvec3> generateSquare(fvec3 center, fvec3 scale);

std::vector<fvec3> generateCircle(fvec3 center, fvec3 scale, float sides);

std::vector<fvec3> generateTriangle(fvec3 center, fvec3 scale);

std::vector<fvec3> generatePentagon(fvec3 center, fvec3 scale);

std::vector<fvec3> generateHexagon(fvec3 center, fvec3 scale);

fvec2 getMaximumAbsValue(std::vector<fvec2> values);

fvec2 getMaximumValue(std::vector<fvec2> values);

fvec2 getMinimumValue(std::vector<fvec2> values);

bool leftMouseDown(int button, int state);

bool leftMouseUp(int button, int state);

fvec3 lerp(fvec3 x0, fvec3 x1, float t);

fvec4 lerp(fvec4 x0, fvec4 x1, float t);

float lerp(float v0, float v1, float t);

float clamp(float v0, float v1, float v);

float round(float v0, float v1, float v);

fvec3 RandomColorGenerator(float saturation, float brightness);

fvec3 HSVtoRGB(fvec3 hsv);

fvec2 rotatePoint2D(fvec2 point, float angle);

#endif
