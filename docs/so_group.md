# SO(2) & SO(3) Group

The SO(2) group is a group of 2D rotations in the plane. The SO(3) group is a group of 3D rotations in space. The SO(2) group is a subgroup of the SO(3) group. The SO(2) group is a group of unit complex numbers. The SO(3) group is a group of unit quaternions.

## Group Properties

Definition of the SO(n) is the set of all $n \times n$ orthogonal matrices with determinant 1. The SO(n) group is a group of rotations in n-dimensional space. The group is defined as:

$$\begin{align}
SO(n) &= \{ R \in \mathbb{R}^{n \times n} \mid R^T R = I, \det(R) = 1 \}
\end{align}$$

where $R^T$ is the transpose of the matrix, $I$ is the identity matrix, and $\det(R)$ is the determinant of the matrix.

$SO(2), SO(3)$ is special orthogonal group in 2D and 3D space respectively. The SO(2) group is a group of 2D rotations in the plane. The SO(3) group is a group of 3D rotations in space.

Compositions of two rotations is equivalent to multiplication of two matrices. The composition of two rotations $R_1$ and $R_2$ is defined as:

$$\begin{align}
R_1 \circ R_2 &= R_1 R_2
\end{align}$$

### Identity & Inverse

Identity is the identity matrix. The inverse of a rotation matrix is the transpose of the matrix. The transpose of a matrix is defined as:

$$\begin{align}
R^{-1} &= R^T
\end{align}$$

### Exponential

The rotation matrix can be represented in exponential form. The exponential form of a rotation matrix is defined as:

$$\begin{align}
R &= \exp([\theta \vec{u}]_{\times}) \\
&= \exp{\begin{bmatrix} 0 & -\theta u_z & \theta u_y \\ \theta u_z & 0 & -\theta u_x \\ -\theta u_y & \theta u_x & 0 \end{bmatrix}} \\
&= I + [\theta \vec{u}]_{\times} + \frac{[\theta \vec{u}]_{\times}^2}{2!} + \frac{[\theta \vec{u}]_{\times}^3}{3!} + \ldots\\
&= I + \sin{\theta} [\vec{u}]_{\times} + (1 - \cos{\theta}) [\vec{u}]_{\times}^2
\end{align}$$

where $[\theta]_{\times}$ is the skew-symmetric matrix representing the rotation axis. $\theta$ is rotation angle, and $\vec{u}$ is the unit vector representing the rotation axis.

In case of 2D rotation, this can be simplified to:

$$\begin{align}
R &= \begin{bmatrix} \cos{\theta} & -\sin{\theta} \\ \sin{\theta} & \cos{\theta} \end{bmatrix}
\end{align}$$

### Logarithmic

The logarithm of a rotation matrix is defined as:

$$\begin{align}
\log(R) &= \theta[\vec{u}]_{\times}\\
\theta &= \cos^{-1} \left( \frac{\text{trace}(R) - 1}{2} \right) \\
[\vec{u}]_{\times} &= \frac{1}{2 \sin{\theta}}(R-R^T) \\
&= \frac{1}{2 \sin{\theta}} \begin{bmatrix} R_{32} - R_{23} \\ R_{13} - R_{31} \\ R_{21} - R_{12} \end{bmatrix}
\end{align}$$

where $\theta$ is the angle of rotation. $\vec{u}$ is the unit vector representing the rotation axis.

In case of 2D rotation, this can be simplified to:

$$\begin{align}
\log(R) &= \begin{bmatrix} 0 & -\theta \\ \theta & 0 \end{bmatrix}
\end{align}$$

### Power

The power of a rotation matrix is defined as:

$$\begin{align}
R^n &= \exp(n \theta [\vec{u}]_{\times}) \\
&= \exp(n \log{R})
\end{align}$$

### Action on Vector

The action of a rotation matrix on a 2D or 3D vector is defined as:

$$\begin{align}
\vec{v}' &= R \vec{v}
\end{align}$$

where $\vec{v}'$ is the rotated vector around the axis $\vec{u}$ by angle $\theta$.

In case of 2D rotation, this can be simplified to:

$$\begin{align}
\begin{bmatrix} x' \\ y' \end{bmatrix} &= \begin{bmatrix} \cos{\theta} & -\sin{\theta} \\ \sin{\theta} & \cos{\theta} \end{bmatrix} \begin{bmatrix} x \\ y \end{bmatrix}
\end{align}$$

## Normalization

The rotation matrix should be normalized to ensure that it is a valid rotation matrix. The mathmatically propery way to normalize a rotation matrix is to use the SVD decomposition, finding a new orthogonal matrix that minimizes the difference between the original matrix and the new one :

$$\begin{align}
\min_{\hat{R}}{\lVert R -\hat{R} \rVert_F^2} \\
s.t. \quad \hat{R} \in SO(n)
\end{align}$$

But in practice, most of the time it is not that far from the orthogonal matrix. So, I implemented a simpler normalization. **Just convert to Unit Quaternion, and convert back to rotation matrix.**

This is not a mathmatically proper way, but it is good enough for most of the cases. Also much faster than SVD decomposition :

```cpp
/**
 * @brief Get the orthogonalized matrix
 * @return SOGroup<N, Type>
 * @note This function uses UnitComplexNum & UnitQuternion internally.
 * Not a mathmatically correct way, but it works pretty good.
 */
inline SOGroup<N, Type> normalized() const
{
    if constexpr (N == 2)
    {
        return this->toUnitComplexNum().toRotMatrix2D();
    }
    else if constexpr (N == 3)
    {
        return this->toUnitQuaternion().toRotMatrix3D();
    }
    else
    {
        static_assert(N == 2 || N == 3, "Supports only SO(2) & SO(3) Groups");
        return SOGroup<N, Type>();
    }
}
```

## SO Group Class

Based on MatrixBase & SquareMatrix class.  
All functions from base classes are available. Below are additional functions.

```cpp
// initinialize
SOGroup<2, float> R2d(0.5f); // 2D rotation by 0.5 radian
SOGroup<3, float> R3d(0.5f, 0.0f, 0.0f); // 3D rotation by 0.5 radian around x-axis

// (Force initialization with norm constraint vialoation)
SOGroup<2, float> R2d(0.5f, 0.0f,
                      0.0f, 0.0f); // forced, not recommended
SOGroup<3, float> R3d(0.5f, 0.0f, 1.0f,
                      0.0f, 0.7f, 0.0f,
                      0.0f, 0.2f, 0.9f); // fored, not recommended

// initialize from other form
// automatically normalized
SquareMatrix<2, float> R2_sq{{0.5f, -0.5f},
                             {0.5f, 0.5f}};
SOGroup<2, float> so2 = R2_sq.cast2SOGroup(); // normalized
Matrix<3,3,float> Mat33{{0.5f, -0.5f, 0.0f},
                         {0.5f, 0.5f, 0.0f},
                         {0.0f, 0.0f, 1.0f}};
SOGroup<3, float> so3 = Mat33.cast2SOGroup(); // normalized

// type alias
SOGroupf<2> so2f = so2;
SO2Group<float> so2ff = so2;
SO2Groupf = so2fff = so2;
RotationMatrixf<2> so2ffff = so2;
RotationMatrix2D<float> so2fffff = so2;
RotationMatrix2Df so2ffffff = so2;

// accessors
// same with SquareMatrix class

// normalize
SOGroupf<2> so2_norm = so2.normalized();

// axis rotations
// rotatation around specific axis
SOGroupf<3> so3_x = SOGroupf<3>::axisRotation<AXIS::X>(0.1f);
SOGroupf<3> so3_y = SOGroupf<3>::axisRotation<AXIS::Y>(0.2f);
SOGroupf<3> so3_z = SOGroupf<3>::axisRotation<AXIS::Z>(0.3f);

// operators
SOGroupf<2> R2d_inv = R2d.inverse(); // internally calls transpose()

SOGroupf<3> so3_1 = R3d * R3d; // SO(3) Composition
SquareMatrixf<3> mat3 = R3d * R3d.cast2SquareMatrix(); // Matrix multiplication
// no division implemented. Use inverse() instead.

SquareMatrixf<3> mat33 = R3d + R3d; // Matrix addition
SquareMatrixf<3> mat333 = R3d - R3d; // Matrix subtraction

// rotation (action on 3D vector)
Vectorf<3> vec3{{1.f, 2.f, 3.f}};
Vectorf<3> vec3_rot = so3 * vec3;

// identity
SOGroupf<3> so3_id = SOGroupf<3>::identity();

// rotation representation conversion
so2.toUnitComplexNum();
so3.toUnitComplexNum() // use 2x2 only
so3.toUnitQuaternion();
so3.toAxisAngle();
so3.toEulerAngle<EULER_ORDER::ZYX>();

```
