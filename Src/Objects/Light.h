#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED

#include "../Math/Vector.h"

class Light {
private:
    Vector3f position;
    Vector3f color;

public:
    Light(const Vector3f& position, const Vector3f& color);

    const Vector3f getPosition() const;
};

#endif // LIGHT_H_INCLUDED