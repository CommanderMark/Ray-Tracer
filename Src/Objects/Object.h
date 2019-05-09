#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "../Math/Vector.h"
#include "Ray.h"
#include "Intersection.h"

class Object {
public:
    Vector3f color;

    virtual Intersection intersects(const Ray& ray)=0;
};

#endif // OBJECT_H_INCLUDED