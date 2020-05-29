#include "Light.h"

Light::Light(const Vector3f& position, const Vector3f& diff, const Vector3f& spec)
: position(position), diffuseColor(diff), specularColor(spec) { }

const Vector3f Light::getPosition() const {
    return position;
}

const Vector3f Light::getDiffuseColor() const {
    return diffuseColor;
}

const Vector3f Light::getSpecularColor() const {
    return specularColor;
}