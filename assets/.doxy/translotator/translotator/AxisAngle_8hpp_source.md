

# File AxisAngle.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**objects**](dir_d5306d4012edd8106bd4452d9b4e4e98.md) **>** [**AxisAngle.hpp**](AxisAngle_8hpp.md)

[Go to the documentation of this file](AxisAngle_8hpp.md)


```C++
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
 * @file : AxisAngle.hpp
 */

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
        constexpr static ObjectType OBJECT_TYPE = ObjectType::AXIS_ANGLE;
        inline AxisAngle(const Type &angle, const Type &x, const Type &y, const Type &z) : angle_(angle), axis_({x, y, z}) {}
        explicit inline AxisAngle(const Type &angle, const Vector<3, Type> &axis) : angle_(angle), axis_(axis.normalized()) {}
        explicit inline AxisAngle(const Type &angle) : angle_(angle), axis_(Vector<3, Type>::zAxis()) {}                              // for 2d rotation
        explicit inline AxisAngle(const Vector<3, Type> &angleVector) : angle_(static_cast<Type>(0)), axis_(Vector<3, Type>::zeros()) //
        {
            const Type normsq = angleVector.normSquared();
            if (normsq <= translotator::epsilon<Type>())
            {
                angle_ = static_cast<Type>(0);
                axis_ = Vector<3, Type>::xAxis();
            }
            else
            {
                angle_ = translotator::sqrt(normsq);
                axis_ = angleVector.normalized();
            }
        }

        static inline AxisAngle<Type> identity() { return AxisAngle<Type>(static_cast<Type>(0), static_cast<Type>(1), static_cast<Type>(0), static_cast<Type>(0)); }

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
        template <AXIS Axis>
        inline AxisAngle<Type> axisRotation(const Type &angle) const 
        {
            if constexpr (Axis == AXIS::X)
                return AxisAngle<Type>(angle, Vector<3, Type>::xAxis());
            else if constexpr (Axis == AXIS::Y)
                return AxisAngle<Type>(angle, Vector<3, Type>::yAxis());
            else if constexpr (Axis == AXIS::Z)
                return AxisAngle<Type>(angle, Vector<3, Type>::zAxis());
            else
                static_assert(Axis == AXIS::X || Axis == AXIS::Y || Axis == AXIS::Z, "Invalid Axis");
        }

        inline UnitQuaternion<Type> toUnitQuaternion() const 
        {
            const Type half_angle = angle_ / static_cast<Type>(2);
            const Vector<3, Type> axis_normalized = axis_.normalized();
            return UnitQuaternion<Type>(translotator::cos(half_angle),
                                        translotator::sin(half_angle) * axis_normalized)
                .canonicalized();
        }
        inline UnitComplexNum<Type> toUnitComplexNum() const 
        {
            return UnitComplexNum{translotator::cos(angle_), translotator::sin(angle_)};
        }
        inline SOGroup<3, Type> toRotMatrix3D() const 
        {
            return toUnitQuaternion().toRotMatrix3D();
        }
        inline SOGroup<2, Type> toRotMatrix2D() const 
        {
            const Type c = translotator::cos(angle_);
            const Type s = translotator::sin(angle_);
            return SOGroup<2, Type>{{+c, -s,
                                     +s, +c}};
        }
        inline Vector<3, Type> toAngleVector() const 
        {
            return axis_ * angle_;
        }
        template <EULER_ORDER AxisOrder>
        inline EulerAngle<Type, AxisOrder> toEulerAngle2D() const 
        {
            return toRotMatrix2D().template toEulerAngle<AxisOrder>();
        }
        template <EULER_ORDER AxisOrder>
        inline EulerAngle<Type, AxisOrder> toEulerAngle3D() const 
        {
            return toRotMatrix3D().template toEulerAngle<AxisOrder>();
        }
        template <typename NewType>
        inline AxisAngle<NewType> castDataType() const 
        {
            static_assert(is_float_v<NewType>, "NewType must be float, double or long double type");
            return AxisAngle<NewType>(static_cast<NewType>(angle_), axis_.template castDataType<NewType>());
        }

    private:
    };

    using AxisAnglef = AxisAngle<float>;
    using AxisAngled = AxisAngle<double>;
    using AxisAngleld = AxisAngle<long double>;
}
```


