# Axis Angle

This class is used to represent rotation in 3D space using rotation axis and angle of rotation. The axis is a unit vector and the angle is in radian.

## Axis Angle Class

This class is not derived from MatrixBase. so most of the methods are implemented in the class itself.

```cpp
// initialize 
// automatically normalize unit axis, angle, x, y, z
AxisAngle<float> axisangle(1.0f, 2.0f, 3.0f, 4.0f);
Vectorf<3> vec3{{1.f, 2.f, 3.f}};
AxisAngle<float> axisangle2(0.5f, vec3);

// type alias
AxisAnglef axisangle3 = axisangle;

// accessors
float angle = axisangle.angle();
Vectorf<3> axis = axisangle.axis();

axisangle.angle() = angle;
axisangle.axis() = axis;

// normalize
axisangle.axisNormalize();

// rotate vector
Vectorf<2> vec2{{1.f, 2.f}};
Vectorf<2> vec2_rot = axisangle.rotateVector2D(vec2); // using only z angle
Vectorf<3> vec3_rot = axisangle.rotateVector3D(vec3);

// get unit axis rotation
AxisAnglef axisangle_rot_x = AxisAnglef::axisRotation<AXIS::X>(angle);

// inverse
AxisAnglef axisangle_inv = axisangle.inversed();

// casting
UnitQuaternionf quat = axisangle.toUnitQuaternion();
UnitComplexNumf complex = axisangle.toUnitComplexNum(); // using only z angle
SOGroupf<2> so2 = axisangle.toRotationMat2D(); // using only z angle
SOGroupf<3> so3 = axisangle.toRotationMat3D();
Vectorf<3> anglevec = axisangle.toAngleVector();
EulerAngleXYZf euler = axisangle.toEulerAngle<EULER_ORDER::XYZ>();

AxisAngle<double> axisangle_d = axisangle.castDataType<double>();

```
