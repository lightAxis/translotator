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
 * @file : ScLerp.hpp
 */

#pragma once

namespace translotator::interpolators
{
    template <typename Container>
    auto ScLerpDiff(const Container &start, const Container &end)
    {
        using Type = typename Container::DATATYPE;
        static_assert(is_same_v<Container, SEGroup<2, Type>> ||
                          is_same_v<Container, SEGroup<3, Type>>,
                      "Invalid type for ScLerp. Must one of SE2, SE3");

        return start.inversed() * end;
    }

    template <typename Container, typename Type>
    auto ScLerping(const Container &start, const Container &end, Type t)
    {
        static_assert(is_same_v<Container, SEGroup<2, Type>> ||
                          is_same_v<Container, SEGroup<3, Type>>,
                      "Invalid type for ScLerp. Must one of SE2, SE3");

        const Container diff = ScLerpDiff(start, end);
        return start * diff.pow(t);
    }

    template <typename Container>
    class ScLerper
    {
        using Type = typename Container::DATATYPE;
        static_assert(is_same_v<Container, SEGroup<2, Type>> ||
                          is_same_v<Container, SEGroup<3, Type>>,
                      "Invalid type for ScLerper. Must one of SE2, SE3");

    private:
        Container start_;
        Container end_;
        Container diff_;

    public:
        /**
         * constructor
         */
        ScLerper() = default;
        ScLerper(const Container &start, const Container &end) : start_(start), end_(end), diff_(ScLerpDiff(start, end)) {}
        ~ScLerper() = default;

        inline Container operator()(Type t) const
        {
            return start_ * diff_.pow(t);
        }
        inline Container interpolate(Type t) const
        {
            return start_ * diff_.pow(t);
        }
        inline void updateDiff() { diff_ = ScLerpDiff(start_, end_); }

        /**
         * getter and setter
         */

        inline Container getStart() const { return start_; }
        inline Container getEnd() const { return end_; }
        inline Container getDiff() const { return diff_; }

        inline void setStart(const Container &start) { start_ = start; }
        inline void setEnd(const Container &end) { end_ = end; }
        inline void setDiff(const Container &diff) { diff_ = diff; }
    };

}