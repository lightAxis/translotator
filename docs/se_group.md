# SE Group

SE(2) and SE(3) groups are used to represent rigid body transformations in 2D and 3D respectively. They are used in many applications in robotics and computer vision.

## Group Properties

Definition of the SE(n) is the set of all $(n+1) \times (n+1)$ matrices of the form:

$$\begin{align}
SE(n) &= \{ T \in \mathbb{R}^{(n+1) \times (n+1)} \mid T = \begin{bmatrix} R & t \\ 0 & 1 \end{bmatrix}, R \in SO(n), t \in \mathbb{R}^n \}
\end{align}$$

where $R$ is a rotation matrix, $t$ is a translation vector, and $0$ is a zero vector.

SE(2) and SE(3) are special Euclidean group in 2D and 3D space respectively. The SE(2) group is a group of 2D rigid body transformations in the plane. The SE(3) group is a group of 3D rigid body transformations in space.

Compositions of two rigid body transformations is equivalent to multiplication of two matrices. The composition of two rigid body transformations $T_1$ and $T_2$ is defined as:

$$\begin{align}
T_1 \circ T_2 &= T_1 T_2
\end{align}$$

### Identity & Inverse

Identity is the identity matrix. The inverse of a rigid body transformation matrix is the inverse of the rotation matrix and the negative of the rotated translation vector. The inverse of a rigid body transformation matrix $T$ is defined as:

$$\begin{align}
T^{-1} &= \begin{bmatrix} R^T & -R^T t \\ 0 & 1 \end{bmatrix}
\end{align}$$

### Exponential

The rigid body transformation matrix can be represented in exponential form. The exponential form of a rigid body transformation matrix is defined as:

$$\begin{align}
T &= \exp{\begin{bmatrix}[\theta \vec{u}]_{\times} & v \\ 0  & 0\end{bmatrix}} \\
\end{align}$$

where $[\theta \vec{u}]_{\times}$ is the skew-symmetric matrix representing the rotation axis. $\theta$ is rotation angle, and $\vec{u}$ is the unit vector representing the rotation axis. $v$ is the translation vector, but not an real translation vector. It is a vector that represents the translation in the direction of the rotation axis, screw motion.

In case of 2D rigid body transformation, this can be simplified to:

$$\begin{align}
T &= \exp{\begin{bmatrix} 0 & -\theta & v_x \\ \theta & 0 & v_y \\ 0 & 0 & 0 \end{bmatrix}} \\
&= \begin{bmatrix} R & Jv \\ 0  & 1\end{bmatrix} \\
\end{align}$$

Where $R$ is rotation matrix in 2D,  $Jv$ is the translation vector in 2D.

$$\begin{align}
R &= \begin{bmatrix} \cos{\theta} & -\sin{\theta} \\ \sin{\theta} & \cos{\theta} \end{bmatrix} \\
J &= \frac{1}{\theta}\begin{bmatrix} \sin{\theta} & -(1-\cos{\theta}) \\ 1 - \cos{\theta} & \sin{\theta} \end{bmatrix}, if \theta \neq 0 \\
J & = I, if \theta = 0
\end{align}$$

In case of 3D rigid body transformation, this can be simplified to:

$$\begin{align}
T &= \exp{\begin{bmatrix} 0 & -\theta u_z & \theta u_y & v_x \\ \theta u_z & 0 & -\theta u_x & v_y \\ -\theta u_y & \theta u_x & 0 & v_z \\ 0 & 0 & 0 & 0 \end{bmatrix}} \\
&= \begin{bmatrix} R & Jv \\ 0  & 1\end{bmatrix} \\
\end{align}$$

Where $R$ is rotation matrix in 3D,  $Jv$ is the translation vector in 3D.

$$\begin{align}
R &= \exp([\theta \vec{u}]_{\times}) \\
&= I + \sin{\theta}[\vec{u}]_{\times} + [1-\cos{\theta}](\vec{u})_{\times}^2 \\
J &= I + \frac{1-\cos{\theta}}{\theta}[\vec{u}]_{\times} + \frac{\theta - \sin{\theta}}{\theta}[\vec{u}]_{\times}^2, if \theta \neq 0 \\
J & = I, if \theta = 0
\end{align}$$

### Logarithmic

The logarithm of a rigid body transformation matrix is defined as:

$$\begin{align}
\log(T) &= \begin{bmatrix} \theta[\vec{u}]_{\times} & v \\ 0 & 0 \end{bmatrix} \\
\end{align}$$

where $\theta$ is the angle of rotation. $\vec{u}$ is the unit vector representing the rotation axis. $v$ is the translation vector, but not an real translation vector. It is a vector that represents the translation in the direction of the rotation axis, screw motion.

In case of 2D rigid body transformation, this can be simplified to:

$$\begin{align}
\log(T)=\log{\begin{bmatrix}R & t \\ 0 & 1\end{bmatrix}} &= \begin{bmatrix} 0 & -\theta & v_x \\ \theta & 0 & v_y \\ 0 & 0 & 0 \end{bmatrix} = \begin{bmatrix} [\theta]_{\times} & v \\ 0 & 0\end{bmatrix} \\
\end{align}$$

Where $R$ is rotation matrix in 2D,  $v$ is the translation vector in screw motion.

$$\begin{align}
R &= \begin{bmatrix} \cos{\theta} & -\sin{\theta} \\ \sin{\theta} & \cos{\theta} \end{bmatrix} \\
v &= J^{-1}t \\
J &= \frac{\theta}{2(1-\cos{\theta})}\begin{bmatrix}\sin{\theta} & 1-\cos{\theta} \\ -(1-\cos{\theta}) & \sin{\theta}\end{bmatrix}, if \theta \neq 0 \\
J & = I, if \theta = 0
\end{align}$$

In case of 3D rigid body transformation, this can be simplified to:

$$\begin{align}
\log(T)=\log{\begin{bmatrix}R & t \\ 0 & 1\end{bmatrix}} &= \begin{bmatrix} 0 & -\theta u_z & \theta u_y & v_x \\ \theta u_z & 0 & -\theta u_x & v_y \\ -\theta u_y & \theta u_x & 0 & v_z \\ 0 & 0 & 0 & 0 \end{bmatrix} = \begin{bmatrix}[\theta \vec{u}]_{\times} & v \\ 0 & 0\end{bmatrix} \\
\end{align}$$

Where $R$ is rotation matrix in 3D,  $v$ is the translation vector in screw motion.

$$\begin{align}
R &= \exp([\theta \vec{u}]_{\times}) \\
\theta &= \cos^{-1} \left( \frac{\text{trace}(R) - 1}{2} \right) \\
[\vec{u}]_{\times} &= \frac{1}{2 \sin{\theta}}(R-R^T) \\[10pt]
v &= J^{-1}t \\
J^{-1} &= I - \frac{\theta}{2}[\vec{u}]_{\times} + \left( 1 - \frac{\theta \sin{\theta}}{2(1-\cos{\theta})} \right)[\vec{u}]_{\times}^2 , if \theta \neq 0 \\
J^{-1} &= I, if \theta = 0
\end{align}$$

### Power

The power of a rigid body transformation matrix is defined as:

$$\begin{align}
T^n &= \exp(n \log{T}) \\
&= \exp(n \begin{bmatrix} \theta[\vec{u}]_{\times} & v \\ 0 & 0 \end{bmatrix}) \\
&= \exp(n \begin{bmatrix} [\theta]_{\times} & v \\ 0 & 0 \end{bmatrix})
\end{align}$$

### Action on Vector

The action of a rigid body transformation matrix on a 2D or 3D vector is defined as:

$$\begin{align}
\begin{bmatrix}\mathbf{v}' \\ 1\end{bmatrix} &= \begin{bmatrix} R & t \\ 0 & 1 \end{bmatrix} \begin{bmatrix}\mathbf{v} \\ 1\end{bmatrix} \\
&= \begin{bmatrix} R\mathbf{v} + t \\ 1 \end{bmatrix}
\end{align}$$

where $\vec{v}'$ is the transformed vector.

### Normalization

Just normalize the rotation matrix $R$ to get the rotation matrix in SO(n) group. Translation vector $t$ is not normalized.

Other structure like unit dual quaternion can be used to represent the rigid body transformation, and the normalization can affect both the rotation and translation.

## SE Group Class

**This is not a matrix-based object, but a composition of two objects.** The SO group object is used to represent the rotation matrix, and the Vector object is used to represent the translation vector.

I manually overload the operators to perform the operations on the SE group object as full operation with matirx form is not effiecient. Every operation has to do unneccessary matrix multiplication, like multiplication with 1s and 0s if we use matrix form.

```cpp
// initialize
SOGroup<2,float> so2{};
Vector<2,float> vec2{};
SEGroup<2,float> se2{so2, vec2};

SOGroup<3,float> so3{};
Vector<3,float> vec3{};
SEGroup<3,float> se3{so3, vec3};

SquareMatrix<3,float> mat33{{0, -1, 11,
                             1,  0, 12,
                             0,  0, 1}};
SEGroup<2, float> se2_from_mat{mat33};

// type alias
SEGroupf<2> se2f = se2;
SE3Groupf se3ff = se3;

// accessors
SOGroup<2,float> so2 = se2.rotation();
se2.rotation() = so2;
Vector<2,float> vec2 = se2.translation();
se2.translation() = vec2;

// operators
// no operator overloading except for multiplication & division
// if you want to do action on vector, or get matrix form, use the methods below
SEGroup<2,float> se2_1 = se2 * se2; // se2 * se2 = se2
SEGroup<3,float> se3_1 = se3 * se3; // se3 * se3 = se3

SEGroup<2,float> se2_2 = se2 / se2; // se2 / se2 = se2.inverse()

// inversed
SEGroup<3,float> se3_2 = se3.inversed();

// action on vector
Vectorf<3> vec3_ac = se3.actOnVector(Vectorf<3>{{1.f, 2.f, 3.f}});

// get matrix form
SquareMatrixf<4> mat44 = se3.toSquareMatrix();
```
