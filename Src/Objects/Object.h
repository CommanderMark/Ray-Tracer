#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "../Math/Vector.h"
#include "Ray.h"
#include "Intersection.h"

class Object {
private:
    Vector3f diffuseColor;
    Vector3f specularColor;
    Vector3f ambientColor;

public:
    Object(const Vector3f& diff, const Vector3f& spec, const Vector3f& amb);
    virtual ~Object()=default;

    const Vector3f getDiffuseColor() const;
    const Vector3f getSpecularColor() const;
    const Vector3f getAmbientColor() const;

    virtual Intersection intersects(const Ray& ray)=0;
};

#endif // OBJECT_H_INCLUDED
