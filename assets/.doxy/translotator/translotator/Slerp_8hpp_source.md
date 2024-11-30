

# File Slerp.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**interpolators**](dir_b0f52d96602c2240130b99aee8b7fd2d.md) **>** [**Slerp.hpp**](Slerp_8hpp.md)

[Go to the documentation of this file](Slerp_8hpp.md)


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
 * @file : Slerp.hpp
 */

#pragma once

namespace translotator::interpolators
{
    /***
     * @brief Slerp for rotation component interpolation
     * @tparam Container Matrix base type
     * @return Slerp difference between start and end
     */
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

        if constexpr (is_same_v<Container, UnitComplexNum<Type>>)
        {
            return start * SlerpDiff(start, end).pow(t);
        }
        else if constexpr (is_same_v<Container, UnitQuaternion<Type>>)
        {
            const Type dot_product = start.w() * end.w() + start.x() * end.x() + start.y() * end.y() + start.z() * end.z();
            const Type theta = translotator::acos(dot_product);
            if (translotator::abs(theta) < translotator::epsilon<Type>())
            {
                return start;
            }
            const Type shortest_path = dot_product < static_cast<Type>(0) ? static_cast<Type>(-1) : static_cast<Type>(1);
            const Type a = translotator::sin((1 - t) * theta) / translotator::sin(theta);
            const Type b = translotator::sin(t * theta) * shortest_path / translotator::sin(theta);
            return UnitQuaternion<Type>{a * start.w() + b * end.w(),
                                        a * start.x() + b * end.x(),
                                        a * start.y() + b * end.y(),
                                        a * start.z() + b * end.z()};
        }
        else if constexpr (is_same_v<Container, SOGroup<2, Type>> ||
                           is_same_v<Container, SOGroup<3, Type>>)
        {
            return start * SlerpDiff(start, end).pow(t);
        }
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

        inline const Container &getStart() const { return start_; }
        inline const Container &getEnd() const { return end_; }
        inline const Container &getDiff() const { return diff_; }

        inline void setStart(const Container &start) { start_ = start; }
        inline void setEnd(const Container &end) { end_ = end; }
        inline void setDiff(const Container &diff) { diff_ = diff; }
    };

    template <typename Container>
    class SlerperFast
    {
        using Type = typename Container::DATATYPE;
        static_assert(is_same_v<Container, UnitComplexNum<Type>> ||
                          is_same_v<Container, UnitQuaternion<Type>>,
                      "Invalid type for SlerperFast. Must one of UnitComplexNum, UnitQuaternion");

    private:
        Container start_;
        Container end_;
        Type theta_;
        Type shortest_path_;

    public:
        SlerperFast() = default;
        SlerperFast(const Container &start, const Container &end) : start_(start), end_(end)
        {
            update_theta();
        }
        ~SlerperFast() = default;

        inline Container operator()(Type t) const 
        {
            const Type a = translotator::sin((1 - t) * theta_) / translotator::sin(theta_);
            const Type b = translotator::sin(t * theta_) / translotator::sin(theta_) * shortest_path_;
            if constexpr (is_same_v<Container, UnitComplexNum<Type>>)
            {
                return Container{a * start_.Re() + b * end_.Re(),
                                 a * start_.Im() + b * end_.Im()};
            }
            else if constexpr (is_same_v<Container, UnitQuaternion<Type>>)
            {
                return Container{a * start_.w() + b * end_.w(),
                                 a * start_.x() + b * end_.x(),
                                 a * start_.y() + b * end_.y(),
                                 a * start_.z() + b * end_.z()};
            }
        }
        inline Container interpolate(Type t) const 
        {
            return operator()(t);
        }

        inline const Container &getStart() const { return start_; }
        inline const Container &getEnd() const { return end_; }

        inline void setStart(const Container &start) { start_ = start; }
        inline void setEnd(const Container &end) { end_ = end; }

        inline void update_theta()
        {
            Type dot;
            if constexpr (is_same_v<Container, UnitComplexNum<Type>>)
            {
                dot = start_.Re() * end_.Re() + start_.Im() * end_.Im();
            }
            else if constexpr (is_same_v<Container, UnitQuaternion<Type>>)
            {
                dot = start_.w() * end_.w() + start_.x() * end_.x() + start_.y() * end_.y() + start_.z() * end_.z();
            }
            shortest_path_ = dot < static_cast<Type>(0) ? static_cast<Type>(-1) : static_cast<Type>(1);
            theta_ = translotator::acos(dot);
        }
    };
}
```


