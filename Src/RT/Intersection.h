#ifndef INTERSECTION_H_INCLUDED
#define INTERSECTION_H_INCLUDED

#include "../Math/Vector.h"

class Object;

class Intersection {
private:
    bool hit;

public:
    const Object* obj;
    Vector3f contact;
    Vector3f normal;

    Intersection();
    Intersection(const Object* obj, const Vector3f& contact, const Vector3f& surfaceNormal);

    bool didHit();
};

#endif // INTERSECTION_H_INCLUDED