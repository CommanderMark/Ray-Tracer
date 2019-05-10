#include <cmath>

#include "Triangle.h"
#include "../Math/Math.h"

Triangle::Triangle(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& color) : p1(p1), p2(p2), p3(p3) {
    this->color = color;
}

Intersection Triangle::intersects(const Ray& ray) {
    // Get the triangle's plane normal.
    Vector3f p1p2 = p2.subtract(p1);
    Vector3f p1p3 = p3.subtract(p1);;
    Vector3f plane = p1p2.crossProduct(p1p3);

    // Check if ray and plane are parallel.
    float dot = plane.dotProduct(ray.direction);
    if (std::fabs(dot) < Math::MARGIN_ERROR) {
        return Intersection();
    }

    float d = plane.dotProduct(p1);
    float t = (plane.dotProduct(ray.origin) + d) / dot;

    // Check if the triangle is behind the ray.
    if (t < 0) {
        return Intersection();
    }

    // Intersection point.
    Vector3f P = ray.origin.add(ray.direction.multiply(t));

    Vector3f C; // Vector perpendicular to triangle's plane.

    // edge 0
    Vector3f edge1 = p2.subtract(p1);
    Vector3f vp1 = P.subtract(p1);
    C = edge1.crossProduct(vp1);
    if (plane.dotProduct(C) < 0) { return Intersection(); } // P is on the right side

    // edge 1
    Vector3f edge2 = p3.subtract(p2);
    Vector3f vp2 = P.subtract(p2);
    C = edge2.crossProduct(vp2);
    if (plane.dotProduct(C) < 0) { return Intersection(); } // P is on the right side

    // edge 2
    Vector3f edge3 = p1.subtract(p3);
    Vector3f vp3 = P.subtract(p3);
    C = edge3.crossProduct(vp3);
    if (plane.dotProduct(C) < 0) { return Intersection(); } // P is on the right side;

    return Intersection(this, P);
}
