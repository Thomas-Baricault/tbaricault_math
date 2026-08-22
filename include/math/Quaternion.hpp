/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include "Vector3.hpp"


namespace tbaricault::math
{

    /**
     * @brief Quaternion representing a 3D rotation
     * 
     * A quaternion is stored as four components (x, y, z, w), where (x, y, z) form the vector part and w is the scalar part.
     * Unit quaternions are commonly used to represent rotations in three-dimensional space.
     */
    class Quaternion final
    {

        public:

            /**
             * @brief X component
             */
            double x = 0;

            /**
             * @brief Y component
             */
            double y = 0;

            /**
             * @brief Z component
             */
            double z = 0;

            /**
             * @brief W component
             */
            double w = 1;


            /**
             * @brief Constructs a quaternion representing a rotation around an axis
             * 
             * @tparam T Vector component type
             * 
             * @param axis Rotation axis
             * @param angle Rotation angle in radians
             * 
             * @return Resulting quaternion
             */
            template<typename T>
            static Quaternion fromAxisAngle(const Vector3<T>& axis, double angle) noexcept;

            /**
             * @brief Constructs a quaternion from Euler angles
             * 
             * @param pitch Rotation about the X axis, in radians
             * @param yaw Rotation about the Y axis, in radians
             * @param roll Rotation about the Z axis, in radians
             * 
             * @return Resulting quaternion
             */
            static Quaternion fromEulerAngles(double pitch, double yaw, double roll) noexcept;

            /**
             * @brief Performs spherical linear interpolation between two quaternions
             * 
             * @param a Starting quaternion
             * @param b Ending quaternion
             * @param t Interpolation factor in the range [0, 1]
             * 
             * @return Resulting quaternion
             */
            static Quaternion slerp(const Quaternion& a, const Quaternion& b, double t) noexcept;

            /**
             * @brief Constructs the identity quaternion
             */
            Quaternion() noexcept = default;

            /**
             * @brief Copy constructor
             * 
             * @param other Quaternion to copy
             */
            Quaternion(const Quaternion& other) noexcept = default;

            /**
             * @brief Move constructor
             * 
             * @param other Quaternion to move
             */
            Quaternion(Quaternion&& other) noexcept = default;

            /**
             * @brief Constructs a quaternion from its components
             * 
             * @param x X component
             * @param y Y component
             */
            Quaternion(double x, double y, double z, double w) noexcept;

            /**
             * @brief Destructor
             */
            ~Quaternion() noexcept = default;

            /**
             * @brief Copy assignment operator
             * 
             * @param other Quaternion to copy
             * 
             * @return Reference to this quaternion
             */
            Quaternion& operator=(const Quaternion& other) noexcept = default;

            /**
             * @brief Move assignment operator
             * 
             * @param other Quaternion to move
             * 
             * @return Reference to this quaternion
             */
            Quaternion& operator=(Quaternion&& other) noexcept = default;

            /**
             * @brief Composes the rotation with another quaternion
             * 
             * @param other Second quaternion
             * 
             * @return Reference to this quaternion
             */
            Quaternion& operator*=(const Quaternion& other) noexcept;

            /**
             * @brief Composition of two quaternion
             * 
             * @param other Second quaternion
             * 
             * @return Resulting quaternion
             */
            Quaternion operator*(const Quaternion& other) const noexcept;

            /**
             * @brief Returns the inverse quaternion
             * 
             * @return Inverse quaternion
             */
            Quaternion inverse() const noexcept;

            /**
             * @brief Returns the normalized quaternion
             *
             * @return Unit quaternion
             */
            Quaternion normalize() const noexcept;

            /**
             * @brief Rotates a three-dimensional vector
             * 
             * @tparam T Vector component type
             * 
             * @param v Vector to rotate
             * 
             * @return Resulting vector
             */
            template<typename T>
            Vector3<T> rotate(const Vector3<T>& v) const noexcept;

    };

}


#include "Quaternion.tpp"
