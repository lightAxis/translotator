#pragma once

namespace translotator
{
    // https://faculty.sites.iastate.edu/jia/files/inline-files/dual-quaternion.pdf

    template <typename Type>
    class DualQuaternion : public MatrixBase<8, 1, Type, DualQuaternion<Type>>
    {
    private:
        // Quaternion<Type> r_;
        // Quaternion<Type> d_;
        using MatrixBase<8, 1, Type, DualQuaternion<Type>>::data_;

    public:
        /**
         * constructor
         */
        using MatrixBase<8, 1, Type, DualQuaternion<Type>>::MatrixBase;
        DualQuaternion() = default;
        DualQuaternion(const Type &rw, const Type &rx, const Type &ry, const Type &rz,
                       const Type &dw, const Type &dx, const Type &dy, const Type &dz)
            : MatrixBase<8, 1, Type, DualQuaternion<Type>>({rw, rx, ry, rz, dw, dx, dy, dz}) {}
        DualQuaternion(const Quaternion<Type> &r, const Quaternion<Type> &d)
            : MatrixBase<8, 1, Type, DualQuaternion<Type>>{{r.w(), r.x(), r.y(), r.z(), d.w(), d.x(), d.y(), d.z()}} {}
        DualQuaternion(const Vector<8, Type> &vec)
            : MatrixBase<8, 1, Type, DualQuaternion<Type>>{{vec[0], vec[1], vec[2], vec[3], vec[4], vec[5], vec[6], vec[7]}} {}
        ~DualQuaternion() = default;

        /**
         * accessors
         */
        inline const Quaternion<Type> &real() const { return reinterpret_cast<const Quaternion<Type> &>(data_[0]); }
        inline const Quaternion<Type> &dual() const { return reinterpret_cast<const Quaternion<Type> &>(data_[4]); }
        inline Quaternion<Type> &real() { return reinterpret_cast<Quaternion<Type> &>(data_[0]); }
        inline Quaternion<Type> &dual() { return reinterpret_cast<Quaternion<Type> &>(data_[4]); }
        inline const Type &rw() const { return data_[0]; }
        inline const Type &rx() const { return data_[1]; }
        inline const Type &ry() const { return data_[2]; }
        inline const Type &rz() const { return data_[3]; }
        inline const Type &dw() const { return data_[4]; }
        inline const Type &dx() const { return data_[5]; }
        inline const Type &dy() const { return data_[6]; }
        inline const Type &dz() const { return data_[7]; }
        inline Type &rw() { return data_[0]; }
        inline Type &rx() { return data_[1]; }
        inline Type &ry() { return data_[2]; }
        inline Type &rz() { return data_[3]; }
        inline Type &dw() { return data_[4]; }
        inline Type &dx() { return data_[5]; }
        inline Type &dy() { return data_[6]; }
        inline Type &dz() { return data_[7]; }
        inline const Type &operator[](const int &idx) const { return data_[idx]; }
        inline Type &operator[](const int &idx) { return data_[idx]; }

        /**
         * operators
         */
        // inline DualQuaternion<Type> operator+(const DualQuaternion<Type> &other) const
        // {
        //     return DualQuaternion<Type>(r_ + other.r_, d_ + other.d_);
        // }
        // inline DualQuaternion<Type> operator-(const DualQuaternion<Type> &other) const
        // {
        //     return DualQuaternion<Type>(r_ - other.r_, d_ - other.d_);
        // }
        // inline DualQuaternion<Type> operator*(const DualQuaternion<Type> &other) const
        // {
        //     return DualQuaternion<Type>(r_ * other.r_, r_ * other.d_ + d_ * other.r_);
        // }
        // inline void operator+=(const DualQuaternion<Type> &other) { *this = *this + other; }
        // inline void operator-=(const DualQuaternion<Type> &other) { *this = *this - other; }
        // inline void operator*=(const DualQuaternion<Type> &other) { *this = *this * other; }

        // /**
        //  * utils
        //  */
        // inline DualQuaternion<Type> conjugatedPrimary() const
        // {
        //     return DualQuaternion<Type>{r_.conjugated(), d_.conjugated()};
        // }
        // inline DualQuaternion<Type> conjugatedDual() const
        // {
        //     return DualQuaternion<Type>{r_, -d_};
        // }
        // inline DualQuaternion<Type> conjugatedFull() const
        // {
        //     return DualQuaternion<Type>{r_.conjugated(), -d_.conjugated()};
        // }
        // inline void conjugatePrimary() { *this = conjugatedPrimary(); }
        // inline void conjugateDual() { *this = conjugatedDual(); }
        // inline void conjugateFull() { *this = conjugatedFull(); }

        // // TODO norm's return is dual number
        // // inline Type norm();

        // inline DualQuaternion<Type> normalized() const // norm 1 can only available in conjugated primary
        // {
        //     return DualQuaternion<Type>{r_.normalized(),
        //                                 Quaternion<Type>{static_cast<Type>(0), (d_ * r_.conjugated()).Im()} * r_};
        // }
        // inline void normalize() { *this = normalized(); }
        // inline void print() const
        // {
        //     r_.print();
        //     d_.print();
        // }

        // /**
        //  * static functions
        //  */
        // static DualQuaternion<Type> zeros() { return DualQuaternion<Type>(Quaternion<Type>::zeros(), Quaternion<Type>::zeros()); }

        // /**
        //  * casts
        //  */
        // inline Vector<8, Type> toVector() const
        // {
        //     return Vector<8, Type>{{r_.w(), r_.x(), r_.y(), r_.z(),
        //                             d_.w(), d_.x(), d_.y(), d_.z()}};
        // }

        // inline SquareMatrix<8, Type> toMulMatrix() const
        // {
        //     // | [r]_x    0  |
        //     // | [d]_x [r]_x |
        //     const Type zero___ = static_cast<Type>(0);
        //     return SquareMatrix<8, Type>{{r_.w(), -r_.x(), -r_.y(), -r_.z(), zero___, zero___, zero___, zero___,
        //                                   r_.x(), +r_.w(), -r_.z(), +r_.y(), zero___, zero___, zero___, zero___,
        //                                   r_.y(), +r_.z(), +r_.w(), -r_.x(), zero___, zero___, zero___, zero___,
        //                                   r_.z(), -r_.y(), +r_.x(), +r_.w(), zero___, zero___, zero___, zero___,
        //                                   d_.w(), -d_.x(), -d_.y(), -d_.z(), +r_.w(), -r_.x(), -r_.y(), -r_.z(),
        //                                   d_.x(), +d_.w(), -d_.z(), +d_.y(), +r_.x(), +r_.w(), -r_.z(), +r_.y(),
        //                                   d_.y(), +d_.z(), +d_.w(), -d_.x(), +r_.y(), +r_.z(), +r_.w(), -r_.x(),
        //                                   d_.z(), -d_.y(), +d_.x(), +d_.w(), +r_.z(), -r_.y(), +r_.x(), +r_.w()}};
        // }
        // inline SquareMatrix<8, Type> toRightMulMatrix() const
        // {
        //     // | [r]_xr    0   |
        //     // | [d]_xr [r]_xr |
        //     const Type zero___ = static_cast<Type>(0);
        //     return SquareMatrix<8, Type>{{r_.w(), -r_.x(), -r_.y(), -r_.z(), zero___, zero___, zero___, zero___,
        //                                   r_.x(), +r_.w(), +r_.z(), -r_.y(), zero___, zero___, zero___, zero___,
        //                                   r_.y(), -r_.z(), +r_.w(), +r_.x(), zero___, zero___, zero___, zero___,
        //                                   r_.z(), +r_.y(), -r_.x(), +r_.w(), zero___, zero___, zero___, zero___,
        //                                   d_.w(), -d_.x(), -d_.y(), -d_.z(), +r_.w(), +r_.x(), +r_.y(), -r_.z(),
        //                                   d_.x(), +d_.w(), +d_.z(), -d_.y(), -r_.x(), +r_.w(), +r_.z(), +r_.y(),
        //                                   d_.y(), -d_.z(), +d_.w(), +d_.x(), -r_.y(), +r_.z(), +r_.w(), +r_.x(),
        //                                   d_.z(), +d_.y(), -d_.x(), +d_.w(), -r_.z(), -r_.y(), -r_.x(), +r_.w()}};
        // }
    };

    using DualQuaternionf = DualQuaternion<float>;
    using DualQuaterniond = DualQuaternion<double>;
    using DualQuaternionld = DualQuaternion<long double>;
}