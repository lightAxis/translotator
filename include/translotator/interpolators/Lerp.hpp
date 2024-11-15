#pragma once

namespace translotator::interpolators
{
    template <typename Container>
    Container LerpDiff(const Container &start, const Container &end)
    {
        static_assert(is_matrix_base_v<Container>, "Invalid type for Lerp. Must have matrix base");
        return end - start;
    }
    template <typename Container>
    Container Lerping(const Container &start, const Container &end, typename Container::DATATYPE t)
    {
        static_assert(is_matrix_base_v<Container>, "Invalid type for Lerp. Must have matrix base");
        return start + LerpDiff(start, end) * t;
    }

    template <typename Container>
    class Lerper
    {
        static_assert(is_matrix_base_v<Container>, "Invalid type for Lerper. Must have matrix base");

    private:
        Container start_;
        Container end_;
        Container diff_;

        using ScalarType = typename Container::DATATYPE;

    public:
        /**
         * constructor
         */
        Lerper() = default;
        Lerper(const Container &start, const Container &end) : start_(start), end_(end), diff_(LerpDiff(start, end)) {}
        ~Lerper() = default;

        inline Container operator()(ScalarType t) const
        {
            return start_ + diff_ * t;
        }
        inline void updateDiff() { diff_ = LerpDiff(start_, end_); }

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