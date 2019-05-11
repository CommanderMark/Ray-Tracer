#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED

#include "Object.h"

class Plane : public Object {
private:
    Vector3f normal;

public:
    Plane(const Vector3f& normal, const Vector3f& color);

    Intersection intersects(const Ray& ray) override;
};

#endif // PLANE_H_INCLUDED