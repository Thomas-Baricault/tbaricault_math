/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <cmath>
#include <vector>

#include <tbaricault/str.hpp>
#include <tbaricault/uniconvert.hpp>

#include "Vector2.hpp"


namespace tbaricault::math
{

    template<typename T>
    Vector2<T> Vector2<T>::zero() noexcept
    {
        return Vector2(0, 0);
    }

    template<typename T>
    Vector2<T> Vector2<T>::one() noexcept
    {
        return Vector2(1, 1);
    }

    template<typename T>
    Vector2<T> Vector2<T>::left() noexcept
    {
        return Vector2(-1, 0);
    }

    template<typename T>
    Vector2<T> Vector2<T>::right() noexcept
    {
        return Vector2(1, 0);
    }

    template<typename T>
    Vector2<T> Vector2<T>::down() noexcept
    {
        return Vector2(0, -1);
    }

    template<typename T>
    Vector2<T> Vector2<T>::up() noexcept
    {
        return Vector2(0, 1);
    }

    template<typename T>
    Vector2<T> Vector2<T>::hadamard(const Vector2& a, const Vector2& b) noexcept
    {
        return Vector2(
            a.x * b.x,
            a.y * b.y
        );
    }

    template<typename T>
    double Vector2<T>::distance(const Vector2& a, const Vector2& b) noexcept
    {
        return sqrt(
            (a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y)
        );
    }

    template<typename T>
    double Vector2<T>::angle(const Vector2& a, const Vector2& b) noexcept
    {
        return acos(a * b / (a.magnitude() * b.magnitude()));
    }

    template<typename T>
    Vector2<T>::Vector2(T v) noexcept
        : x(v)
        , y(v)
    {
        return;
    }

    template<typename T>
    Vector2<T>::Vector2(T x, T y) noexcept
        : x(x)
        , y(y)
    {
        return;
    }

    template<typename T>
    template<typename U>
    Vector2<T>::Vector2(const Vector2<U>& other)
        : x(static_cast<T>(other.x))
        , y(static_cast<T>(other.y))
    {
        return;
    }

    template<typename T>
    Vector2<T>::Vector2(std::string_view str)
    {
        std::vector<std::string> args = tbaricault::str::split(str, " ", false);
        if (args.size() == 2)
        {
            this->x = tbaricault::uniconvert::convert<std::string, T>(args.at(0));
            this->y = tbaricault::uniconvert::convert<std::string, T>(args.at(1));
        }
        throw std::invalid_argument("convertion failed");
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator+=(const Vector2& other) noexcept
    {
        this->x += other.x;
        this->y += other.y;
        return (*this);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator+=(T other) noexcept
    {
        this->x += other;
        this->y += other;
        return (*this);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2& other) noexcept
    {
        this->x -= other.x;
        this->y -= other.y;
        return (*this);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator-=(T other) noexcept
    {
        this->x -= other;
        this->y -= other;
        return (*this);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator*=(T other) noexcept
    {
        this->x *= other;
        this->y *= other;
        return (*this);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator/=(T other) noexcept
    {
        this->x /= other;
        this->y /= other;
        return (*this);
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator+(const Vector2& other) const noexcept
    {
        return Vector2(
            this->x + other.x,
            this->y + other.y
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator+(T other) const noexcept
    {
        return Vector2(
            this->x + other,
            this->y + other
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2& other) const noexcept
    {
        return Vector2(
            this->x - other.x,
            this->y - other.y
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator-(T other) const noexcept
    {
        return Vector2(
            this->x - other,
            this->y - other
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator-() const noexcept
    {
        return Vector2(
            -this->x,
            -this->y
        );
    }

    template<typename T>
    T Vector2<T>::operator*(const Vector2& other) const noexcept
    {
        return (
            this->x * other.x +
            this->y * other.y
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator*(T other) const noexcept
    {
        return Vector2(
            this->x * other,
            this->y * other
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator/(T other) const noexcept
    {
        return Vector2(
            this->x / other,
            this->y / other
        );
    }

    template<typename T>
    bool Vector2<T>::operator==(const Vector2& other) const noexcept
    {
        return (
            other.x == this->x &&
            other.y == this->y
        );
    }

    template<typename T>
    bool Vector2<T>::operator!=(const Vector2& other) const noexcept
    {
        return (
            other.x != this->x ||
            other.y != this->y
        );
    }

    template<typename T>
    Vector2<T>::operator std::string() const
    {
        return (
            tbaricault::uniconvert::convert<T, std::string>(this->x) + ' ' +
            tbaricault::uniconvert::convert<T, std::string>(this->y)
        );
    }

    template<typename T>
    bool Vector2<T>::isZero() const noexcept
    {
        return (
            this->x == 0 &&
            this->y == 0
        );
    }

    template<typename T>
    double Vector2<T>::magnitude() const noexcept
    {
        return sqrt(
            this->x * this->x +
            this->y * this->y
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::normalize() const noexcept
    {
        double magnitude = this->magnitude();
        return (
            magnitude == 0
            ? Vector2::zero()
            : Vector2(
                this->x / magnitude,
                this->y / magnitude
            )
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::limit(T limit) const noexcept
    {
        double magnitude = this->magnitude();
        return (
            magnitude > limit
            ? Vector2(
                this->x / magnitude * limit,
                this->y / magnitude * limit
            )
            : *this
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::rotate(double angle) const noexcept
    {
        double c = cos(angle);
        double s = sin(angle);
        return Vector2(
            this->x * c - this->y * s,
            this->x * s + this->y * c
        );
    }

    template<typename T>
    Vector2<T> Vector2<T>::project(const Vector2& other) const noexcept
    {
        return (other * ((*this) * other) / (other * other));
    }

}
