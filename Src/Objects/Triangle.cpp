#include <cmath>

#include "Triangle.h"
#include "../Math/Math.h"

Triangle::Triangle(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& diff, const Vector3f& spec, const Vector3f& amb)
: Object(diff, spec, amb), p1(p1), p2(p2), p3(p3) {
    Vector3f edge1 = p2.subtract(p1);
    Vector3f edge2 = p3.subtract(p1);

    normal = edge1.crossProduct(edge2).normalize();
}

Intersection Triangle::intersects(const Ray& ray) {
    // Möller–Trumbore intersection algorithm.

    Vector3f edge1 = p2.subtract(p1);
    Vector3f edge2 = p3.subtract(p1);

    Vector3f h = ray.direction.crossProduct(edge2);
    float a = edge1.dotProduct(h);
    if (std::fabs(a) < Math::MARGIN_ERROR) {
        return Intersection();
    }

    float f = 1 / a;
    Vector3f s = ray.origin.subtract(p1);
    float u = f * s.dotProduct(h);
    if (u < 0.0f || u > 1.0f) {
        return Intersection();
    }

    Vector3f q = s.crossProduct(edge1);
    float v = f * ray.direction.dotProduct(q);
    if (v < 0.0f || (u + v) > 1.0f) {
        return Intersection();
    }

    // Calculate the t for pi = p + t * d.
    float t = f * edge2.dotProduct(q);

    if (t > Math::MARGIN_ERROR) {
        Vector3f contact = ray.origin.add(ray.direction.multiply(t));
        return Intersection(this, contact, normal);
    } else {
        // Only line interesection.
        return Intersection();
    }
}
