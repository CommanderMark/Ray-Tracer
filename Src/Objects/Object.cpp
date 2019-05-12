#include "Object.h"

Object::Object(const Vector3f& diff, const Vector3f& spec, const Vector3f& amb, float shininessCoe)
: diffuseColor(diff), specularColor(spec), ambientColor(amb), shininessCoe(shininessCoe) { }

const Vector3f Object::getDiffuseColor() const {
    return diffuseColor;
}

const Vector3f Object::getSpecularColor() const {
    return specularColor;
}

const Vector3f Object::getAmbientColor() const {
    return ambientColor;
}

float Object::getShineCoefficient() const {
    return shininessCoe;
}