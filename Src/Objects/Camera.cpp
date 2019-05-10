#include "Camera.h"

Camera::Camera(const Vector3f& pos, const Vector3f& lookAt, const Vector3f& viewUp) {
    position = pos;
    
    // Direction from camera to lookAt.
    forward = lookAt.subtract(position).normalize();
    
    // Based on whatever we defined the "up" as, is should be on the pixel plane.
    // Perform cross product with viewup and forward to get right.
    right = forward.crossProduct(viewUp).normalize();
    
    up = forward.crossProduct(right).normalize();
}
