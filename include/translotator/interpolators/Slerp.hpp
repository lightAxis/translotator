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
 * @file : Slerp.hpp
 */

#pragma once

namespace translotator::interpolators
{
    template <typename Container>
    auto SlerpDiff(const Container &start, const Container &end)
    {
        using Type = typename Container::DATATYPE;
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
            return start * lie::LieOperator_S1<Type>::Exp(lie::LieOperator_S1<Type>::Log(diff) * t);
        }
        return start * SlerpDiff(start, end).pow(t);
    }

    template <typename Container>
    class Slerper
    {
        using Type = typename Container::DATATYPE;
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
        inline Container interpolate(Type t) const
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