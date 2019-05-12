#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED

#include "Object.h"

class Plane : public Object {
private:
    Vector3f center;
    Vector3f normal;

public:
    Plane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& diff, const Vector3f& spec, const Vector3f& amb, float shininessCoe);

    Intersection intersects(const Ray& ray) override;
};

#endif // PLANE_H_INCLUDED
