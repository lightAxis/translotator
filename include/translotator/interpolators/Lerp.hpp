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
 * @file : Lerp.hpp
 */

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
        inline Container interpolate(ScalarType t) const
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