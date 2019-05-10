#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "../Math/Vector.h"
#include "Object.h"

class Triangle : public Object {
private:
    Vector3f p1;
    Vector3f p2;
    Vector3f p3;

public:
    Triangle(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& color);
    Intersection intersects(const Ray& ray) override;
};

#endif // TRIANGLE_H_INCLUDED
