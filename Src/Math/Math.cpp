#include <cmath>

#include "Math.h"

Vector3f Math::closestPointOnLine(const Ray& ray, const Vector3f& rayToPoint) {
    // Remember linear algebra? Project the point on ray line.
    Vector3f projectionOfCenterOnLine = ray.direction.multiply(ray.direction.dotProduct(rayToPoint));

    // Add to ray origin to get a point that perpendicularly intersects the ray line and the point.
    Vector3f finalPoint = ray.origin.add(projectionOfCenterOnLine);

    return finalPoint;
}

float Math::degToRad(float degree) {
    return degree * M_PI / 180;
}