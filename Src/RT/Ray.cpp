#include "Ray.h"

Ray::Ray(const Vector3f& origin, const Vector3f& direction) : origin(origin), direction(direction.normalize()) { }
