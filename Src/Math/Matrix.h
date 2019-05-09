/* Copyright (c) 2019 Juan Pablo Arce

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

This notice may not be removed or altered from any source distribution. */

#ifndef PGE_MATRIX_H_INCLUDED
#define PGE_MATRIX_H_INCLUDED

#include "Vector.h"

class Matrix4x4f {
public:
    float elements[4][4];

    Matrix4x4f();
    Matrix4x4f(float aa,float ab,float ac,float ad,
                float ba,float bb,float bc,float bd,
                float ca,float cb,float cc,float cd,
                float da,float db,float dc,float dd);

    Matrix4x4f transpose() const;

    Matrix4x4f product(const Matrix4x4f& other) const;
    Vector4f transform(const Vector4f& other) const;
    Vector3f transform(const Vector3f& other) const;

    static Matrix4x4f constructWorldMat(const Vector3f& position,const Vector3f& scale,const Vector3f& rotation);
    static Matrix4x4f constructViewMat(const Vector3f& position,const Vector3f& target,const Vector3f& upVector);

    static const Matrix4x4f identity;
};

#endif
