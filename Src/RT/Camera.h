#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "../Math/Vector.h"

class Camera {
private:
    Vector3f position;
    Vector3f lookAt;
    float fov;

    Vector3f forward;
    Vector3f up;
    Vector3f right;

public:
    const Vector3f getPosition() const;
    float getFOV() const;

    const Vector3f getForward() const;
    const Vector3f getUp() const;
    const Vector3f getRight() const;

    Camera(const Vector3f& pos, const Vector3f& lookAt, const Vector3f& viewUp, float fov);
};

#endif // CAMERA_H_INCLUDED
