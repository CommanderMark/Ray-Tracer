#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "../Math/Vector.h"

class Camera {
private:
    Vector3f position;

    Vector3f forward;
    Vector3f up;
    Vector3f right;

public:
    const Vector3f getPosition();

    const Vector3f getForward();
    const Vector3f getUp();
    const Vector3f getRight();

    Camera(const Vector3f& pos, const Vector3f& lookAt, const Vector3f& viewUp);
};

#endif // CAMERA_H_INCLUDED
