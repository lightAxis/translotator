# Euler Angle

Euler angle representation is a set of three angles that represent the orientation of a rigid body in 3D space. The three angles are usually denoted as $\phi$, $\theta$, and $\psi$.

This library provides a class 'EulerAngle' to represent Euler angles. The class provides methods to convert Euler angles to other representations like rotation matrix, quaternion, etc.

Using intrinsic rotations, Vector rotation(active rotation), and Tait-Bryan angles.
If the order is ZYX, it means that the rotation is first around the Z-axis, then around the Y-axis, and finally around the X-axis.

Check out the [Wikipedia page](https://en.wikipedia.org/wiki/Euler_angles) for more information.

## Euler Angle Class

This class is not derived from MatrixBase. so most of the methods are implemented in the class itself.

```cpp
// initialize 
// by x,y,z angles
EulerAngle<float, EULER_ORDER::XYZ> euler1{0.1f, 0.2f, 0.3f};
EulerAngle<float, EULER_ORDER::ZYX> euler2{0.1f, 0.2f, 0.3f};

// by vector3
Vectorf<3> vec3{{0.1f, 0.2f, 0.3f}}; // x,y,z angles in radian
EulerAngle<float, EULER_ORDER::XYZ> euler3{vec3};


// type alias
EulerAnglef<EULER_ORDER::ZYX> euler4 = euler2;
EulerAngleXYZ<float> euler5 = euler1;
EulerAngleZYXf euler6 = euler2;

// accessors
float x_angle = euler1.x();
float y_angle = euler1.y();
float z_angle = euler1.z();
euler.x() = 0.1f;
euler.y() = 0.2f;
euler.z() = 0.3f;

x_angle = euler1[0];
y_angle = euler1[1];
z_angle = euler1[2];
euler[0] = x_angle;
euler[1] = y_angle;
euler[2] = z_angle;

x_angle = euler1.roll();
y_angle = euler1.pitch();
z_angle = euler1.yaw();
euler1.roll() = 0.1f;
euler1.pitch() = 0.2f;
euler1.yaw() = 0.3f;

z_angle = euler1.getAngleInOrder<2>(); // XYZ, 3rd angle = z_angle
x_angle = euler2.getAngleInOrder<2>(); // ZYX, 3rd angle = x_angle

AXIS z_axis = euler1.getAxisInOrder<2>(); // XYZ, 3rd axis = Z
AXIS x_axis = euler2.getAxisInOrder<2>(); // ZYX, 3rd axis = X

// rotation vector
Vectorf<2> vec2{{1.f, 2.f}};
Vectorf<3> vec3{{1.f, 2.f, 3.f}};

Vectorf<2> vec2_rot = euler1.rotateVector2D(vec2); // using only z angle
Vectorf<3> vec3_rot = euler2.rotateVector3D(vec3);

// axis rotation 
EulerAngle<EULER_ORDER::ZYX> euler_rot_x = EulerAngle<EULER_ORDER::ZYX>::axisRotation<AXIS::X>(0.1f);

// rotation representation conversion
euler1.toUnitQuaternion()
euler1.toUnitComplexNum() // using only z angle
euler1.toAxisAngle()
euler1.toSO3Group()
euler1.toSO2Group() // using only z angle
euler1.toVector() // x_angle, y_angle, z_angle

// casting
EulerAngle<EULER_ORDER::ZYX> zyx = euler1.castAxisOrder<EULER_ORDER::ZYX>();
EulerAngleXYZ<double> xyz_d = euler1.castDataType<double>();

```
