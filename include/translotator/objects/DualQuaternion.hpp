#pragma once

namespace translotator
{
    // https://faculty.sites.iastate.edu/jia/files/inline-files/dual-quaternion.pdf

    template <typename Type>
    class DualQuaternion
    {
    private:
        Quaternion<Type> r_;
        Quaternion<Type> d_;

    public:
        /**
         * constructor
         */
        DualQuaternion() = default;
        DualQuaternion(const Type &rw, const Type &rx, const Type &ry, const Type &rz,
                       const Type &dw, const Type &dx, const Type &dy, const Type &dz) : r_{rw, rx, ry, rz}, d_{dw, dx, dy, dz} {}
        DualQuaternion(const Quaternion<Type> &r, const Quaternion<Type> &d) : r_(r), d_(d) {}
        DualQuaternion(const Vector<8, Type> &vec) : r_{vec[0], vec[1], vec[2], vec[3]}, d_{vec[4], vec[5], vec[6], vec[7]} {}
        ~DualQuaternion() = default;

        /**
         * accessors
         */
        inline const Quaternion<Type> &real() const { return r_; }
        inline const Quaternion<Type> &dual() const { return d_; }
        inline Quaternion<Type> &real() { return r_; }
        inline Quaternion<Type> &dual() { return d_; }

        /**
         * operators
         */
        inline DualQuaternion<Type> operator+(const DualQuaternion<Type> &other) const
        {
            return DualQuaternion<Type>(r_ + other.r_, d_ + other.d_);
        }
        inline DualQuaternion<Type> operator-(const DualQuaternion<Type> &other) const
        {
            return DualQuaternion<Type>(r_ - other.r_, d_ - other.d_);
        }
        inline DualQuaternion<Type> operator*(const DualQuaternion<Type> &other) const
        {
            return DualQuaternion<Type>(r_ * other.r_, r_ * other.d_ + d_ * other.r_);
        }
        inline void operator+=(const DualQuaternion<Type> &other) { *this = *this + other; }
        inline void operator-=(const DualQuaternion<Type> &other) { *this = *this - other; }
        inline void operator*=(const DualQuaternion<Type> &other) { *this = *this * other; }

        /**
         * utils
         */
        inline DualQuaternion<Type> conjugatedPrimary() const
        {
            return DualQuaternion<Type>{r_.conjugated(), d_.conjugated()};
        }
        inline DualQuaternion<Type> conjutagedDual() const
        {
            return DualQuaternion<Type>{r_, -d_};
        }
        inline DualQuaternion<Type> conjugatedFull() const
        {
            return DualQuaternion<Type>{r_.conjugated(), -d_.conjugated()};
        }
        inline void conjugatePrimary() { *this = conjugatedPrimary(); }
        inline void conjugateDual() { *this = conjutagedDual(); }
        inline void conjugateFull() { *this = conjugatedFull(); }

        inline DualQuaternion<Type> normalized() const // norm 1 can only available in conjugated primary
        {
            return DualQuaternion<Type>{r_.normalized(),
                                        Quaternion<Type>{static_cast<Type>(0), (d_ * r_.conjugated()).Im()} * r_};
        }
        inline void normalize() { *this = normalized(); }

        /**
         * static functions
         */
        static DualQuaternion<Type> zeros() { return DualQuaternion<Type>(Quaternion<Type>::zeros(), Quaternion<Type>::zeros()); }

        /**
         * casts
         */
        inline Vector<8, Type> toVector() const
        {
            return Vector<8, Type>{{r_.w(), r_.x(), r_.y(), r_.z(),
                                    d_.w(), d_.x(), d_.y(), d_.z()}};
        }

        inline SquareMatrix<8, Type> toMulMatrix() const
        {
            // | [r]_x    0  |
            // | [d]_x [r]_x |
            const Type zero___ = static_cast<Type>(0);
            return SquareMatrix<8, Type>{{r_.w(), -r_.x(), -r_.y(), -r_.z(), zero___, zero___, zero___, zero___,
                                          r_.x(), +r_.w(), -r_.z(), +r_.y(), zero___, zero___, zero___, zero___,
                                          r_.y(), +r_.z(), +r_.w(), -r_.x(), zero___, zero___, zero___, zero___,
                                          r_.z(), -r_.y(), +r_.x(), +r_.w(), zero___, zero___, zero___, zero___,
                                          d_.w(), -d_.x(), -d_.y(), -d_.z(), +r_.w(), -r_.x(), -r_.y(), -r_.z(),
                                          d_.x(), +d_.w(), -d_.z(), +d_.y(), +r_.x(), +r_.w(), -r_.z(), +r_.y(),
                                          d_.y(), +d_.z(), +d_.w(), -d_.x(), +r_.y(), +r_.z(), +r_.w(), -r_.x(),
                                          d_.z(), -d_.y(), +d_.x(), +d_.w(), +r_.z(), -r_.y(), +r_.x(), +r_.w()}};
        }
        inline SquareMatrix<8, Type> toRightMulMatrix() const
        {
            // | [r]_xr    0   |
            // | [d]_xr [r]_xr |
            const Type zero___ = static_cast<Type>(0);
            return SquareMatrix<8, Type>{{r_.w(), -r_.x(), -r_.y(), -r_.z(), zero___, zero___, zero___, zero___,
                                          r_.x(), +r_.w(), +r_.z(), -r_.y(), zero___, zero___, zero___, zero___,
                                          r_.y(), -r_.z(), +r_.w(), +r_.x(), zero___, zero___, zero___, zero___,
                                          r_.z(), +r_.y(), -r_.x(), +r_.w(), zero___, zero___, zero___, zero___,
                                          d_.w(), -d_.x(), -d_.y(), -d_.z(), +r_.w(), +r_.x(), +r_.y(), -r_.z(),
                                          d_.x(), +d_.w(), +d_.z(), -d_.y(), -r_.x(), +r_.w(), +r_.z(), +r_.y(),
                                          d_.y(), -d_.z(), +d_.w(), +d_.x(), -r_.y(), +r_.z(), +r_.w(), +r_.x(),
                                          d_.z(), +d_.y(), -d_.x(), +d_.w(), -r_.z(), -r_.y(), -r_.x(), +r_.w()}};
        }
    };

    using DualQuaternionf = DualQuaternion<float>;
    using DualQuaterniond = DualQuaternion<double>;
    using DualQuaternionld = DualQuaternion<long double>;
}