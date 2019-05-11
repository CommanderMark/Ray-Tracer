#ifndef RAYTRACER_H_INCLUDED
#define RAYTRACER_H_INCLUDED

#include <vector>

#include "Math/Vector.h"
#include "Objects/Ray.h"
#include "Objects/Camera.h"

class Object;

class RayTracer {
private:
    Camera cam = Camera(Vector3f::one, Vector3f(0, 1, 0), Vector3f::zero, 90.0f);

    int imageWidth;
    int imageHeight;
    int pixelWidth;
    int pixelHeight;
    float getAspectRatio();

    Vector3f centerOfPlane;
    Vector3f bottomLeftOfPlane;

    Ray getPrimaryRay(int x, int y);
    Vector3f computeRay(const Ray& ray);

public:
    Vector3f backgroundColor;
    Vector3f lightPosition;

    std::vector<Object*> objects;

    RayTracer(const Camera& camera, int imageWidth, int imageHeight, int planeWidth, int planeHeight);

    void rayTrace(const char outputFile[]);
};

#endif // RAYTRACER_H_INCLUDED
