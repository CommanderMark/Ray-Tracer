#ifndef RAYTRACER_H_INCLUDED
#define RAYTRACER_H_INCLUDED

#include <vector>

#include "Math/Vector.h"
#include "Objects/Ray.h"

class Object;

class RayTracer {
private:
    float fieldOfViewDeg;
    int imageWidth;
    int imageHeight;

    std::vector<Object*> objects;
    Vector3f backgroundColor;

    float getAspectRatio();

    Ray getPrimaryRay(int x, int y);
    void rayTrace();
    Vector3f computeRay(const Ray& ray);
};

#endif // RAYTRACER_H_INCLUDED