# Unit Complex Number

A unit complex number is a complex number that has a magnitude of 1. It is used to represent a rotation in 2D space. The unit complex number is defined as:

$$\begin{align}
z &= a + bi \\
&= \cos(\theta) + i \sin(\theta)
\end{align}$$

where $a$ is the real part, $b$ is the imaginary part, and $\theta$ is the angle of rotation.

## Inverse by Conjugate

The inverse of a unit complex number is the conjugate of the complex number. The conjugate of a complex number is defined as:

$$\begin{align}
z^{-1} = \bar{z} &= a - bi
\end{align}$$

## S1 Group

The unit complex number forms a group called the S1 group. The S1 group is a group of unit complex numbers that form a circle in the complex plane. The group is defined as:

$$\begin{align}
S^1 &= \{ z \in \mathbb{C} \mid |z| = 1 \}
\end{align}$$

where $|z|$ is the magnitude of the complex number.

Composition of two unit complex numbers is equivalent to multiplication of two complex numbers. The composition of two unit complex numbers $z_1$ and $z_2$ is defined as:

$$\begin{align}
z_1 \circ z_2 &= z_1 z_2
\end{align}$$

Identity is 1, and the inverse of a unit complex number is the conjugate of the complex number.

### Exponential Form

The unit complex number can be represented in exponential form. The exponential form of a unit complex number is defined as:

$$\begin{align}
z &= \cos(\theta) + i \sin(\theta) \\
&= e^{i \theta}
\end{align}$$

where $e$ is the base of the natural logarithm.

### Logarithmic Form

The logarithm of a unit complex number is defined as:

$$\begin{align}
\log(z) &= i \angle(z)
\end{align}$$

where $\angle(z)$ is the angle of the complex number.

### Power

The power of a unit complex number is defined as:

$$\begin{align}
z^n &= \cos(n \theta) + i \sin(n \theta) \\
&= \exp{(n \log{z})}
\end{align}$$

where $n$ is the power of the complex number.

### Action on 2D Vector

The unit complex number can be used to rotate a 2D vector. The action of a unit complex number on a 2D vector is defined as:

$$\begin{align}
v' &= zv \\
&= (\cos{\theta} + i\sin{\theta})(x + yi) \\
&= \begin{bmatrix} \cos{\theta} & -\sin{\theta} \\ \sin{\theta} & \cos{\theta} \end{bmatrix} \begin{bmatrix} x \\ y \end{bmatrix}
\end{align}$$

where $v$ is the 2D vector, and $v'$ is the rotated vector.

## Unit Complex Number Class

Based on MatrixBase & ComplexNum class.  
All functions from base classes are available. Below are additional functions.

```cpp
// initialize
UnitComplexNum<float> z1(1.f, 0); // z = 1 + 0i
// (Force initialization with norm constraint vialoation)
UnitComplexNum<float> z2(1.f, 1.f); // z = 1 + 1i,

// initialize from other form
// automatically normalized
Vectorf<2> vec2{1.f, 1.f};
UnitComplexNum<float> z3 = vec2.cast2UnitComplexNum();
ComplexNum z4{1.f, 1.f};
UnitComplexNum<float> z5 = z4.cast2UnitComplexNum();

// type alias
UnitComplexNumf z1 = z;

// accessors
float re = z1.Re();
float im = z1.Im();
z1.Re() = re;
z1.Im() = im;

// redirected inverse function
UnitComplexNumf z_inv = z1.inversed(); // internally calls conjugated()
z_inv = z1.conjugated();

// operators
UnitComplexNumf z6 = z1 * z2; // z1 * z2 (S1 composition)
ComplexNumf z7 = z1 * z2.cast2ComplexNum(); // z1 * z4 (complex number multiplication)
UnitComplexNumf z8 = z1 / z2; // z1 * z4.conjugated() (S1 division)
ComplexNumf z9 = z1 / z2.cast2ComplexNum(); // z1 * z4.inversed() (complex number division)

ComplexNumf z10 = z1 + z2; // complex number addition
ComplexNumf z11 = z1 - z2; // complex number subtraction

// rotation (action on 2D vector)
Vectorf<2> vec2{1.f, 0.f};
Vectorf<2> vec2_rotated = z1.rotateVector2D(vec2);

// identity
UnitComplexNumf z12 = UnitComplexNumf::identity();

// rotation representation conversion
SOGroup<2, float> rotationMat2D = z1.toRotMatrix2D();
AxisAngle<float> axis_angle = z2.toAxisAngle();
EulerAngle<float, EULER_ORDER::ZYX> euler_angle =
                z3.toEulerAngle<EULER_ORDER::ZYX>();
```
