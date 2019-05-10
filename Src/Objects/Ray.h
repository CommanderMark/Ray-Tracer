#ifndef RAY_H_INCLUDED
#define RAY_H_INCLUDED

#include "../Math/Vector.h"

class Ray {
public:
    const Vector3f origin;
    const Vector3f direction;

    Ray(const Vector3f& origin, const Vector3f& direction);
};

#endif // RAY_H_INCLUDED