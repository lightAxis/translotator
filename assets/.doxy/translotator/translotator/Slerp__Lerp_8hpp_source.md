

# File Slerp\_Lerp.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**interpolators**](dir_b0f52d96602c2240130b99aee8b7fd2d.md) **>** [**Slerp\_Lerp.hpp**](Slerp__Lerp_8hpp.md)

[Go to the documentation of this file](Slerp__Lerp_8hpp.md)


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
 * @file : Slerp_Lerp.hpp
 */

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

        inline const Container &getStart() const { return start_; }
        inline const Container &getEnd() const { return end_; }
        inline const Container &getDiff() const { return diff_; }

        inline void setStart(const Container &start) { start_ = start; }
        inline void setEnd(const Container &end) { end_ = end; }
        inline void setDiff(const Container &diff) { diff_ = diff; }
    };
}
```


