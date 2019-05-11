#include "Plane.h"

Plane::Plane(const Vector3f& normal, const Vector3f& color) : normal(normal) {
    this->color = color;
}

Intersection Plane::intersects(const Ray& ray) {

}