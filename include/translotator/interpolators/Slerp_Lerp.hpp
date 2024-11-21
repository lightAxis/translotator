#pragma once

namespace translotator::interpolators
{
    template <typename Container>
    auto SlerpLerpDiff(const Container &start, const Container &end)
    {
        using Type = typename Container::DATATYPE;
        static_assert(is_same_v<Container, SEGroup<2, Type>> ||
                          is_same_v<Container, SEGroup<3, Type>>,
                      "Invalid type for SlerpLerp. Must one of SE2, SE3");

        if constexpr (is_same_v<Container, SEGroup<2, Type>> || is_same_v<Container, SEGroup<3, Type>>)
        {
            return Container{SlerpDiff(start.rotation(), end.rotation()), LerpDiff(start.translation(), end.translation())};
        }
    }

    template <typename Container, typename Type>
    auto SlerpLerping(const Container &start, const Container &end, Type t)
    {
        static_assert(is_same_v<Container, SEGroup<2, Type>> ||
                          is_same_v<Container, SEGroup<3, Type>>,
                      "Invalid type for SlerpLerp. Must one of SE2, SE3");

        if constexpr (is_same_v<Container, SEGroup<2, Type>> || is_same_v<Container, SEGroup<3, Type>>)
        {
            const Container diff = SlerpLerpDiff(start, end);
            return Container{start.rotation() * diff.rotation().pow(t), start.translation() + diff.translation() * t};
        }
    }
    template <typename Container>
    class SlerpLerper
    {
        using Type = typename Container::DATATYPE;
        static_assert(is_same_v<Container, SEGroup<2, Type>> ||
                          is_same_v<Container, SEGroup<3, Type>>,
                      "Invalid type for SlerpLerper. Must one of SE2, SE3");

    private:
        Container start_;
        Container end_;
        Container diff_;

    public:
        /**
         * constructor
         */
        SlerpLerper() = default;
        SlerpLerper(const Container &start, const Container &end) : start_(start), end_(end), diff_(SlerpLerpDiff(start, end)) {}
        ~SlerpLerper() = default;

        inline Container operator()(Type t) const
        {
            return interpolate(t);
        }
        inline Container interpolate(Type t) const
        {
            return Container{start_.rotation() * diff_.rotation().pow(t), start_.translation() + diff_.translation() * t};
        }

        inline void updateDiff() { diff_ = SlerpLerpDiff(start_, end_); }

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