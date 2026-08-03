/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <cmath>

#include "Quaternion.hpp"


namespace tbaricault::math
{

    template<typename T>
    Quaternion Quaternion::fromAxisAngle(const Vector3<T>& axis, double angle) noexcept
    {
        double s = sin(angle / 2);
        return Quaternion(
            axis.x * s,
            axis.y * s,
            axis.z * s,
            cos(angle / 2)
        );
    }

    template<typename T>
    Vector3<T> Quaternion::rotate(const Vector3<T>& v) const noexcept
    {
        return Vector3<T>(
            static_cast<T>((1 - 2 * this->y * this->y - 2 * this->z * this->z) * v.x + (2 * this->x * this->y - 2 * this->w * this->z) * v.y + (2 * this->x * this->z + 2 * this->w * this->y) * v.z),
            static_cast<T>((2 * this->x * this->y + 2 * this->w * this->z) * v.x + (1 - 2 * this->x * this->x - 2 * this->z * this->z) * v.y + (2 * this->y * this->z - 2 * this->w * this->x) * v.z),
            static_cast<T>((2 * this->x * this->z - 2 * this->w * this->y) * v.x + (2 * this->y * this->z + 2 * this->w * this->x) * v.y + (1 - 2 * this->x * this->x - 2 * this->y * this->y) * v.z)
        );
    }

}
