#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include "Object.h"

class Sphere : public Object {
private:
    Vector3f center;
    float radius;

public:
    Sphere(const Vector3f& center, float radius, const Vector3f& diff, const Vector3f& spec = Vector3f::zero, const Vector3f& amb = Vector3f::zero);

    Intersection intersects(const Ray& ray) override;
    const Vector3f getNormal(const Vector3f& point);
};

#endif // SPHERE_H_INCLUDED
