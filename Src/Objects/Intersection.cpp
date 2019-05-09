#include "Intersection.h"

Intersection::Intersection() : obj(nullptr), contact(Vector3f::zero) {
    hit = false;
}

Intersection::Intersection(const Object* obj, Vector3f contact) : obj(obj), contact(contact) {
    hit = true;
}

bool Intersection::didHit() {
    return hit;
}