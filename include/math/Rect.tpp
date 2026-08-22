/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <stdexcept>

#include <tbaricault/str.hpp>
#include <tbaricault/uniconvert.hpp>

#include "Rect.hpp"


namespace tbaricault::math
{

    template<typename T>
    bool Rect<T>::allowTwoComponents = true;

    template<typename T>
    bool Rect<T>::allowOneComponent = true;


    template<typename T>
    Rect<T>::Rect(T v) noexcept
        : x(v)
        , y(v)
        , w(v)
        , h(v)
    {
        return;
    }

    template<typename T>
    Rect<T>::Rect(T w, T h) noexcept
        : w(w)
        , h(h)
    {
        return;
    }

    template<typename T>
    Rect<T>::Rect(T x, T y, T w, T h) noexcept
        : x(x)
        , y(y)
        , w(w)
        , h(h)
    {
        return;
    }

    template<typename T>
    Rect<T>::Rect(const Vector2<T>& size) noexcept
        : w(size.x)
        , h(size.y)
    {
        return;
    }

    template<typename T>
    Rect<T>::Rect(const Vector2<T>& pos, const Vector2<T>& size) noexcept
        : x(pos.x)
        , y(pos.y)
        , w(size.x)
        , h(size.y)
    {
        return;
    }

    template<typename T>
    Rect<T>::Rect(std::string_view str)
    {
        std::vector<std::string> args = tbaricault::str::split(str, " ", false);
        if (Rect::allowOneComponent && args.size() == 1)
        {
            this->x = tbaricault::uniconvert::convert<std::string, T>(args.at(0));
            this->y = tbaricault::uniconvert::convert<std::string, T>(args.at(0));
            this->w = tbaricault::uniconvert::convert<std::string, T>(args.at(0));
            this->h = tbaricault::uniconvert::convert<std::string, T>(args.at(0));
        }
        else if (Rect::allowTwoComponents && args.size() == 2)
        {
            this->x = tbaricault::uniconvert::convert<std::string, T>(args.at(0));
            this->y = tbaricault::uniconvert::convert<std::string, T>(args.at(1));
            this->w = tbaricault::uniconvert::convert<std::string, T>(args.at(0));
            this->h = tbaricault::uniconvert::convert<std::string, T>(args.at(1));
        }
        else if (args.size() == 4)
        {
            this->x = tbaricault::uniconvert::convert<std::string, T>(args.at(0));
            this->y = tbaricault::uniconvert::convert<std::string, T>(args.at(1));
            this->w = tbaricault::uniconvert::convert<std::string, T>(args.at(2));
            this->h = tbaricault::uniconvert::convert<std::string, T>(args.at(3));
        }
        throw std::invalid_argument("convertion failed");
    }

    template<typename T>
    Rect<T>& Rect<T>::operator|=(const Rect& other) noexcept
    {
        *this = *this | other;
        return (*this);
    }

    template<typename T>
    Rect<T>& Rect<T>::operator&=(const Rect& other) noexcept
    {
        *this = *this & other;
        return (*this);
    }

    template<typename T>
    Rect<T> Rect<T>::operator|(const Rect& other) const noexcept
    {
        if (this->area() == T{})
            return (other);
        if (other.area() == T{})
            return (*this);
        Rect rect(std::min(this->x, other.x), std::min(this->y, other.y), 0, 0);
        rect.w = std::max(this->x + this->w, other.x + other.w) - rect.x;
        rect.h = std::max(this->y + this->h, other.y + other.h) - rect.y;
        return (rect);
    }

    template<typename T>
    Rect<T> Rect<T>::operator&(const Rect& other) const noexcept
    {
        if (!this->intersects(other))
            return (Rect());
        Rect rect(std::max(this->x, other.x), std::max(this->y, other.y), 0, 0);
        rect.w = std::min(this->x + this->w, other.x + other.w) - rect.x;
        rect.h = std::min(this->y + this->h, other.y + other.h) - rect.y;
        return (rect);
    }

    template<typename T>
    bool Rect<T>::operator==(const Rect& other) const noexcept
    {
        return (
            other.x == this->x &&
            other.y == this->y &&
            other.w == this->w &&
            other.h == this->h
        );
    }

    template<typename T>
    bool Rect<T>::operator!=(const Rect& other) const noexcept
    {
        return (
            other.x != this->x ||
            other.y != this->y ||
            other.w != this->w ||
            other.h != this->h
        );
    }

    template<typename T>
    Rect<T>::operator std::string() const
    {
        if (Rect::allowOneComponent && this->x == this->y && this->x == this->w && this->x == this->h)
            return (tbaricault::uniconvert::convert<T, std::string>(this->x));
        if (Rect::allowTwoComponents && this->x == this->w && this->y == this->h)
        {
            return (
                tbaricault::uniconvert::convert<T, std::string>(this->x) + ' ' +
                tbaricault::uniconvert::convert<T, std::string>(this->y)
            );
        }
        return (
            tbaricault::uniconvert::convert<T, std::string>(this->x) + ' ' +
            tbaricault::uniconvert::convert<T, std::string>(this->y) + ' ' +
            tbaricault::uniconvert::convert<T, std::string>(this->w) + ' ' +
            tbaricault::uniconvert::convert<T, std::string>(this->h)
        );
    }

    template<typename T>
    bool Rect<T>::intersects(const Rect& other) const noexcept
    {
        return !(
            this->x >= other.x + other.w ||
            this->y >= other.y + other.h ||
            other.x >= this->x + this->w ||
            other.y >= this->y + this->h
        );
    }

    template<typename T>
    bool Rect<T>::contains(const Vector2<T>& point) const noexcept
    {
        return (
            this->x <= point.x && point.x < this->x + this->w &&
            this->y <= point.y && point.y < this->y + this->h
        );
    }

    template<typename T>
    Vector2<T> Rect<T>::size() const noexcept
    {
        return Vector2<T>(
            this->w,
            this->h
        );
    }

    template<typename T>
    T Rect<T>::area() const noexcept
    {
        return (this->w * this->h);
    }

    template<typename T>
    Vector2<T> Rect<T>::topLeft() const noexcept
    {
        return Vector2<T>(
            this->x,
            this->y
        );
    }

    template<typename T>
    Vector2<T> Rect<T>::topRight() const noexcept
    {
        return Vector2<T>(
            this->x + this->w,
            this->y
        );
    }

    template<typename T>
    Vector2<T> Rect<T>::bottomLeft() const noexcept
    {
        return Vector2<T>(
            this->x,
            this->y + this->h
        );
    }

    template<typename T>
    Vector2<T> Rect<T>::bottomRight() const noexcept
    {
        return Vector2<T>(
            this->x + this->w,
            this->y + this->h
        );
    }

    template<typename T>
    Rect<T>& Rect<T>::setPosition(const Vector2<T>& pos) noexcept
    {
        this->x = pos.x;
        this->y = pos.y;
        return (*this);
    }

    template<typename T>
    Rect<T>& Rect<T>::translate(const Vector2<T>& offset) noexcept
    {
        this->x += offset.x;
        this->y += offset.y;
        return (*this);
    }

    template<typename T>
    Rect<T> Rect<T>::translated(const Vector2<T>& offset) const noexcept
    {
        return Rect(
            this->x + offset.x,
            this->y + offset.y,
            this->w,
            this->h
        );
    }

    template<typename T>
    Rect<T>& Rect<T>::setSize(const Vector2<T>& size) noexcept
    {
        this->w = size.x;
        this->h = size.y;
        return (*this);
    }

    template<typename T>
    Rect<T>& Rect<T>::inflate(const Vector2<T>& size) noexcept
    {
        this->w += size.x;
        this->h += size.y;
        return (*this);
    }

    template<typename T>
    Rect<T> Rect<T>::inflated(const Vector2<T>& size) const noexcept
    {
        return Rect(
            this->x,
            this->y,
            this->w + size.x,
            this->h + size.y
        );
    }

}
