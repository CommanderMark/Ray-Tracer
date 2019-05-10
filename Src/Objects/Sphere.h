#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include "Object.h"

class Sphere : public Object {
private:
    Vector3f center;
    float radius;

public:
    Sphere(const Vector3f& center, float radius, const Vector3f& color);

    Intersection intersects(const Ray& ray) override;
};

#endif // SPHERE_H_INCLUDED
