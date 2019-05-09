#ifndef RAY_H_INCLUDED
#define RAY_H_INCLUDED

#include "../Math/Vector.h"

class Ray {
public:
    Vector3f origin;
    Vector3f direction;

    Ray(Vector3f& origin, Vector3f& direction);
};

#endif // RAY_H_INCLUDED