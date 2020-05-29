#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "../Math/Vector.h"
#include "../RT/Ray.h"
#include "../RT/Intersection.h"

class Object {
private:
    Vector3f diffuseColor;
    Vector3f specularColor;
    Vector3f ambientColor;
    float shininessCoe;

public:
    Object(const Vector3f& diff, const Vector3f& spec, const Vector3f& amb, float shininessCoe);
    virtual ~Object()=default;

    const Vector3f getDiffuseColor() const;
    const Vector3f getSpecularColor() const;
    const Vector3f getAmbientColor() const;
    float getShineCoefficient() const;

    virtual Intersection intersects(const Ray& ray) const=0;
};

#endif // OBJECT_H_INCLUDED
