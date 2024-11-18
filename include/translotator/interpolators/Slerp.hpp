#pragma once

namespace translotator
{
    template <typename Container, typename Type>
    auto SlerpDiff(const Container &start, const Container &end)
    {
        static_assert(is_same_v<Container, UnitComplexNum<Type>> ||
                          is_same_v<Container, UnitQuaternion<Type>> ||
                          is_same_v<Container, SOGroup<2, Type>> ||
                          is_same_v<Container, SOGroup<3, Type>>,
                      "Invalid type for Slerp. Must one of UnitComplexNum, UnitQuaternion, SO2, SO3");

        return start.inversed() * end;
    }

    template <typename Container, typename Type>
    auto Slerping(const Container &start, const Container &end, Type t)
    {
        static_assert(is_same_v<Container, UnitComplexNum<Type>> ||
                          is_same_v<Container, UnitQuaternion<Type>> ||
                          is_same_v<Container, SOGroup<2, Type>> ||
                          is_same_v<Container, SOGroup<3, Type>>,
                      "Invalid type for Slerp. Must one of UnitComplexNum, UnitQuaternion, SO2, SO3");
        const Container diff = SlerpDiff(start, end);

        if constexpr (is_same_v<Container, UnitComplexNum<Type>>)
        {
            return start * LieOperator_S1<Type>::Exp(LieOperator_S1<Type>::Log(diff) * t);
        }
        return start * SlerpDiff(start, end).pow(t);
    }

    template <typename Container, typename Type>
    class Slerper
    {
        static_assert(is_same_v<Container, UnitComplexNum<Type>> ||
                          is_same_v<Container, UnitQuaternion<Type>> ||
                          is_same_v<Container, SOGroup<2, Type>> ||
                          is_same_v<Container, SOGroup<3, Type>>,
                      "Invalid type for Slerper. Must one of UnitComplexNum, UnitQuaternion, SO2, SO3");

    private:
        Container start_;
        Container end_;
        Container diff_;

    public:
        /**
         * constructor
         */
        Slerper() = default;
        Slerper(const Container &start, const Container &end) : start_(start), end_(end), diff_(SlerpDiff(start, end)) {}
        ~Slerper() = default;

        inline Container operator()(Type t) const
        {
            return start_ * diff_.pow(t);
        }
        inline void updateDiff() { diff_ = SlerpDiff(start_, end_); }

        /**
         * getter & setter
         */

        inline const Container &getStart() const { return start_; }
        inline const Container &getEnd() const { return end_; }
        inline const Container &getDiff() const { return diff_; }

        inline void setStart(const Container &start) { start_ = start; }
        inline void setEnd(const Container &end) { end_ = end; }
        inline void setDiff(const Container &diff) { diff_ = diff; }
    };
}