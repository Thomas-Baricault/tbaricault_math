/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <cstddef>
#include <initializer_list>


namespace tbaricault::math
{

    /**
     * @brief Fixed-size matrix class
     * 
     * @tparam R Number of rows
     * @tparam C Number of columns
     * @tparam T Element type
     */
    template<std::size_t R, std::size_t C, typename T>
    class Matrix final
    {

        public:

            /**
             * @brief Creates an identity matrix
             * 
             * @return Identity matrix
             * 
             * @note Only valid for square matrices (R == C)
             */
            static Matrix identity() noexcept requires (R == C);

            /**
             * @brief Computes the Hadamard product (element-wise multiplication)
             * 
             * @param a First matrix
             * @param b Second matrix
             * 
             * @return Element-wise product of a and b
             */
            static Matrix hadamard(const Matrix&, const Matrix&) noexcept;

            /**
             * @brief Default constructor, initializes all elements to zero
             */
            Matrix() noexcept;

            /**
             * @brief Copy constructor
             * 
             * @param other Matrix to copy
             */
            Matrix(const Matrix& other) noexcept = default;

            /**
             * @brief Move constructor
             * 
             * @param other Matrix to move
             */
            Matrix(Matrix&& other) noexcept = default;

            /**
             * @brief Constructs a matrix filled with a constant value
             * 
             * @param value Value assigned to all elements
             */
            Matrix(T value) noexcept;

            /**
             * @brief Constructs a matrix from an initializer list
             * 
             * @param values Row-wise initializer list
             */
            Matrix(std::initializer_list<std::initializer_list<T>>);

            /**
             * @brief Destructor
             */
            ~Matrix() noexcept = default;

            /**
             * @brief Copy assignment operator
             * 
             * @param other Matrix to copy
             * 
             * @return Reference to this matrix
             */
            Matrix& operator=(const Matrix& other) noexcept = default;

            /**
             * @brief Move assignment operator
             * 
             * @param other Matrix to move
             * 
             * @return Reference to this matrix
             */
            Matrix& operator=(Matrix&& other) noexcept = default;

            /**
             * @brief Adds another matrix element-wise
             * 
             * @param other Matrix to add
             * 
             * @return Reference to this matrix
             */
            Matrix& operator+=(const Matrix& other) noexcept;

            /**
             * @brief Adds a scalar value to every element of the matrix
             * 
             * @param other Scalar value to add
             * 
             * @return Reference to this matrix
             */
            Matrix& operator+=(T other) noexcept;

            /**
             * @brief Subtracts another matrix element-wise
             * 
             * @param other Matrix to subtract
             * 
             * @return Reference to this matrix
             */
            Matrix& operator-=(const Matrix& other) noexcept;

            /**
             * @brief Subtracts a scalar value to every element of the matrix
             * 
             * @param other Scalar value to subtract
             * 
             * @return Reference to this matrix
             */
            Matrix& operator-=(T other) noexcept;

            /**
             * @brief Multiplies every element of the matrix by a scalar
             * 
             * @param other Scalar multiplier
             * 
             * @return Reference to this matrix
             */
            Matrix& operator*=(T other) noexcept;

            /**
             * @brief Divides every element of the matrix by a scalar
             * 
             * @param other Scalar divisor
             * 
             * @return Reference to this matrix
             */
            Matrix& operator/=(T other) noexcept;

            /**
             * @brief Element-wise addition of two matrixes
             * 
             * @param other Matrix to add
             * 
             * @return Resulting matrix
             */
            Matrix operator+(const Matrix& other) const noexcept;

            /**
             * @brief Adds a scalar to every element of a matrix
             * 
             * @param other Scalar to add
             * 
             * @return Resulting matrix
             */
            Matrix operator+(T other) const noexcept;

            /**
             * @brief Element-wise subtraction of two matrixes
             * 
             * @param other Matrix to subtract
             * 
             * @return Resulting matrix
             */
            Matrix operator-(const Matrix& other) const noexcept;

            /**
             * @brief Subtracts a scalar to every element of a matrix
             * 
             * @param other Scalar to subtract
             * 
             * @return Resulting matrix
             */
            Matrix operator-(T other) const noexcept;

            /**
             * @brief Matrix multiplication
             * 
             * @tparam N Number of columns of the right-hand matrix
             * 
             * @param other Matrix to multiply with
             * 
             * @return Resulting R × N matrix
             */
            template<std::size_t N>
            Matrix<R, N, T> operator*(const Matrix<C, N, T>& other) const noexcept;

            /**
             * @brief Multiplies every element of a matrix by a scalar
             * 
             * @param other Scalar multiplier
             * 
             * @return Resulting matrix
             */
            Matrix operator*(T other) const noexcept;

            /**
             * @brief Divides every element of a matrix by a scalar
             * 
             * @param other Scalar divisor
             * 
             * @return Resulting matrix
             */
            Matrix operator/(T other) const noexcept;

            /**
             * @brief Checks whether two matrixes are equal
             * 
             * @param other Matrix to compare with
             * 
             * @return `true` if both matrixes are equal, `false` otherwise
             */
            bool operator==(const Matrix& other) const noexcept;

            /**
             * @brief Checks whether two matrixes are different
             * 
             * @param other Matrix to compare with
             * 
             * @return `true` if matrixes differ, `false` otherwise
             */
            bool operator!=(const Matrix& other) const noexcept;

            /**
             * @brief Access element (read-only)
             * 
             * @param i Row index
             * @param j Column index
             * 
             * @return Element at (i, j)
             * 
             * @throws std::out_of_range If index (i, j) is out of range
             */
            T operator()(std::size_t i, std::size_t j) const;

            /**
             * @brief Access element (mutable)
             * 
             * @param i Row index
             * @param j Column index
             * 
             * @return Element at (i, j)
             * 
             * @throws std::out_of_range If index (i, j) is out of range
             */
            T& operator()(std::size_t i, std::size_t j);

            /**
             * @brief Checks whether all elements are zero
             * 
             * @return `true` if all elements are zero, `false` otherwise
             */
            bool isZero() const noexcept;

            /**
             * @brief Checks whether the matrix is an identity matrix
             * 
             * @return `true` if is an identity matrix, `false` otherwise
             * 
             * @note Only valid for square matrices (R == C)
             */
            bool isIdentity() const noexcept requires (R == C);

            /**
             * @brief Returns the number of rows in the matrix
             * 
             * @return Number of rows
             */
            std::size_t rows() const noexcept;

            /**
             * @brief Returns the number of columns in the matrix
             * 
             * @return Number of columns
             */
            std::size_t columns() const noexcept;

            /**
             * @brief Computes the trace of the matrix
             * 
             * @return Computed trace
             * 
             * @note Only valid for square matrices (R == C)
             */
            T trace() const noexcept requires (R == C);

            /**
             * @brief Computes the Frobenius norm of the matrix
             * 
             * @return Frobenius norm
             */
            double norm() const noexcept;

            /**
             * @brief Fills the matrix with a constant value
             * 
             * @param value Value to fill with
             */
            void fill(T value) noexcept;

            /**
             * @brief Computes the transposed matrix
             * 
             * @return Transposed matrix
             */
            Matrix<C, R, T> transpose() const noexcept;


        private:

            /**
             * @brief Matrix data
             */
            T _data[R][C];

    };

}


#include "Matrix.tpp"
