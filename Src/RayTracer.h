#ifndef RAYTRACER_H_INCLUDED
#define RAYTRACER_H_INCLUDED

#include <vector>

#include "Math/Vector.h"
#include "Objects/Ray.h"
#include "Objects/Camera.h"

class Object;

class RayTracer {
private:
    Camera cam = Camera(Vector3f::zero, Vector3f(0, 1, 0), Vector3f::one);

    float fieldOfViewDeg;
    int imageWidth;
    int imageHeight;

    std::vector<Object*> objects;
    Vector3f backgroundColor;

    float getAspectRatio();

    Ray getPrimaryRay(int x, int y);
    Vector3f computeRay(const Ray& ray);

public:
    void rayTrace();
};

#endif // RAYTRACER_H_INCLUDED
