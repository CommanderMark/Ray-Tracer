#include "Object.h"

Object::Object(const Vector3f& diff, const Vector3f& spec, const Vector3f& amb)
: diffuseColor(diff), specularColor(spec), ambientColor(amb) { }

const Vector3f Object::getDiffuseColor() const {
    return diffuseColor;
}

const Vector3f Object::getSpecularColor() const {
    return specularColor;
}

const Vector3f Object::getAmbientColor() const {
    return ambientColor;
}