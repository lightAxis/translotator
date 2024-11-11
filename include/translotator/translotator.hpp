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

// rotation objects, SO(2), SO(3)
#include "objects/UnitComplexNum.hpp"
#include "objects/UnitQuaternion.hpp"
#include "objects/SOGroup.hpp"
#include "objects/AxisAngle.hpp"
#include "objects/EulerAngle.hpp"

// homogeneous transformation objects
#include "objects/SEGroup.hpp"

#include "objects/tail.hpp"