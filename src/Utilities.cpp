#include "Utilities.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "Vectors/Vector2.h"
#include "Vectors/Vector3.h"

bool isPointInsideBounds(fvec2 point, fvec2 position, fvec2 scale) {
    return point.x < position.x + scale.x && point.x > position.x && point.y < position.y + scale.y &&
           point.y > position.y;
}

int isLeft(fvec3 P0, fvec3 P1, fvec3 P2) {
    return ((P1.x - P0.x) * (P2.y - P0.y) - (P2.x - P0.x) * (P1.y - P0.y));
}


//Crossing number point in polygon algorithm implementation
//This code is patterned after [Franklin, 2000]
//Taken from http://geomalgorithms.com/a03-_inclusion.html
bool isPointInsidePolygon(fvec2 P, std::vector<fvec3> vertices, int n) {
    int cn = 0; // the  crossing number counter

    // loop through all edges of the polygon
    for (int i = 0; i < n; i++) {
        // edge from V[i]  to V[i+1]
        if (((vertices[i].y <= P.y) && (vertices[i + 1].y > P.y)) // an upward crossing
            || ((vertices[i].y > P.y) && (vertices[i + 1].y <= P.y))) { // a downward crossing
            // compute  the actual edge-ray intersect x-coordinate
            float vt = (float) (P.y - vertices[i].y) / (vertices[i + 1].y - vertices[i].y);
            if (P.x < vertices[i].x + vt * (vertices[i + 1].x - vertices[i].x)) // P.x < intersect
                ++cn;                                                           // a valid crossing of y=P.y right of P.x
        }
    }
    return (cn & 1); // 0 if even (out), and 1 if  odd (in)
}

bool leftMouseDown(int button, int state) {
    return button == MouseButton::Left && state == MouseState::Down;
}

bool leftMouseUp(int button, int state) {
    return button == MouseButton::Left && state == MouseState::Up;
}

fvec3 lerp(fvec3 x0, fvec3 x1, float t) {
    return x0 * (1 - t) + x1 * t;
}

fvec4 lerp(fvec4 x0, fvec4 x1, float t) {
    return x0 * (1 - t) + x1 * t;
}

float lerp(float v0, float v1, float t) {
    return v0 * (1 - t) + v1 * t;
}

float clamp(float v0, float v1, float v) {
    if (v < v0) return v0;
    if (v > v1) return v1;
    return v;
}

float round(float v0, float v1, float v) {
    float distV0 = abs(v - v0);
    float distV1 = abs(v - v1);
    if (distV0 < distV1) return v0;
    if (distV1 > distV0) return v1;
    return v1;

}

std::vector<fvec3> generateCircle(fvec3 center, fvec3 scale, float sides) {
    float ang, x1, y1;
    float inc = PI_2 / sides;
    std::vector<fvec3> vertices;
    for (ang = 0; ang < PI_2; ang += inc) {
        float x = (cos(ang) * scale.x);
        float y = (sin(ang) * scale.y);
        vertices.push_back({center.x + x, center.y + y, center.z});
    }
    vertices.push_back(vertices[0]);
    return vertices;
}

bool isPointInsideCircle(fvec2 point, fvec2 center, float radius) {
    return std::pow(point.x - center.x, 2) + std::pow(point.y - center.y, 2) <= std::pow(radius, 2);
}

fvec3 HSVtoRGB(fvec3 hsv) {

    double r = 0, g = 0, b = 0;

    if (hsv.y == 0) {
        r = hsv.z;
        g = hsv.z;
        b = hsv.z;
    } else {
        int i;
        double f, p, q, t;

        if (hsv.x == 360)
            hsv.x = 0;
        else
            hsv.x = hsv.x / 60;

        i = (int) hsv.x;
        f = hsv.x - i;

        p = hsv.z * (1.0 - hsv.x);
        q = hsv.z * (1.0 - (hsv.x * f));
        t = hsv.z * (1.0 - (hsv.x * (1.0 - f)));

        switch (i) {
            case 0:
                r = hsv.z;
                g = t;
                b = p;
                break;

            case 1:
                r = q;
                g = hsv.z;
                b = p;
                break;

            case 2:
                r = p;
                g = hsv.z;
                b = t;
                break;

            case 3:
                r = p;
                g = q;
                b = hsv.z;
                break;

            case 4:
                r = t;
                g = p;
                b = hsv.z;
                break;

            default:
                r = hsv.z;
                g = p;
                b = q;
                break;
        }

    }

    return fvec3(r, g, b);
}

fvec3 RandomColorGenerator(float saturation, float brightness) {
    double rand = (std::rand() % 1000) / 1000.0;
    rand = std::min(360.0, rand * 360);
    return HSVtoRGB(fvec3(rand, saturation, brightness));
}

fvec2 getMaximumAbsValue(std::vector<fvec2> values) {
    fvec2 max = fvec2(std::abs(values[0].x), std::abs(values[0].y));
    for (int i = 0; i < values.size(); ++i) {
        fvec2 cur = values[i];
        if (std::abs(cur.x) > max.x) max.x = std::abs(cur.x);
        if (std::abs(cur.y) > max.y) max.y = std::abs(cur.y);
    }
    return max;
}

fvec2 getMaximumValue(std::vector<fvec2> values) {
    fvec2 max = fvec2(values[0].x, values[0].y);
    for (int i = 0; i < values.size(); ++i) {
        fvec2 cur = values[i];
        if (cur.x > max.x) max.x = cur.x;
        if (cur.y > max.y) max.y = cur.y;
    }
    return max;
}

fvec2 getMinimumValue(std::vector<fvec2> values) {
    fvec2 min = fvec2(values[0].x, values[0].y);
    for (int i = 0; i < values.size(); ++i) {
        fvec2 cur = values[i];
        if (cur.x < min.x) min.x = cur.x;
        if (cur.y < min.y) min.y = cur.y;
    }
    return min;
}

fvec2 rotatePoint2D(fvec2 point, float angle) {
    fvec2 rotatedPoint;
    rotatedPoint.x = std::cos(angle) * point.x - std::sin(angle) * point.y;
    rotatedPoint.y = std::sin(angle) * point.x + std::cos(angle) * point.y;
    return rotatedPoint;

}