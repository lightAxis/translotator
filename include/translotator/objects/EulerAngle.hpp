#pragma once

namespace translotator
{

    template <typename Type, EULER_ORDER AxisOrder = EULER_ORDER::ZYX>
    class EulerAngle
    {
    private:
        Type angles_[3];

    public:
        /**
         * constructor
         */
        EulerAngle() : angles_{0, 0, 0} {}
        explicit EulerAngle(const Type &angle) : angles_{0, 0, angle} {}
        EulerAngle(const Type &x, const Type &y, const Type &z) : angles_{x, y, z} {};
        explicit EulerAngle(const Vector<3, Type> &angles) : angles_{angles[0], angles[1], angles[2]} {};

        /**
         * accessor
         */
        inline Type x() const { return angles_[0]; }
        inline Type y() const { return angles_[1]; }
        inline Type z() const { return angles_[2]; }
        inline Type &x() { return angles_[0]; }
        inline Type &y() { return angles_[1]; }
        inline Type &z() { return angles_[2]; }

        inline Type operator[](size_t idx) const { return angles_[idx]; }
        inline Type &operator[](size_t idx) { return angles_[idx]; }

        inline Type roll() const { return x(); }
        inline Type pitch() const { return y(); }
        inline Type yaw() const { return z(); }
        inline Type &roll() { return x(); }
        inline Type &pitch() { return y(); }
        inline Type &yaw() { return z(); }

        template <size_t N>
        inline Type getAngleInOrder() const { return angles_[EULER_CONSTEXPR::AXIS_IDX_AT<N, AxisOrder>()]; }
        template <size_t N>
        inline Type &getAngleInOrder() { return angles_[EULER_CONSTEXPR::AXIS_IDX_AT<N, AxisOrder>()]; }
        template <size_t N>
        constexpr inline AXIS getAxisInOrder() const { return EULER_CONSTEXPR::AXIS_AT<N, AxisOrder>(); }

        /**
         * utils
         */
        // TODO utils
        inline Vector<2, Type> rotateVec2D(const Vector<2, Type> &vec) const
        {
            return toUnitComplexNum().rotateVector2D(vec);
        }
        inline Vector<3, Type> rotateVec3D(const Vector<3, Type> &vec) const
        {
            return toUnitQuaternion().rotateVector3D(vec);
        }

        /**
         * static functions
         */
        template <AXIS Axis>
        inline static EulerAngle<Type, AxisOrder> axisRotation(const Type &angle)
        {
            if constexpr (Axis == AXIS::X)
            {
                return EulerAngle<Type, AxisOrder>{angle, static_cast<Type>(0), static_cast<Type>(0)};
            }
            else if constexpr (Axis == AXIS::Y)
            {
                return EulerAngle<Type, AxisOrder>{static_cast<Type>(0), angle, static_cast<Type>(0)};
            }
            else if constexpr (Axis == AXIS::Z)
            {
                return EulerAngle<Type, AxisOrder>{static_cast<Type>(0), static_cast<Type>(0), angle};
            }
            else
            {
                return EulerAngle<Type, AxisOrder>{};
            }
        }

        /**
         * casts
         */
        inline UnitQuaternion<Type> toUnitQuaternion() const
        {
            constexpr AXIS AXIS1 = EULER_CONSTEXPR::AXIS_AT<0, AxisOrder>();
            constexpr AXIS AXIS2 = EULER_CONSTEXPR::AXIS_AT<1, AxisOrder>();
            constexpr AXIS AXIS3 = EULER_CONSTEXPR::AXIS_AT<2, AxisOrder>();

            const Type angle1 = getAngleInOrder<0>();
            const Type angle2 = getAngleInOrder<1>();
            const Type angle3 = getAngleInOrder<2>();

            const UnitQuaternion<Type> q1 = UnitQuaternion<Type>::template axisRotation<AXIS1>(angle1);
            const UnitQuaternion<Type> q2 = UnitQuaternion<Type>::template axisRotation<AXIS2>(angle2);
            const UnitQuaternion<Type> q3 = UnitQuaternion<Type>::template axisRotation<AXIS3>(angle3);

            return q1 * q2 * q3;
        }
        inline UnitComplexNum<Type> toUnitComplexNum() const
        {
            return UnitComplexNum<Type>{z()};
        }
        inline AxisAngle<Type> toAxisAngle() const
        {
            return toUnitQuaternion().toAxisAngle();
        }
        inline SOGroup<3, Type> toSO3Group() const
        {
            return toUnitQuaternion().toRotMatrix3D();
        }
        inline SOGroup<2, Type> toSO2Group() const
        {
            return SOGroup<2, Type>{z()};
        }
        inline Vector<3, Type> toVector() const
        {
            return Vector<3, Type>{{x(), y(), z()}};
        }

    private:
    };

    template <EULER_ORDER AxisOrder = EULER_ORDER::ZYX>
    using EulerAnglef = EulerAngle<float, AxisOrder>;
    template <EULER_ORDER AxisOrder = EULER_ORDER::ZYX>
    using EulerAngled = EulerAngle<double, AxisOrder>;
    template <EULER_ORDER AxisOrder = EULER_ORDER::ZYX>
    using EulerAngleld = EulerAngle<long double, AxisOrder>;

    template <typename Type>
    using EulerAngleXYZ = EulerAngle<Type, EULER_ORDER::XYZ>;
    template <typename Type>
    using EulerAngleZYX = EulerAngle<Type, EULER_ORDER::ZYX>;

    using EulerAngleXYZf = EulerAngleXYZ<float>;
    using EulerAngleXYZd = EulerAngleXYZ<double>;
    using EulerAngleXYZld = EulerAngleXYZ<long double>;
    using EulerAngleZYXf = EulerAngleZYX<float>;
    using EulerAngleZYXd = EulerAngleZYX<double>;
    using EulerAngleZYXld = EulerAngleZYX<long double>;
}