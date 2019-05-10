#include <cmath>

#include "RayTracer.h"
#include "Objects/Intersection.h"
#include "Objects/Object.h"

float RayTracer::getAspectRatio() {
    return imageWidth / (float)imageHeight;
}

Ray RayTracer::getPrimaryRay(int x, int y) {
    float rayX = (2 * ((x + 0.5) / imageWidth) - 1) * std::tan(fieldOfViewDeg / 2 * M_PI / 180) * getAspectRatio();
    float rayY = (1 - 2 * ((y + 0.5) / imageHeight)) * std::tan(fieldOfViewDeg / 2 * M_PI / 180);

    Vector3f origin = Vector3f::zero;
    Vector3f direction = Vector3f(rayX, rayY, -1).subtract(origin).normalize();

    return Ray(origin, direction);
}

void RayTracer::rayTrace() {
    fieldOfViewDeg = 90;
    imageWidth = 720;
    imageHeight = 480;
    backgroundColor = Vector3f::zero; // Black.

    Vector3f finalImage[imageWidth * imageHeight];

    for (int x = 1; x <= imageWidth; x++) {
        for (int y = 1; y <= imageHeight; y++) {
            Ray primaryRay = getPrimaryRay(x, y);
            Vector3f finalColor = computeRay(primaryRay);
            finalImage[(x - 1) + (y - 1)] = finalColor;
        }
    }
}

Vector3f RayTracer::computeRay(const Ray& ray) {
    // TODO: Add a cache to speed this up when there's high spatial locality.
    float closestContactSquared = INFINITY;
    Intersection closestIntersect = Intersection();
    for (int i = 0; i < (int)objects.size(); i++) {
        Intersection intersect = objects[i]->intersects(ray);
        if (intersect.didHit()) {
            // Check that it's the closest intersection so far.
            float distanceSquared = intersect.contact.subtract(ray.origin).lengthSquared();
            if (distanceSquared < closestContactSquared) {
                closestContactSquared = distanceSquared;
                closestIntersect = intersect;
            }
        }
    }

    // TODO: Shadow rays god dammit.
    if (closestIntersect.didHit()) {
        return closestIntersect.obj->color;
    }

    return backgroundColor;
}