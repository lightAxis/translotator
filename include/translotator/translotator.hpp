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