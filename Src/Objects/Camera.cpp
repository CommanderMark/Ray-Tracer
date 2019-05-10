#include "Camera.h"

Camera::Camera(const Vector3f& pos, const Vector3f& lookAt) {
    position = pos;

    // I have no clue what I'm doing.
    forward = lookAt.subtract(position).normalize();
    right = forward.crossProduct(Vector3f(0.0, -1.0, 0.0)).normalize().multiply(1.5f);
    up = forward.crossProduct(right).normalize().multiply(1.5f);
}
