#ifndef RAYTRACER_H_INCLUDED
#define RAYTRACER_H_INCLUDED

#include <vector>

#include "Math/Vector.h"
#include "Objects/Ray.h"
#include "Objects/Camera.h"
#include "Objects/Intersection.h"

class Object;
class Light;

class RayTracer {
private:
    Camera cam = Camera(Vector3f::one, Vector3f(0, 1, 0), Vector3f::zero, 90.0f);

    int imageWidth;
    int imageHeight;
    int pixelWidth;
    int pixelHeight;
    float getAspectRatio() const;

    Vector3f centerOfPlane;
    Vector3f bottomLeftOfPlane;

    const Ray getPrimaryRay(int x, int y) const;
    const Vector3f computeRay(const Ray& ray) const;
    const Vector3f getPhongShading(const Ray& primaryRay, const Ray& shadowRay, const Light* light, const Intersection& intersect) const;

public:
    Vector3f backgroundColor;

    std::vector<Object*> objects;
    std::vector<Light*> lights;

    RayTracer(const Camera& camera, int imageWidth, int imageHeight, int planeWidth, int planeHeight);
    ~RayTracer();

    void rayTrace(const char outputFile[]) const;
};

#endif // RAYTRACER_H_INCLUDED
