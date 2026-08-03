/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include "Vector2.hpp"


namespace tbaricault::math
{

    /**
     * @brief Three-dimensional vector
     * 
     * @tparam T Component type
     */
    template<typename T>
    class Vector3 final
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
             * @brief Z component
             */
            T z = T{};


            /**
             * @brief Returns the zero vector
             * 
             * @return (0, 0, 0)
             */
            static Vector3 zero() noexcept;

            /**
             * @brief Returns a vector whose components are all equal to one
             * 
             * @return (1, 1, 1)
             */
            static Vector3 one() noexcept;

            /**
             * @brief Returns the unit vector pointing left
             * 
             * @return (-1, 0, 0)
             */
            static Vector3 left() noexcept;

            /**
             * @brief Returns the unit vector pointing right
             * 
             * @return (1, 0, 0)
             */
            static Vector3 right() noexcept;

            /**
             * @brief Returns the unit vector pointing downward
             * 
             * @return (0, -1, 0)
             */
            static Vector3 down() noexcept;

            /**
             * @brief Returns the unit vector pointing upward
             * 
             * @return (0, 1, 0)
             */
            static Vector3 up() noexcept;

            /**
             * @brief Returns the unit vector pointing backwards
             * 
             * @return (0, 0, -1)
             */
            static Vector3 backward() noexcept;

            /**
             * @brief Returns the unit vector pointing forward
             * 
             * @return (0, 0, 1)
             */
            static Vector3 forward() noexcept;

            /**
             * @brief Computes the Hadamard (element-wise) product of two vectors
             * 
             * @param a First vector
             * @param b Second vector
             * 
             * @return Component-wise product
             */
            static Vector3 hadamard(const Vector3& a, const Vector3& b) noexcept;

            /**
             * @brief Computes the cross product of two vector
             * 
             * The resulting vector is perpendicular to both input vectors.
             * Its direction is determined by the right-hand rule.
             * Its magnitude is equals to the area of the parallelogram spanned by the two vectors.
             * 
             * @param a First vector
             * @param b Second vector
             * 
             * @result Cross product
             */
            static Vector3 cross(const Vector3& a, const Vector3& b) noexcept;

            /**
             * @brief Computes the Euclidean distance between two points
             * 
             * @param a First point
             * @param b Second point
             * 
             * @return Distance
             */
            static double distance(const Vector3& a, const Vector3& b) noexcept;

            /**
             * @brief Computes the angle between two vectors
             * 
             * @param a First vector
             * @param b Second vector
             * 
             * @return Angle in radians
             */
            static double angle(const Vector3& a, const Vector3& b) noexcept;

            /**
             * @brief Constructs the zero vector
             */
            Vector3() noexcept = default;

            /**
             * @brief Copy constructor
             * 
             * @param other Vector to copy
             */
            Vector3(const Vector3& other) noexcept = default;

            /**
             * @brief Move constructor
             * 
             * @param other Vector to move
             */
            Vector3(Vector3&& other) noexcept = default;

            /**
             * @brief Constructs a vector with all components initialized to the same value
             * 
             * @param value Component value
             */
            Vector3(T value) noexcept;

            /**
             * @brief Constructs a vector from its components
             * 
             * @param x X component
             * @param y Y component
             * @param z Z component
             */
            Vector3(T x, T y, T z) noexcept;

            /**
             * @brief Constructs a three-dimensional vector expanding a @ref Vector2
             * 
             * @param v Vector to expand
             * @param z Z component
             */
            Vector3(const Vector2<T>& v, T z) noexcept;

            /**
             * @brief Constructs a vector by converting another @ref Vector3
             *
             * @tparam U Source component type
             * 
             * @param other Vector to convert
             */
            template<typename U>
            Vector3(const Vector3<U>& other);

            /**
             * @brief Destructor
             */
            ~Vector3() noexcept = default;

            /**
             * @brief Copy assignment operator
             * 
             * @param other Vector to copy
             * 
             * @return Reference to this vector
             */
            Vector3& operator=(const Vector3& other) noexcept = default;

            /**
             * @brief Move assignment operator
             * 
             * @param other Vector to move
             * 
             * @return Reference to this vector
             */
            Vector3& operator=(Vector3&& other) noexcept = default;

            /**
             * @brief Adds another vector component-wise
             * 
             * @param other Vector to add
             * 
             * @return Reference to this vector
             */
            Vector3& operator+=(const Vector3& other) noexcept;

            /**
             * @brief Adds a scalar value to each component
             * 
             * @param other Scalar to add
             * 
             * @return Reference to this vector
             */
            Vector3& operator+=(T other) noexcept;

            /**
             * @brief Subtracts another vector component-wise
             * 
             * @param other Vector to subtract
             * 
             * @return Reference to this vector
             */
            Vector3& operator-=(const Vector3& other) noexcept;

            /**
             * @brief Subtracts a scalar value to each component
             * 
             * @param other Scalar to subtract
             * 
             * @return Reference to this vector
             */
            Vector3& operator-=(T other) noexcept;

            /**
             * @brief Multiplies each component by a scalar
             * 
             * @param other Scalar multiplier
             * 
             * @return Reference to this vector
             */
            Vector3& operator*=(T other) noexcept;

            /**
             * @brief Divides each component by a scalar
             * 
             * @param other Scalar divisor
             * 
             * @return Reference to this vector
             */
            Vector3& operator/=(T other) noexcept;

            /**
             * @brief Component-wise addition of two vectors
             * 
             * @param other Vector to add
             * 
             * @return Resulting vector
             */
            Vector3 operator+(const Vector3& other) const noexcept;

            /**
             * @brief Adds a scalar to each component of a vector
             * 
             * @param other Scalar to add
             * 
             * @return Resulting vector
             */
            Vector3 operator+(T other) const noexcept;

            /**
             * @brief Component-wise subtraction of two vectors
             * 
             * @param other Vector to subtract
             * 
             * @return Resulting vector
             */
            Vector3 operator-(const Vector3& other) const noexcept;

            /**
             * @brief Subtracts a scalar to each component of a vector
             * 
             * @param other Scalar to subtract
             * 
             * @return Resulting vector
             */
            Vector3 operator-(T other) const noexcept;

            /**
             * @brief Returns the negation of the vector
             * 
             * @return (-x, -y, -z)
             */
            Vector3 operator-() const noexcept;

            /**
             * @brief Computes the dot product of two vectors
             * 
             * @param other Second vector
             * 
             * @return Dot product (ax * bx + ay * by + az * bz)
             */
            T operator*(const Vector3& other) const noexcept;

            /**
             * @brief Multiplies each component of a vector by a scalar
             * 
             * @param other Scalar multiplier
             * 
             * @return Resulting vector
             */
            Vector3 operator*(T other) const noexcept;

            /**
             * @brief Divides each component of a vector by a scalar
             * 
             * @param other Scalar divisor
             * 
             * @return Resulting vector
             */
            Vector3 operator/(T other) const noexcept;

            /**
             * @brief Checks whether two vectors are equal
             * 
             * @param other Vector to compare with
             * 
             * @return `true` if both vector are equal, `false` otherwise
             */
            bool operator==(const Vector3& other) const noexcept;

            /**
             * @brief Checks whether two vectors are different
             * 
             * @param other Vector to compare with
             * 
             * @return `true` if vectors differ, `false` otherwise
             */
            bool operator!=(const Vector3& other) const noexcept;

            /**
             * @brief Checks whether this is the zero vector
             * 
             * @return `true` if all components are equal to zero, `false` otherwise
             */
            bool isZero() const noexcept;

            /**
             * @brief Computes the Euclidean norm of the vector
             * 
             * @return Euclidean norm (sqrt(x * x + y * y + z * z))
             */
            double magnitude() const noexcept;

            /**
             * @brief Returns the normalized vector
             * 
             * @return Unit vector
             */
            Vector3 normalize() const noexcept;

            /**
             * @brief Returns the magnitude limited vector
             * 
             * @param limit Maximum allowed magnitude
             * 
             * @return Limited vector
             */
            Vector3 limit(const T) const noexcept;

            /**
             * @brief Projects the vector onto another vector
             * 
             * @param other Vector onto which to project
             * 
             * @return Projected vector
             */
            Vector3 project(const Vector3&) const noexcept;

    };

}


#include "Vector3.tpp"
