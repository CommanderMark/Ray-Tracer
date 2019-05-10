#include "Camera.h"

Camera::Camera(const Vector3f& pos, const Vector3f& lookAt, const Vector3f& viewUp) {
    position = pos;

    // Direction from camera to lookAt.
    forward = position.subtract(lookAt).normalize();

    // Based on whatever we defined the "up" as, is should be on the pixel plane.
    // Perform cross product with viewup and forward to get right.
    right = forward.crossProduct(viewUp).normalize();

    up = forward.crossProduct(right).normalize();
}

const Vector3f Camera::getPosition() {
    return position;
}

const Vector3f Camera::getForward() {
    return forward;
}

const Vector3f Camera::getUp() {
    return up;
}

const Vector3f Camera::getRight() {
    return right;
}
