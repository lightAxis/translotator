

# File default\_type.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**utils**](dir_19a7ecde96094a236c7c8e28b6698d62.md) **>** [**default\_type.hpp**](default__type_8hpp.md)

[Go to the documentation of this file](default__type_8hpp.md)


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
 * @file : default_type.hpp
 */

#pragma once

#include "../config.hpp"

namespace translotator
{

#ifdef CONFIG_TRANSLOTATOR_DEFAULT_FLOATING_POINT_PRECISION_32
#define TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE float
#elif CONFIG_TRANSLOTATOR_DEFAULT_FLOATING_POINT_PRECISION_64
#define TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE double
#elif CONFIG_TRANSLOTATOR_DEFAULT_FLOATING_POINT_PRECISION_128
#define TRANSLOTATOR_DEFAULT_FLOATING_POINT_TYPE long double
#endif

}
```


