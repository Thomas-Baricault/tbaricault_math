/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <cmath>

#include "Vector3.hpp"


namespace tbaricault::math
{

    template<typename T>
    Vector3<T> Vector3<T>::left() noexcept
    {
        return Vector3(-1, 0, 0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::right() noexcept
    {
        return Vector3(1, 0, 0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::down() noexcept
    {
        return Vector3(0, -1, 0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::up() noexcept
    {
        return Vector3(0, 1, 0);
    }

    template<typename T>
    Vector3<T> Vector3<T>::backward() noexcept
    {
        return Vector3(0, 0, -1);
    }

    template<typename T>
    Vector3<T> Vector3<T>::forward() noexcept
    {
        return Vector3(0, 0, 1);
    }

    template<typename T>
    Vector3<T> Vector3<T>::hadamard(const Vector3& a, const Vector3& b) noexcept
    {
        return Vector3(
            a.x * b.x,
            a.y * b.y,
            a.z * b.z
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::cross(const Vector3& a, const Vector3& b) noexcept
    {
        return Vector3(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        );
    }

    template<typename T>
    double Vector3<T>::distance(const Vector3& a, const Vector3& b) noexcept
    {
        return sqrt(
            (a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y) +
            (a.z - b.z) * (a.z - b.z)
        );
    }

    template<typename T>
    double Vector3<T>::angle(const Vector3& a, const Vector3& b) noexcept
    {
        return acos(a * b / (a.magnitude() * b.magnitude()));
    }

    template<typename T>
    Vector3<T>::Vector3(T value) noexcept
        : x(value)
        , y(value)
        , z(value)
    {
        return;
    }

    template<typename T>
    Vector3<T>::Vector3(T x, T y, T z) noexcept
        : x(x)
        , y(y)
        , z(z)
    {
        return;
    }

    template<typename T>
    Vector3<T>::Vector3(const Vector2<T>& v, T z) noexcept
        : x(v.x)
        , y(v.y)
        , z(z)
    {
        return;
    }

    template<typename T>
    template<typename U>
    Vector3<T>::Vector3(const Vector3<U>& other)
        : x(static_cast<T>(other.x))
        , y(static_cast<T>(other.y))
        , z(static_cast<T>(other.z))
    {
        return;
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator+=(const Vector3& other) noexcept
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return (*this);
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator+=(T other) noexcept
    {
        this->x += other;
        this->y += other;
        this->z += other;
        return (*this);
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator-=(const Vector3& other) noexcept
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return (*this);
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator-=(T other) noexcept
    {
        this->x -= other;
        this->y -= other;
        this->z -= other;
        return (*this);
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator*=(T other) noexcept
    {
        this->x *= other;
        this->y *= other;
        this->z *= other;
        return (*this);
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator/=(T other) noexcept
    {
        this->x /= other;
        this->y /= other;
        this->z /= other;
        return (*this);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator+(const Vector3& other) const noexcept
    {
        return Vector3(
            this->x + other.x,
            this->y + other.y,
            this->z + other.z
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator+(T other) const noexcept
    {
        return Vector3(
            this->x + other,
            this->y + other,
            this->z + other
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator-(const Vector3& other) const noexcept
    {
        return Vector3(
            this->x - other.x,
            this->y - other.y,
            this->z - other.z
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator-(T other) const noexcept
    {
        return Vector3(
            this->x - other,
            this->y - other,
            this->z - other
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator-() const noexcept
    {
        return Vector3(
            -this->x,
            -this->y,
            -this->z
        );
    }

    template<typename T>
    T Vector3<T>::operator*(const Vector3& other) const noexcept
    {
        return (
            this->x * other.x +
            this->y * other.y +
            this->z * other.z
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator*(T other) const noexcept
    {
        return Vector3(
            this->x * other,
            this->y * other,
            this->z * other
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator/(T other) const noexcept
    {
        return Vector3(
            this->x / other,
            this->y / other,
            this->z / other
        );
    }

    template<typename T>
    bool Vector3<T>::operator==(const Vector3& other) const noexcept
    {
        return (
            other.x == this->x &&
            other.y == this->y &&
            other.z == this->z
        );
    }

    template<typename T>
    bool Vector3<T>::operator!=(const Vector3& other) const noexcept
    {
        return (
            other.x != this->x ||
            other.y != this->y ||
            other.z != this->z
        );
    }

    template<typename T>
    bool Vector3<T>::isZero() const noexcept
    {
        return (
            this->x == 0 &&
            this->y == 0 &&
            this->z == 0
        );
    }

    template<typename T>
    double Vector3<T>::magnitude() const noexcept
    {
        return sqrt(
            this->x * this->x +
            this->y * this->y +
            this->z * this->z
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::normalize() const noexcept
    {
        double magnitude = this->magnitude();
        return (
            magnitude == 0
            ? Vector3(1, 0, 0)
            : Vector3(
                this->x / magnitude,
                this->y / magnitude,
                this->z / magnitude
            )
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::limit(T limit) const noexcept
    {
        double magnitude = this->magnitude();
        return (
            magnitude > limit
            ? Vector3(
                this->x / magnitude * limit,
                this->y / magnitude * limit,
                this->z / magnitude * limit
            )
            : *this
        );
    }

    template<typename T>
    Vector3<T> Vector3<T>::project(const Vector3& other) const noexcept
    {
        return (other * ((*this) * other) / (other * other));
    }

}
