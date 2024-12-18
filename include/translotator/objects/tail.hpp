/*
 * The MIT License (MIT)
 * Copyright (c) 2024 Jiseok Lee
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Created on Tue Nov 19 2024
 * @file : tail.hpp
 */

#pragma once

namespace translotator
{
    // ################################
    // ### MatrixBase castContainer ###
    // ################################

    template <size_t N, size_t M, typename Type, typename Derived>
    template <typename NewContainer>
    inline NewContainer MatrixBase<N, M, Type, Derived>::castContainer() const
    {
        static_assert(NewContainer::ROWS == N, "Matrix dimensions must be the same");
        static_assert(NewContainer::COLS == M, "Matrix dimensions must be the same");
        static_assert(is_same_v<typename NewContainer::DATATYPE, Type>, "Matrix data types must be the same");
        return *reinterpret_cast<const NewContainer *>(this);
    };
    template <size_t N, size_t M, typename Type, typename Derived>
    inline Matrix<N, M, Type> MatrixBase<N, M, Type, Derived>::cast2Matrix() const
    {
        return castContainer<Matrix<N, M, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline SquareMatrix<N, Type> MatrixBase<N, M, Type, Derived>::cast2SquareMatrix() const
    {
        return castContainer<SquareMatrix<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline Vector<N, Type> MatrixBase<N, M, Type, Derived>::cast2Vector() const
    {
        return castContainer<Vector<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline ComplexNum<Type> MatrixBase<N, M, Type, Derived>::cast2ComplexNum() const
    {
        return castContainer<ComplexNum<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitComplexNum<Type> MatrixBase<N, M, Type, Derived>::cast2UnitComplexNum() const
    {
        UnitComplexNum<Type> c = castContainer<UnitComplexNum<Type>>();
        c.normalize();
        return c;
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline Quaternion<Type> MatrixBase<N, M, Type, Derived>::cast2Quaternion() const
    {
        return castContainer<Quaternion<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitQuaternion<Type> MatrixBase<N, M, Type, Derived>::cast2UnitQuaternion() const
    {
        UnitQuaternion<Type> q = castContainer<UnitQuaternion<Type>>();
        q.normalize();
        return q;
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline SOGroup<N, Type> MatrixBase<N, M, Type, Derived>::cast2SOGroup() const
    {
        SOGroup<N, Type> so = castContainer<SOGroup<N, Type>>();
        so.normalize();
        return so;
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline DualNumber<Type> MatrixBase<N, M, Type, Derived>::cast2DualNumber() const
    {
        return castContainer<DualNumber<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline DualQuaternion<Type> MatrixBase<N, M, Type, Derived>::cast2DualQuaternion() const
    {
        return castContainer<DualQuaternion<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitDualQuaternion<Type> MatrixBase<N, M, Type, Derived>::cast2UnitDualQuaternion() const
    {
        UnitDualQuaternion<Type> udq = castContainer<UnitDualQuaternion<Type>>();
        udq.normalize();
        return udq;
    }

    // ###################################
    // ### MatrixBase castContainerRef ###
    // ###################################

    template <size_t N, size_t M, typename Type, typename Derived>
    template <typename NewDerived>
    inline NewDerived &MatrixBase<N, M, Type, Derived>::castContainerRef()
    {
        static_assert(NewDerived::ROWS == N, "Matrix dimensions must be the same");
        static_assert(NewDerived::COLS == M, "Matrix dimensions must be the same");
        static_assert(is_same_v<typename NewDerived::DATATYPE, Type>, "Matrix data types must be the same");

        return *reinterpret_cast<NewDerived *>(this);
    };
    template <size_t N, size_t M, typename Type, typename Derived>
    inline Matrix<N, M, Type> &MatrixBase<N, M, Type, Derived>::cast2MatrixRef()
    {
        return castContainerRef<Matrix<N, M, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline SquareMatrix<N, Type> &MatrixBase<N, M, Type, Derived>::cast2SquareMatrixRef()
    {
        return castContainerRef<SquareMatrix<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline Vector<N, Type> &MatrixBase<N, M, Type, Derived>::cast2VectorRef()
    {
        return castContainerRef<Vector<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline ComplexNum<Type> &MatrixBase<N, M, Type, Derived>::cast2ComplexNumRef()
    {
        return castContainerRef<ComplexNum<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitComplexNum<Type> &MatrixBase<N, M, Type, Derived>::cast2UnitComplexNumRef()
    {
        auto &c = castContainerRef<UnitComplexNum<Type>>();
        c.normalize();
        return c;
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline Quaternion<Type> &MatrixBase<N, M, Type, Derived>::cast2QuaternionRef()
    {
        return castContainerRef<Quaternion<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitQuaternion<Type> &MatrixBase<N, M, Type, Derived>::cast2UnitQuaternionRef()
    {
        auto &q = castContainerRef<UnitQuaternion<Type>>();
        q.normalize();
        return q;
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline SOGroup<N, Type> &MatrixBase<N, M, Type, Derived>::cast2SOGroupRef()
    {
        auto &so = castContainerRef<SOGroup<N, Type>>();
        so.normalize();
        return so;
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline DualNumber<Type> &MatrixBase<N, M, Type, Derived>::cast2DualNumberRef()
    {
        return castContainerRef<DualNumber<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline DualQuaternion<Type> &MatrixBase<N, M, Type, Derived>::cast2DualQuaternionRef()
    {
        return castContainerRef<DualQuaternion<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitDualQuaternion<Type> &MatrixBase<N, M, Type, Derived>::cast2UnitDualQuaternionRef()
    {
        auto &udq = castContainerRef<UnitDualQuaternion<Type>>();
        udq.normalize();
        return udq;
    }

}