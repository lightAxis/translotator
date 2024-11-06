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
    inline Matrix<N, M, Type> MatrixBase<N, M, Type, Derived>::toMatrix() const
    {
        return castContainer<Matrix<N, M, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline SquareMatrix<N, Type> MatrixBase<N, M, Type, Derived>::toSquareMatrix() const
    {
        return castContainer<SquareMatrix<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline Vector<N, Type> MatrixBase<N, M, Type, Derived>::toVector() const
    {
        return castContainer<Vector<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline ComplexNum<Type> MatrixBase<N, M, Type, Derived>::toComplexNum() const
    {
        return castContainer<ComplexNum<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitComplexNum<Type> MatrixBase<N, M, Type, Derived>::toUnitComplexNum() const
    {
        UnitComplexNum<Type> c = castContainer<UnitComplexNum<Type>>();
        c.normalize();
        return c;
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline Quaternion<Type> MatrixBase<N, M, Type, Derived>::toQuaternion() const
    {
        return castContainer<Quaternion<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitQuaternion<Type> MatrixBase<N, M, Type, Derived>::toUnitQuaternion() const
    {
        UnitQuaternion<Type> q = castContainer<UnitQuaternion<Type>>();
        q.normalize();
        return q;
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
    inline Matrix<N, M, Type> &MatrixBase<N, M, Type, Derived>::toMatrixRef()
    {
        return castContainerRef<Matrix<N, M, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline SquareMatrix<N, Type> &MatrixBase<N, M, Type, Derived>::toSquareMatrixRef()
    {
        return castContainerRef<SquareMatrix<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline Vector<N, Type> &MatrixBase<N, M, Type, Derived>::toVectorRef()
    {
        return castContainerRef<Vector<N, Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline ComplexNum<Type> &MatrixBase<N, M, Type, Derived>::toComplexNumRef()
    {
        return castContainerRef<ComplexNum<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitComplexNum<Type> &MatrixBase<N, M, Type, Derived>::toUnitComplexNumRef()
    {
        auto &c = castContainerRef<UnitComplexNum<Type>>();
        c.normalize();
        return c;
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline Quaternion<Type> &MatrixBase<N, M, Type, Derived>::toQuaternionRef()
    {
        return castContainerRef<Quaternion<Type>>();
    }
    template <size_t N, size_t M, typename Type, typename Derived>
    template <size_t N_, size_t M_, typename>
    inline UnitQuaternion<Type> &MatrixBase<N, M, Type, Derived>::toUnitQuaternionRef()
    {
        auto &q = castContainerRef<UnitQuaternion<Type>>();
        q.normalize();
        return q;
    }

}
