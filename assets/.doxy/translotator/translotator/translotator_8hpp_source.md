

# File translotator.hpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**translotator**](dir_ffa3503b73a46a1fbf73d754da62ba14.md) **>** [**translotator.hpp**](translotator_8hpp.md)

[Go to the documentation of this file](translotator_8hpp.md)


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
 * @file : translotator.hpp
 */

#pragma once

#include <assert.h>
#include <stddef.h>

#include "utils/default_type.hpp"
#include "utils/micro_math.hpp"
#include "utils/epsilon.hpp"

// basic object definitions
#include "objects/objectdefs.hpp"
#include "objects/initializer_list.hpp"

// matrix based objects
#include "objects/MatrixBaseInternal.hpp"
#include "objects/MatrixBase.hpp"
#include "objects/Matrix.hpp"
#include "objects/SquareMatrix.hpp"
#include "objects/Vector.hpp"

// number systems
#include "objects/ComplexNum.hpp"
#include "objects/Quaternion.hpp"
#include "objects/DualNumber.hpp"
#include "objects/DualQuaternion.hpp"

// rotation objects, SO(2), SO(3)
#include "objects/UnitComplexNum.hpp"
#include "objects/UnitQuaternion.hpp"
#include "objects/SOGroup.hpp"
#include "objects/AxisAngle.hpp"
#include "objects/EulerAngle.hpp"

// homogeneous transformation objects
#include "objects/SEGroup.hpp"
#include "objects/UnitDualQuaternion.hpp"

// lie group operations
#include "lie/LieOperator.hpp"

// interpolators
#include "interpolators/Lerp.hpp"
#include "interpolators/Slerp.hpp"
#include "interpolators/ScLerp.hpp"
#include "interpolators/Slerp_Lerp.hpp"

#include "objects/tail.hpp"
```


