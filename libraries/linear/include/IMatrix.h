////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  [projectName]
//  File:     IMatrix.h (linear)
//  Authors:  Ofer Dekel
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "types.h"

#include "Base.h"

#include <vector>

namespace linear
{
    /// Base class for matrices of double numbers
    ///
    class IMatrix : public Base
    {
    public:

        /// \returns The number of rows in the matrix
        ///
        virtual uint64 NumRows() const = 0;

        /// \returns The number of columns in the matrix
        ///
        virtual uint64 NumColumns() const = 0;

        /// Performs a general matrix std::vector product: y = alpha * M * x + beta * y
        ///
        void Gemv(const std::vector<double>& x, std::vector<double>& y, double alpha = 1.0, double beta = 0.0) const;

        /// Performs a general matrix std::vector product: y = alpha * M * x + beta * y
        ///
        virtual void Gemv(const double* p_x, double* p_y, double alpha = 1.0, double beta = 0.0) const =0;

        /// Performs a general std::vector matrix product: y = alpha * x * M + beta * y
        ///
        void Gevm(const std::vector<double>& x, std::vector<double>& y, double alpha = 1.0, double beta = 0.0) const;

        /// Performs a general std::vector matrix product: y = alpha * x * M + beta * y
        ///
        virtual void Gevm(const double* p_x, double* p_y, double alpha = 1.0, double beta = 0.0) const =0;
    };
}
