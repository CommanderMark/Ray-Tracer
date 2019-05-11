#include "Light.h"

Light::Light(const Vector3f& position, const Vector3f& color) : position(position), color(color) { }

const Vector3f Light::getPosition() const {
    return position;
}