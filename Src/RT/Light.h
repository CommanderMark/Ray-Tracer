#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED

#include "../Math/Vector.h"

class Light {
private:
    Vector3f position;
    Vector3f diffuseColor;
    Vector3f specularColor;

public:
    Light(const Vector3f& position, const Vector3f& diff, const Vector3f& spec);

    const Vector3f getPosition() const;

    const Vector3f getDiffuseColor() const;
    const Vector3f getSpecularColor() const;
};

#endif // LIGHT_H_INCLUDED