#include <cmath>

#include "Sphere.h"
#include "../Math/Math.h"

Sphere::Sphere(Vector3f center, float radius, Vector3f color) : center(center), radius(radius) {
    this->color = color;
}

Intersection Sphere::intersects(const Ray& ray) {
    // TODO: remove all of this and replace it with the commented out code.
    Vector3f deltap = ray.origin.subtract(center);
    float a = ray.direction.dotProduct(ray.direction);
    float b = deltap.dotProduct(ray.direction) * 2;
    float c = deltap.dotProduct(deltap) - (radius * radius);

    double disc = b * b - 4 * a * c;
    if (disc < 0) {
        return Intersection(); // No intersection.
    }

    disc = sqrt(disc);

    double q;
    if (b < 0) {
        q = (-b - disc) * 0.5;
    } else {
        q = (-b + disc) * 0.5;
    }

    double r1 = q / a;
    double r2 = c / q;

    if (r1 > r2) {
        double tmp = r1;
        r1 = r2;
        r2 = tmp;
    }

    double distance = r1;
    if (distance < 0) {
        distance = r2;
    }

    if (distance < 0 || isnan(distance)) {
        return Intersection(); // No intersection.
    }

    Vector3f point = ray.origin.add (ray.direction.multiply(distance));
//    Vector normal = (point - center).normalize();
//
//    normal = material->modifyNormal(normal, point);

    // Normal needs to be flipped if this is a refractive ray.
//    if (ray.direction.dotProduct(normal) > 0) {
//        normal = normal * -1;
//    }

    return Intersection(this, point);
//    float radiusSquared = radius * radius;
//
//    // Vector from ray origin to the center of the sphere.
//    Vector3f rayToCenter = center.subtract(ray.origin);
//
//    // Is the sphere center behind the ray?
//    if (rayToCenter.dotProduct(ray.direction) < 0) {
//        // Is there an intersection?
//        float distanceSquared = rayToCenter.lengthSquared();
//
//        if (distanceSquared > radiusSquared) {
//            // Miss.
//            return Intersection();
//        } else if (std::abs(distanceSquared - radiusSquared) < Math::MARGIN_ERROR) {
//            // Ray origin is right on the sphere.
//            return Intersection(this, ray.origin);
//        } else {
//            // We're inside the sphere, yikes.
//
//            // Get the point on the ray closest to the center.
//            Vector3f projectedPoint = Math::closestPointOnLine(ray, rayToCenter);
//
//            float distance = std::sqrtf(radiusSquared - projectedPoint.subtract(center).lengthSquared());
//            float distanceToIntersectPoint = distance - projectedPoint.subtract(ray.origin).length();
//            Vector3f intersectPoint = ray.origin.add(ray.direction.multiply(distanceToIntersectPoint));
//
//            return Intersection(this, intersectPoint);
//        }
//    } else {
//        // Center of sphere is in front of the ray.
//        Vector3f projectedPoint = Math::closestPointOnLine(ray, rayToCenter);
//        if (center.subtract(projectedPoint).lengthSquared() > radiusSquared) {
//            // Miss.
//            return Intersection();
//        } else  {
//            float distance = std::sqrtf(radiusSquared - projectedPoint.subtract(center).lengthSquared());
//            float distanceToIntersectPoint = 0.0f;
//
//            if (rayToCenter.lengthSquared() > radiusSquared) {
//                // Ray is outside sphere.
//                distanceToIntersectPoint = projectedPoint.subtract(ray.origin).length() - distance;
//            } else {
//                // Ray is inside sphere.
//                distanceToIntersectPoint = projectedPoint.subtract(ray.origin).length() + distance;
//            }
//
//            Vector3f intersectPoint = ray.origin.add(ray.direction.multiply(distanceToIntersectPoint));
//            return Intersection(this, intersectPoint);
//        }
//    }
}
