/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string>
#include <string_view>


namespace tbaricault::math
{

    /**
     * @brief Two-dimensional vector
     * 
     * @tparam T Component type
     */
    template<typename T>
    class Vector2 final
    {

        public:

            /**
             * @brief X component
             */
            T x = T{};

            /**
             * @brief Y component
             */
            T y = T{};


            /**
             * @brief Returns the zero vector
             * 
             * @return (0, 0)
             */
            static Vector2 zero() noexcept;

            /**
             * @brief Returns a vector whose components are all equal to one
             * 
             * @return (1, 1)
             */
            static Vector2 one() noexcept;

            /**
             * @brief Returns the unit vector pointing left
             * 
             * @return (-1, 0)
             */
            static Vector2 left() noexcept;

            /**
             * @brief Returns the unit vector pointing right
             * 
             * @return (1, 0)
             */
            static Vector2 right() noexcept;

            /**
             * @brief Returns the unit vector pointing downward
             * 
             * @return (0, -1)
             */
            static Vector2 down() noexcept;

            /**
             * @brief Returns the unit vector pointing upward
             * 
             * @return (0, 1)
             */
            static Vector2 up() noexcept;

            /**
             * @brief Computes the Hadamard (element-wise) product of two vectors
             * 
             * @param a First vector
             * @param b Second vector
             * 
             * @return Component-wise product
             */
            static Vector2 hadamard(const Vector2& a, const Vector2& b) noexcept;

            /**
             * @brief Computes the Euclidean distance between two points
             * 
             * @param a First point
             * @param b Second point
             * 
             * @return Distance
             */
            static double distance(const Vector2& a, const Vector2& b) noexcept;

            /**
             * @brief Computes the angle between two vectors
             * 
             * @param a First vector
             * @param b Second vector
             * 
             * @return Angle in radians
             */
            static double angle(const Vector2& a, const Vector2& b) noexcept;

            /**
             * @brief Constructs the zero vector
             */
            Vector2() noexcept = default;

            /**
             * @brief Copy constructor
             * 
             * @param other Vector to copy
             */
            Vector2(const Vector2& other) noexcept = default;

            /**
             * @brief Move constructor
             * 
             * @param other Vector to move
             */
            Vector2(Vector2&& other) noexcept = default;

            /**
             * @brief Constructs a vector with all components initialized to the same value
             * 
             * @param value Component value
             */
            Vector2(T value) noexcept;

            /**
             * @brief Constructs a vector from its components
             * 
             * @param x X component
             * @param y Y component
             */
            Vector2(T x, T y) noexcept;

            /**
             * @brief Constructs a vector by converting another @ref Vector2
             *
             * @tparam U Source component type
             * 
             * @param other Vector to convert
             */
            template<typename U>
            Vector2(const Vector2<U>& other);

            /**
             * @brief Constructs a vector from its string representation
             * 
             * @param str String representation
             * 
             * @throws std::invalid_argument If conversion failed
             */
            Vector2(std::string_view str);

            /**
             * @brief Destructor
             */
            ~Vector2() noexcept = default;

            /**
             * @brief Copy assignment operator
             * 
             * @param other Vector to copy
             * 
             * @return Reference to this vector
             */
            Vector2& operator=(const Vector2& other) noexcept = default;

            /**
             * @brief Move assignment operator
             * 
             * @param other Vector to move
             * 
             * @return Reference to this vector
             */
            Vector2& operator=(Vector2&& other) noexcept = default;

            /**
             * @brief Adds another vector component-wise
             * 
             * @param other Vector to add
             * 
             * @return Reference to this vector
             */
            Vector2& operator+=(const Vector2& other) noexcept;

            /**
             * @brief Adds a scalar value to each component
             * 
             * @param other Scalar to add
             * 
             * @return Reference to this vector
             */
            Vector2& operator+=(T other) noexcept;

            /**
             * @brief Subtracts another vector component-wise
             * 
             * @param other Vector to subtract
             * 
             * @return Reference to this vector
             */
            Vector2& operator-=(const Vector2& other) noexcept;

            /**
             * @brief Subtracts a scalar value to each component
             * 
             * @param other Scalar to subtract
             * 
             * @return Reference to this vector
             */
            Vector2& operator-=(T other) noexcept;

            /**
             * @brief Multiplies each component by a scalar
             * 
             * @param other Scalar multiplier
             * 
             * @return Reference to this vector
             */
            Vector2& operator*=(T other) noexcept;

            /**
             * @brief Divides each component by a scalar
             * 
             * @param other Scalar divisor
             * 
             * @return Reference to this vector
             */
            Vector2& operator/=(T other) noexcept;

            /**
             * @brief Component-wise addition of two vectors
             * 
             * @param other Vector to add
             * 
             * @return Resulting vector
             */
            Vector2 operator+(const Vector2& other) const noexcept;

            /**
             * @brief Adds a scalar to each component of a vector
             * 
             * @param other Scalar to add
             * 
             * @return Resulting vector
             */
            Vector2 operator+(T other) const noexcept;

            /**
             * @brief Component-wise subtraction of two vectors
             * 
             * @param other Vector to subtract
             * 
             * @return Resulting vector
             */
            Vector2 operator-(const Vector2& other) const noexcept;

            /**
             * @brief Subtracts a scalar to each component of a vector
             * 
             * @param other Scalar to subtract
             * 
             * @return Resulting vector
             */
            Vector2 operator-(T other) const noexcept;

            /**
             * @brief Returns the negation of the vector
             * 
             * @return (-x, -y)
             */
            Vector2 operator-() const noexcept;

            /**
             * @brief Computes the dot product of two vectors
             * 
             * @param other Second vector
             * 
             * @return Dot product (ax * bx + ay * by)
             */
            T operator*(const Vector2& other) const noexcept;

            /**
             * @brief Multiplies each component of a vector by a scalar
             * 
             * @param other Scalar multiplier
             * 
             * @return Resulting vector
             */
            Vector2 operator*(T other) const noexcept;

            /**
             * @brief Divides each component of a vector by a scalar
             * 
             * @param other Scalar divisor
             * 
             * @return Resulting vector
             */
            Vector2 operator/(T other) const noexcept;

            /**
             * @brief Checks whether two vectors are equal
             * 
             * @param other Vector to compare with
             * 
             * @return `true` if both vector are equal, `false` otherwise
             */
            bool operator==(const Vector2& other) const noexcept;

            /**
             * @brief Checks whether two vectors are different
             * 
             * @param other Vector to compare with
             * 
             * @return `true` if vectors differ, `false` otherwise
             */
            bool operator!=(const Vector2& other) const noexcept;

            /**
             * @brief Converts the vector to its string representation
             */
            operator std::string() const;

            /**
             * @brief Checks whether this is the zero vector
             * 
             * @return `true` if all components are equal to zero, `false` otherwise
             */
            bool isZero() const noexcept;

            /**
             * @brief Computes the Euclidean norm of the vector
             * 
             * @return Euclidean norm (sqrt(x * x + y * y))
             */
            double magnitude() const noexcept;

            /**
             * @brief Returns the normalized vector
             * 
             * @return Unit vector
             */
            Vector2 normalize() const noexcept;

            /**
             * @brief Returns the magnitude limited vector
             * 
             * @param limit Maximum allowed magnitude
             * 
             * @return Limited vector
             */
            Vector2 limit(T limit) const noexcept;

            /**
             * @brief Rotates the vector around the origin (counter-clockwise standard)
             * 
             * @param angle Rotation angle in radians
             * 
             * @return Rotated vector
             */
            Vector2 rotate(double angle) const noexcept;

            /**
             * @brief Projects the vector onto another vector
             * 
             * @param other Vector onto which to project
             * 
             * @return Projected vector
             */
            Vector2 project(const Vector2& other) const noexcept;

    };

}


#include "Vector2.tpp"
