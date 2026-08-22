/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <stdexcept>

#include "Matrix.hpp"


namespace tbaricault::math
{

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> Matrix<R, C, T>::identity() noexcept requires (R == C)
    {
        Matrix result;
        for (std::size_t i = 0; i < R; i++)
            result._data[i][i] = 1;
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> Matrix<R, C, T>::hadamard(const Matrix<R, C, T>& a, const Matrix<R, C, T>& b) noexcept
    {
        Matrix result;
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                result._data[i][j] = a._data[i][j] * b._data[i][j];
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T>::Matrix() noexcept
    {
        this->fill(T{});
        return;
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T>::Matrix(T value) noexcept
    {
        this->fill(value);
        return;
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T>::Matrix(std::initializer_list<std::initializer_list<T>> init)
    {
        std::size_t i = 0;
        for (auto it = init.begin(); it != init.end(); it++)
            std::copy(it->begin(), it->end(), this->_data[i++]);
        return;
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T>& Matrix<R, C, T>::operator+=(const Matrix& other) noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                this->_data[i][j] += other._data[i][j];
        return (*this);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T>& Matrix<R, C, T>::operator+=(T other) noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                this->_data[i][j] += other;
        return (*this);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T>& Matrix<R, C, T>::operator-=(const Matrix& other) noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                this->_data[i][j] -= other._data[i][j];
        return (*this);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T>& Matrix<R, C, T>::operator-=(T other) noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                this->_data[i][j] -= other;
        return (*this);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T>& Matrix<R, C, T>::operator*=(const T other) noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                this->_data[i][j] *= other;
        return (*this);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T>& Matrix<R, C, T>::operator/=(const T other) noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                this->_data[i][j] /= other;
        return (*this);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> Matrix<R, C, T>::operator+(const Matrix& other) const noexcept
    {
        Matrix result;
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                result._data[i][j] = this->_data[i][j] + other._data[i][j];
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> Matrix<R, C, T>::operator+(T other) const noexcept
    {
        Matrix result;
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                result._data[i][j] = this->_data[i][j] + other;
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> Matrix<R, C, T>::operator-(const Matrix& other) const noexcept
    {
        Matrix result;
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                result._data[i][j] = this->_data[i][j] - other._data[i][j];
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> Matrix<R, C, T>::operator-(T other) const noexcept
    {
        Matrix result;
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                result._data[i][j] = this->_data[i][j] - other;
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    template<std::size_t N>
    Matrix<R, N, T> Matrix<R, C, T>::operator*(const Matrix<C, N, T>& other) const noexcept
    {
        Matrix result;
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < N; j++)
                for (std::size_t k = 0; k < C; k++)
                    result._data[i][j] += this->_data[i][k] + other(k, j);
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> Matrix<R, C, T>::operator*(T other) const noexcept
    {
        Matrix result;
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                result._data[i][j] = this->_data[i][j] * other;
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> Matrix<R, C, T>::operator/(T other) const noexcept
    {
        Matrix result;
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                result._data[i][j] = this->_data[i][j] / other;
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    bool Matrix<R, C, T>::operator==(const Matrix& other) const noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                if (this->_data[i][j] != other._data[i][j])
                    return (false);
        return (true);
    }

    template<std::size_t R, std::size_t C, typename T>
    bool Matrix<R, C, T>::operator!=(const Matrix& other) const noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                if (this->_data[i][j] == other._data[i][j])
                    return (false);
        return (true);
    }

    template<std::size_t R, std::size_t C, typename T>
    T Matrix<R, C, T>::operator()(std::size_t i, std::size_t j) const
    {
        if (i >= R || j >= C)
            throw std::out_of_range("matrix index out of range");
        return (this->_data[i][j]);
    }

    template<std::size_t R, std::size_t C, typename T>
    T& Matrix<R, C, T>::operator()(std::size_t i, std::size_t j)
    {
        if (i >= R || j >= C)
            throw std::out_of_range("matrix index out of range");
        return (this->_data[i][j]);
    }

    template<std::size_t R, std::size_t C, typename T>
    bool Matrix<R, C, T>::isZero() const noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                if (this->_data[i][j] != 0)
                    return (false);
        return (true);
    }

    template<std::size_t R, std::size_t C, typename T>
    bool Matrix<R, C, T>::isIdentity() const noexcept requires (R == C)
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                if ((i == j && this->_data[i][j] != 1) || this->_data[i][j] != 0)
                    return (false);
        return (true);
    }

    template<std::size_t R, std::size_t C, typename T>
    std::size_t Matrix<R, C, T>::rows() const noexcept
    {
        return (R);
    }

    template<std::size_t R, std::size_t C, typename T>
    std::size_t Matrix<R, C, T>::columns() const noexcept
    {
        return (C);
    }

    template<std::size_t R, std::size_t C, typename T>
    T Matrix<R, C, T>::trace() const noexcept requires (R == C)
    {
        T result = T{};
        for (std::size_t i = 0; i < R; i++)
            result += this->_data[i][i];
        return (result);
    }

    template<std::size_t R, std::size_t C, typename T>
    double Matrix<R, C, T>::norm() const noexcept
    {
        T result = T{};
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                result += this->_data[i][j] * this->_data[i][j];
        return sqrt(result);
    }

    template<std::size_t R, std::size_t C, typename T>
    void Matrix<R, C, T>::fill(T value) noexcept
    {
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                this->_data[i][j] = value;
        return;
    }

    template<std::size_t R, std::size_t C, typename T>
    Matrix<C, R, T> Matrix<R, C, T>::transpose() const noexcept
    {
        Matrix<C, R, T> result;
        for (std::size_t i = 0; i < R; i++)
            for (std::size_t j = 0; j < C; j++)
                result[j][i] = this->_data[i][j];
        return (result);
    }

}
