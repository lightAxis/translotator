# Unit Quaternion

A unit quaternion is a quaternion with a magnitude of 1. Unit quaternions are used to represent rotations in 3D space. They are often used in computer graphics, robotics, and other fields where rotations are commonly used.

A unit quaternion is defined as:

$$\begin{align}
q &= w + xi + yj + zk \\
&= \cos(\theta/2) + \sin(\theta/2)(xi + yj + zk)
\end{align}$$

where $w$ is the real part, $x$, $y$, and $z$ are the imaginary parts with norm 1($x^2 + y^2 + z^2 = 1$) which is rotation axis, and $\theta$ is the angle of rotation.

Also represent with unit vector :

$$\begin{align}
q &= \cos(\theta/2) + \sin(\theta/2) \mathbf{u}
\end{align}$$

where $\mathbf{u}$ is unit vector representing the rotation axis. $\theta$ is the angle of rotation.

## Inverse by Conjugate

The inverse of a unit quaternion is the conjugate of the quaternion. The conjugate of a quaternion is defined as:

$$\begin{align}
q^{-1} = \bar{q} &= w - xi - yj - zk
\end{align}$$

## S3 Group

The unit quaternion forms a group called the S3 group. The S3 group is a group of unit quaternions that form a 3-sphere in 4D space. The group is defined as:

$$\begin{align}
S^3 &= \{ q \in \mathbb{H} \mid |q| = 1 \}
\end{align}$$

where $|q|$ is the magnitude of the quaternion.

Composition of two unit quaternions is equivalent to multiplication of two quaternions. The composition of two unit quaternions $q_1$ and $q_2$ is defined as:

$$\begin{align}
q_1 \circ q_2 &= q_1 q_2
\end{align}$$

Identity is 1, and the inverse of a unit quaternion is the conjugate of the quaternion.

### Exponential Form

The unit quaternion can be represented in exponential form. The exponential form of a unit quaternion is defined as:

$$\begin{align}
q &= \cos(\theta/2) + \sin(\theta/2) \mathbf{u} \\
&= e^{\frac{1}{2} \theta \mathbf{u} }
\end{align}$$

where $e$ is the base of the natural logarithm.

### Logarithmic Form

The logarithm of a unit quaternion is defined as:

$$\begin{align}
\log(q) &=0 + \frac{1}{2} \theta \mathbf{u}
\end{align}$$

where $\mathbf{u}$ is the unit vector representing the rotation axis.

### Power

The power of a unit quaternion is defined as:

$$\begin{align}
q^n &= \cos(n \theta/2) + \sin(n \theta/2) \mathbf{u} \\
&= e^{\frac{n}{2} \theta \mathbf{u} } \\
&= \exp(n \log{q})
\end{align}$$

### Action on 3D Vector

A unit quaternion can be used to rotate a 3D vector. The rotation of a 3D vector $\mathbf{v}$ by a unit quaternion $q$ is defined as:

$$\begin{align}
q &= \cos(\theta/2) + \sin(\theta/2) \mathbf{u} \\
 &= e^{\frac{1}{2} \theta \mathbf{u} } \\
\mathbf{v'} &= q \mathbf{v} q^{-1} \\
&= q \mathbf{v} \bar{q}
\end{align}$$

where $\mathbf{v'}$ is the rotated vector around the axis $\mathbf{u}$ by angle $\theta$.

## Unit Quaternion Class

Based on MatrixBase & Quaternion class.  
All functions from base classes are available. Below are additional functions.

```cpp
// initialize
UnitQuaternion<float> q1(0.7071, 0.0, 0.0, 0.7071); // w, x, y, z
// (Force initialization with norm constraint vialoation)
UnitQuaternion<float> q2(1.f, 1.f, 1.f, 1.f); // w, x, y, z

// initialize from other form
// automatically normalized
UnitQuaternion<float> q3(1.f, 2.f, 3.f, 4.f); // w, x, y, z
UnitQuaternion<float> q4 = q3.cast2UnitQuaternion();
Vectorf<4> vec4{1.f, 1.f, 1.f, 1.f};
UnitQuaternion<float> q5 = vec4.cast2UnitQuaternion();

// type alias
UnitQuaternionf q6 = q5;

// accessors
// same with Quaternion class

// redirected inverse function
UnitQuaternion<float> q7 = q6.inverse(); // internally calls conjugated()

// canonicalize
UnitQuaternionf q_can = q1.canonicalized(); // negate when w < 0

// axis rotations
// rotatation around specific axis
UnitQuaternionf q_rot_x = UnitQuaternionf::axisRotation<AXIS::X>(0.1f);
UnitQuaternionf q_rot_y = UnitQuaternionf::axisRotation<AXIS::Y>(0.2f);
UnitQuaternionf q_rot_z = UnitQuaternionf::axisRotation<AXIS::Z>(0.3f);

// operators
UnitQuaternionf q8 = q1 * q2; // S3 Composition
Quaternionf q9 = q1 * q2.cast2Quaternion(); // Quaternion multiplication
UnitQuaternionf q10 = q1 / q2; // S3 Division
Quaternionf q11 = q1 / q2.cast2Quaternion(); // Quaternion division

Quaternionf q12 = q1 + q2; // Quaternion addition
Quaternionf q13 = q1 - q2; // Quaternion subtraction

// rotation (action on 3D vector)
Vectorf<3> vec3{{1.f, 2.f, 3.f}};
Vectorf<3> vec3_rot = q1.rotateVector3D(vec3);

Vectorf<2> vec2{{1.f, 2.f}};
// Use z-axis only for rotation
Vectorf<2> vec2_rot = q1.rotateVector2D(vec2);

// identity
UnitQuaternionf q14 = UnitQuaternionf::identity();

// rotation representation conversion
SOGroup<2, float> so2 = q1.toRotMatrix2D();
SOGroup<3, float> so3 = q1.toRotMatrix3D();
AxisAngle<float> axis_angle = q1.toAxisAngle<>();
EulerAngle<float, EULER_ORDER::ZYX> euler_angle2d = q1.toEulerAngle2D<EULER_ORDER::ZYX>();
EulerAngle<float, EULER_ORDER::XYZ> euler_angle3d = q1.toEulerAngle3D<EULER_ORDER::XYZ>();
```
