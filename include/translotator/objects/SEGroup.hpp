#pragma once

namespace translotator
{
    /**
     * @brief Special Euclidean Group
     */
    template <size_t N, typename Type>
    class SEGroup
    {

    private:
        SOGroup<N, Type> R_; // rotation
        Vector<N, Type> t_;  // translation

    public:
        constexpr static ObjectType OBJECT_TYPE = ObjectType::SE_GROUP;
        using DATATYPE = Type;
        /**
         * constructor
         */

        SEGroup() = default;
        SEGroup(const SOGroup<N, Type> &rotation, const Vector<N, Type> &translation) : R_(rotation), t_(translation) {}
        SEGroup(const SquareMatrix<N + 1, Type> &matrix) : SEGroup(
                                                               matrix.template block<0, 0, N, N>().template castContainer<SOGroup<N, Type>>(),
                                                               matrix.template block<0, N, N, 1>().cast2Vector()) {}
        ~SEGroup() = default;

        /**
         * accessors
         */
        inline SOGroup<N, Type> rotation() const { return R_; }
        inline Vector<N, Type> translation() const { return t_; }
        inline SOGroup<N, Type> &rotation() { return R_; }
        inline Vector<N, Type> &translation() { return t_; }

        /**
         * operator
         */
        inline SEGroup<N, Type> operator*(const SEGroup<N, Type> &other) const
        {
            return SEGroup<N, Type>(R_ * other.R_, R_ * other.t_ + t_);
        }

        inline SEGroup<N, Type> operator/(const SEGroup<N, Type> &other) const
        {
            const SOGroup<N, Type> other_r_inv = other.R_.inversed();
            return SEGroup<N, Type>(R_ * other_r_inv, -R_ * other_r_inv * other.t_ + t_);
        }

        /**
         * utils
         */
        inline SEGroup<N, Type> inversed() const
        {
            const SOGroup<N, Type> R_inv = R_.inversed();
            return SEGroup<N, Type>{R_inv, -R_inv * t_};
        }
        inline Vector<N, Type> actOnVector(const Vector<N, Type> &vec) const
        {
            return R_ * vec + t_;
        }
        inline void print() const
        {
            R_.print();
            t_.print();
        }
        inline SEGroup<N, Type> pow(const Type &t) const
        {
            using LieOp = lie::LieOperator<ObjectType::SE_GROUP, Type>;
            return LieOp::Exp(LieOp::Log(*this) * t);
        }

        /**
         * static functions
         */
        static inline SEGroup<N, Type> identity()
        {
            return SEGroup<N, Type>{SOGroup<N, Type>::identity(), Vector<N, Type>::zeros()};
        }

        /**
         * casting
         */
        inline SquareMatrix<N + 1, Type> toSquareMatrix() const
        {
            SquareMatrix<N + 1, Type> mat = SquareMatrix<N + 1, Type>::zeros();
            mat.template setBlockStatic<0, 0>(R_);
            mat.template setBlockStatic<0, N>(t_);
            mat(N, N) = static_cast<Type>(1);
            return mat;
        }
    };

    template <size_t N>
    using SEGroupf = SEGroup<N, float>;
    template <size_t N>
    using SEGroupd = SEGroup<N, double>;
    template <size_t N>
    using SEGroupld = SEGroup<N, long double>;

    template <typename Type>
    using SE2Group = SEGroup<2, Type>;
    template <typename Type>
    using SE3Group = SEGroup<3, Type>;

    using SE2Groupf = SE2Group<float>;
    using SE2Groupd = SE2Group<double>;
    using SE2Groupld = SE2Group<long double>;
    using SE3Groupf = SE3Group<float>;
    using SE3Groupd = SE3Group<double>;
    using SE3Groupld = SE3Group<long double>;
}