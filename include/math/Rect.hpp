/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string>
#include <string_view>

#include "Vector2.hpp"


namespace tbaricault::math
{

    /**
     * @brief Axis-aligned rectangle
     * 
     * @tparam T Component type
     */
    template<typename T>
    class Rect final
    {

        public:

            /**
             * @brief Whether rectangle can be represented with only two components if `x == w` and `y == h`
             */
            static bool allowTwoComponents;

            /**
             * @brief Whether rectangle can be represented with only one component if all components are equal
             */
            static bool allowOneComponent;

            /**
             * @brief X coordinate
             */
            T x = T{};

            /**
             * @brief Y coordinate
             */
            T y = T{};

            /**
             * @brief Width
             */
            T w = T{};

            /**
             * @brief Height
             */
            T h = T{};


            /**
             * @brief Constructs an empty rectangle
             */
            Rect() noexcept = default;

            /**
             * @brief Copy constructor
             * 
             * @param other Rectangle to copy
             */
            Rect(const Rect& other) noexcept = default;

            /**
             * @brief Move constructor
             * 
             * @param other Rectangle to move
             */
            Rect(Rect&& other) noexcept = default;

            /**
             * @brief Constructs a rectangle with uniform value
             *
             * @param value Value assigned to all components
             */
            Rect(T value) noexcept;

            /**
             * @brief Constructs a rectangle at origin with given size
             * 
             * @param w Width
             * @param h Height
             */
            Rect(T w, T h) noexcept;

            /**
             * @brief Constructs a rectangle from position and size
             * 
             * @param x X coordinate
             * @param y Y coordinate
             * @param w Width
             * @param h Height
             */
            Rect(T x, T y, T w, T h) noexcept;

            /**
             * @brief Constructs a rectangle at origin with given size
             * 
             * @param size Size
             */
            Rect(const Vector2<T>& size) noexcept;

            /**
             * @brief Constructs a rectangle from position and size
             * 
             * @param pos Position
             * @param size Size
             */
            Rect(const Vector2<T>&, const Vector2<T>&) noexcept;

            /**
             * @brief Constructs a rectangle from its string representation
             * 
             * @param str String representation
             * 
             * @throws std::invalid_argument If conversion failed
             */
            Rect(std::string_view str);

            /**
             * @brief Destructor
             */
            ~Rect() noexcept = default;

            /**
             * @brief Copy assignment operator
             * 
             * @param other Rectangle to copy
             * 
             * @return Reference to this rectangle
             */
            Rect& operator=(const Rect& other) noexcept = default;

            /**
             * @brief Move assignment operator
             * 
             * @param other Rectangle to move
             * 
             * @return Reference to this rectangle
             */
            Rect& operator=(Rect&& other) noexcept = default;

            /**
             * @brief Computes the union of two rectangles
             * 
             * The resulting rectangle is the smallest rectangle that contains both
             * 
             * @param other Second rectangle
             * 
             * @return Reference to this rectangle
             */
            Rect& operator|=(const Rect& other) noexcept;

            /**
             * @brief Computes the intersection of two rectangles
             * 
             * If there is no overlap, the result is an empty rectangle
             * 
             * @param other Second rectangle
             * 
             * @return Reference to this rectangle
             */
            Rect& operator&=(const Rect& other) noexcept;

            /**
             * @brief Computes the union of two rectangles
             * 
             * The resulting rectangle is the smallest rectangle that contains both
             * 
             * @param other Second rectangle
             * 
             * @return Resulting rectangle
             */
            Rect operator|(const Rect&) const noexcept;

            /**
             * @brief Computes the intersection of two rectangles
             * 
             * If there is no overlap, the result is an empty rectangle
             * 
             * @param other Second rectangle
             * 
             * @return Resulting rectangle
             */
            Rect operator&(const Rect&) const noexcept;

            /**
             * @brief Checks whether two rectangles are equal
             * 
             * @param other Rectangle to compare with
             * 
             * @return `true` if both rectangle are equal, `false` otherwise
             */
            bool operator==(const Rect&) const noexcept;

            /**
             * @brief Checks whether two rectangles are different
             * 
             * @param other Rectangle to compare with
             * 
             * @return `true` if rectangles differ, `false` otherwise
             */
            bool operator!=(const Rect&) const noexcept;

            /**
             * @brief Converts the rectangle to its string representation
             */
            operator std::string() const;

            /**
             * @brief Checks whether two rectangles intersect
             * 
             * @param other Second rectangle
             * 
             * @return `true` if rectangles intersect, `false` otherwise
             */
            bool intersects(const Rect& other) const noexcept;

            /**
             * @brief Checks whether a point lies inside the rectangle
             * 
             * @param point Point to test
             * 
             * @return `true` if point lies inside the rectangle, `false` otherwise
             */
            bool contains(const Vector2<T>& point) const noexcept;

            /**
             * @brief Returns the size (width, height)
             * 
             * @return Size (width, height)
             */
            Vector2<T> size() const noexcept;

            /**
             * @brief Computes the area of the rectangle
             * 
             * @return Area (width * height)
             */
            T area() const noexcept;

            /**
             * @brief Returns the top-left corner
             * 
             * @return Corner position
             */
            Vector2<T> topLeft() const noexcept;

            /**
             * @brief Returns the top-right corner
             * 
             * @return Corner position
             */
            Vector2<T> topRight() const noexcept;

            /**
             * @brief Returns the bottom-left corner
             * 
             * @return Corner position
             */
            Vector2<T> bottomLeft() const noexcept;

            /**
             * @brief Returns the bottom-right corner
             * 
             * @return Corner position
             */
            Vector2<T> bottomRight() const noexcept;

            /**
             * @brief Sets the rectangle position
             * 
             * @param pos New top-left position (x, y)
             * 
             * @return Reference to this rectangle
             */
            Rect& setPosition(const Vector2<T>& pos) noexcept;

            /**
             * @brief Translates the rectangle by a given offset
             * 
             * @param offset Translation vector
             * 
             * @return Reference to this rectangle
             */
            Rect& translate(const Vector2<T>& offset) noexcept;

            /**
             * @brief Returns a translated copy of the rectangle
             * 
             * @param offset Translation vector
             * 
             * @return Translated rectangle
             */
            Rect translated(const Vector2<T>& offset) const noexcept;

            /**
             * @brief Sets the rectangle size
             * 
             * @param size New size (width, height)
             * 
             * @return Reference to this rectangle
             */
            Rect& setSize(const Vector2<T>& size) noexcept;

            /**
             * @brief Inflates the rectangle by a given amount
             * 
             * @param size Amount to inflate (width, height)
             * 
             * @return Reference to this rectangle
             */
            Rect& inflate(const Vector2<T>& size) noexcept;

            /**
             * @brief Returns an inflated copy of the rectangle
             * 
             * @param size Inflation amount (width, height)
             * 
             * @return Inflated rectangle
             */
            Rect inflated(const Vector2<T>& size) const noexcept;

    };

}


#include "Rect.tpp"
