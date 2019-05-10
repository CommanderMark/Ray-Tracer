#include <cmath>

#include "Sphere.h"
#include "../Math/Math.h"

Sphere::Sphere(Vector3f& center, float radius, Vector3f color) : center(center), radius(radius) {
    this->color = color;
}

Intersection Sphere::intersects(const Ray& ray) {
    float radiusSquared = radius * radius;

    // Vector from ray origin to the center of the sphere.
    Vector3f rayToCenter = center.subtract(ray.origin);

    // Is the sphere center behind the ray?
    if (rayToCenter.dotProduct(ray.direction) < 0) {
        // Is there an intersection?
        float distanceSquared = rayToCenter.lengthSquared();

        if (distanceSquared > radiusSquared) {
            // Miss.
            return Intersection();
        } else if (std::abs(distanceSquared - radiusSquared) < Math::MARGIN_ERROR) {
            // Ray origin is right on the sphere.
            return Intersection(this, ray.origin);
        } else {
            // We're inside the sphere, yikes.

            // Get the point on the ray closest to the center.
            Vector3f projectedPoint = Math::closestPointOnLine(ray, rayToCenter);

            float distance = std::sqrtf(radiusSquared - projectedPoint.subtract(center).lengthSquared());
            float distanceToIntersectPoint = distance - projectedPoint.subtract(ray.origin).length();
            Vector3f intersectPoint = ray.origin.add(ray.direction.multiply(distanceToIntersectPoint));

            return Intersection(this, intersectPoint);
        }
    } else {
        // Center of sphere is in front of the ray.
        Vector3f projectedPoint = Math::closestPointOnLine(ray, rayToCenter);
        if (center.subtract(projectedPoint).lengthSquared() > radiusSquared) {
            // Miss.
            return Intersection();
        } else  {
            float distance = std::sqrtf(radiusSquared - projectedPoint.subtract(center).lengthSquared());
            float distanceToIntersectPoint = 0.0f;

            if (rayToCenter.lengthSquared() > radiusSquared) {
                // Ray is outside sphere.
                distanceToIntersectPoint = projectedPoint.subtract(ray.origin).length() - distance;
            } else {
                // Ray is inside sphere.
                distanceToIntersectPoint = projectedPoint.subtract(ray.origin).length() + distance;
            }

            Vector3f intersectPoint = ray.origin.add(ray.direction.multiply(distanceToIntersectPoint));
            return Intersection(this, intersectPoint);
        }
    }
}