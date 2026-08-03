/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include <algorithm>
#include <cmath>

#include "math/Quaternion.hpp"


namespace tbaricault::math
{
    Quaternion Quaternion::fromEulerAngles(double pitch, double yaw, double roll) noexcept
    {
        double cx = cos(pitch * 0.5);
        double sx = sin(pitch * 0.5);
        double cy = cos(yaw * 0.5);
        double sy = sin(yaw * 0.5);
        double cz = cos(roll * 0.5);
        double sz = sin(roll * 0.5);
        return Quaternion(
            cx * cy * sz - sx * sy * cz,
            sx * cy * cz + cx * sy * sz,
            cx * sy * cz - sx * cy * sz,
            cx * cy * cz + sx * sy * sz
        );
    }

    Quaternion Quaternion::slerp(const Quaternion& a, const Quaternion& b, double t) noexcept
    {
        Quaternion bb = b;
        double dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
        if (dot < 0)
        {
            bb = Quaternion(-b.x, -b.y, -b.z, -b.w);
            dot = -dot;
        }
        dot = std::clamp(dot, -1.0, 1.0);
        if (dot > 0.9995)
        {
            return Quaternion(
                a.x + (bb.x - a.x) * t,
                a.y + (bb.y - a.y) * t,
                a.z + (bb.z - a.z) * t,
                a.w + (bb.w - a.w) * t
            ).normalize();
        }
        double theta = acos(dot);
        double stheta = sin(theta);
        double s0 = sin((1.0 - t) * theta) / stheta;
        double s1 = sin(t * theta) / stheta;
        return Quaternion(
            a.x * s0 + bb.x * s1,
            a.y * s0 + bb.y * s1,
            a.z * s0 + bb.z * s1,
            a.w * s0 + bb.w * s1
        ).normalize();
    }

    Quaternion::Quaternion(double x, double y, double z, double w) noexcept
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {
        return;
    }

    Quaternion& Quaternion::operator*=(const Quaternion& other) noexcept
    {
        this->x = this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y;
        this->y = this->w * other.y - this->x * other.z + this->y * other.w + this->z * other.x;
        this->z = this->w * other.z + this->x * other.y - this->y * other.x + this->z * other.w;
        this->w = this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z;
        return (*this);
    }

    Quaternion Quaternion::operator*(const Quaternion& other) const noexcept
    {
        return Quaternion(
            this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y,
            this->w * other.y - this->x * other.z + this->y * other.w + this->z * other.x,
            this->w * other.z + this->x * other.y - this->y * other.x + this->z * other.w,
            this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z
        );
    }

    Quaternion Quaternion::inverse() const noexcept
    {
        double norm = this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
        return Quaternion(
            -this->x / norm,
            -this->y / norm,
            -this->z / norm,
             this->w / norm
        );
    }

    Quaternion Quaternion::normalize() const noexcept
    {
        double norm = (
            this->x * this->x +
            this->y * this->y +
            this->z * this->z +
            this->w * this->w
        );
        return (
            norm == 0
            ? Quaternion()
            : Quaternion(
                this->x / norm,
                this->y / norm,
                this->z / norm,
                this->w / norm
            )
        );
    }
}