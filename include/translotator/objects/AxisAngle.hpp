#pragma once

namespace translotator
{
    template <typename Type = TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE>
    class AxisAngle
    {
    private:
        Type angle_;
        Vector<3, Type> axis_;

    public:
        /**
         * Constructors
         */
        inline AxisAngle(const Type &angle, const Type &x, const Type &y, const Type &z) : angle_(angle), axis_({x, y, z}) {}
        explicit inline AxisAngle(const Type &angle, const Vector<3, Type> &axis) : angle_(angle), axis_(axis.normalized()) {}
        explicit inline AxisAngle(const Type &angle) : angle_(angle), axis_(Vector<3, Type>::zAxis()) {} // for 2d rotation

        /**
         * static functions
         */
        static inline AxisAngle<Type> identity() { return AxisAngle<Type>(static_cast<Type>(0), static_cast<Type>(1), static_cast<Type>(0), static_cast<Type>(0)); }

        /**
         * accessors
         */
        inline Type angle() const { return angle_; }
        inline Type &angle() { return angle_; }
        inline const Vector<3, Type> &axis() const { return axis_; }
        inline Vector<3, Type> &axis() { return axis_; }
        inline Type x() const { return axis_.x(); }
        inline Type y() const { return axis_.y(); }
        inline Type z() const { return axis_.z(); }
        inline Type &x() { return axis_.x(); }
        inline Type &y() { return axis_.y(); }
        inline Type &z() { return axis_.z(); }

        /**
         * Utils
         */
        inline void axisNormalize() { axis_.normalize(); }
        inline AxisAngle axisNormalized() const { return AxisAngle<Type>(angle_, axis_.normalized()); }
        inline void inverse() { angle_ = -angle_; }
        inline AxisAngle inversed() const { return AxisAngle<Type>(-angle_, axis_); }
        inline Vector<3, Type> rotateVector3D(const Vector<3, Type> &v) const
        {
            return (*this).toUnitQuaternion().rotateVector3D(v);
        }
        inline Vector<2, Type> rotateVector2D(const Vector<2, Type> &v) const
        {
            const Type c = translotator::cos(angle_);
            const Type s = translotator::sin(angle_);
            return SquareMatrix<2, Type>{{c * v.x() - s * v.y(),
                                          s * v.x() + c * v.y()}};
        }

        /**
         * Casting
         */
        inline UnitQuaternion<Type> toUnitQuaternion() const
        {
            const Type half_angle = angle_ / static_cast<Type>(2);
            const Vector<3, Type> axis_normalized = axis_.normalized();
            return UnitQuaternion<Type>(translotator::cos(half_angle),
                                        translotator::sin(half_angle) * axis_normalized);
        }
        inline UnitComplexNum<Type> toUnitComplexNum() const
        {
            return UnitComplexNum{translotator::cos(angle_), translotator::sin(angle_)};
        }
        inline SquareMatrix<3, Type> toRotMatrix3D() const
        {
            return (*this).toUnitQuaternion().toRotMatrix3D();
        }
        inline SquareMatrix<2, Type> toRotMatrix2D() const
        {
            const Type c = translotator::cos(angle_);
            const Type s = translotator::sin(angle_);
            return SquareMatrix<2, Type>{{+c, -s,
                                          +s, +c}};
        }

    private:
    };

    using AxisAnglef = AxisAngle<float>;
    using AxisAngled = AxisAngle<double>;
    using AxisAnglei = AxisAngle<int>;
}