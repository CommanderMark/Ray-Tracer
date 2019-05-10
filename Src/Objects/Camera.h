#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "../Math/Vector.h"

class Camera {
public:
    Vector3f position;
    Vector3f up;
    Vector3f right;
    Vector3f forward;

    Camera(const Vector3f& pos, const Vector3f& lookAt, const Vector3f& viewUp);
};

#endif // CAMERA_H_INCLUDED
