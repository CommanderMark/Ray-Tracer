#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include "Object.h"

class Sphere : public Object {
private:
    float radius;

public:
    Vector3f center;
    Sphere(Vector3f center, float radius, Vector3f color);

    Intersection intersects(const Ray& ray) override;
};

#endif // SPHERE_H_INCLUDED
