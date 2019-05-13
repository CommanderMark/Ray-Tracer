#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "../Math/Vector.h"
#include "Object.h"

class Triangle : public Object {
private:
    Vector3f p1;
    Vector3f p2;
    Vector3f p3;
    Vector3f normal;

public:
    Triangle(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& diff, const Vector3f& spec, const Vector3f& amb, float shininessCoe);
    
    Intersection intersects(const Ray& ray) const override;
};

#endif // TRIANGLE_H_INCLUDED
