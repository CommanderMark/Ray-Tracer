#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include "Vector.h"
#include "../Objects/Ray.h"

class Math {
public:
    constexpr static float MARGIN_ERROR = 0.001;

    // Finds the point on a given line (ray) that is closest to a specified point.
    static Vector3f closestPointOnLine(const Ray& ray, const Vector3f& rayToPoint);

    static float degToRad(float degrees);
};

#endif // MATH_H_INCLUDED
