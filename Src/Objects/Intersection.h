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

    Intersection();
    Intersection(const Object* obj, Vector3f contact);

    bool didHit();
};

#endif // INTERSECTION_H_INCLUDED