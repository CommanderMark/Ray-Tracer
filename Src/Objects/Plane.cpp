#include <cmath>

#include "Plane.h"
#include "../Math/Math.h"

Plane::Plane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& diff, const Vector3f& spec, const Vector3f& amb) : Object(diff, spec, amb) {
    Vector3f edge1 = p2.subtract(p1);
    Vector3f edge2 = p3.subtract(p1);

    normal = edge1.crossProduct(edge2).normalize();
    center = p1;
}

Intersection Plane::intersects(const Ray& ray) {
    float denom = normal.dotProduct(ray.direction);

    if (std::fabs(denom) > Math::MARGIN_ERROR) {
        float t = center.subtract(ray.origin).dotProduct(normal) / denom;
        if (t > Math::MARGIN_ERROR) {
            Vector3f contact = ray.origin.add(ray.direction.multiply(t));
            return Intersection(this, contact, normal);
        }
    }

    return Intersection();
}