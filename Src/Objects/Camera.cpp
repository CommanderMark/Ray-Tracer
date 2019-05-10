#include "Camera.h"
#include "../Math/Math.h"

Camera::Camera(const Vector3f& pos, const Vector3f& lookAt, const Vector3f& viewUp, float fov) : position(pos), lookAt(lookAt) {
    // Store everything as radiants.
    this->fov = Math::degToRad(fov);

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

float Camera::getFOV() {
    return fov;
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
