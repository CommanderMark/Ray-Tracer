#include "Intersection.h"

Intersection::Intersection() : obj(nullptr), contact(Vector3f::zero), normal(Vector3f::zero) {
    hit = false;
}

Intersection::Intersection(const Object* obj, const Vector3f& contact, const Vector3f& surfaceNormal) : obj(obj), contact(contact), normal(surfaceNormal) {
    hit = true;
}

bool Intersection::didHit() {
    return hit;
}