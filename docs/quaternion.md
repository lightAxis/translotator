
# Quaternion

A quaternion is a number that can be expressed in the form `a + bi + cj + dk`, where `a`, `b`, `c`, and `d` are real numbers, and `i`, `j`, and `k` are imaginary units that satisfy the following equations:

$$\begin{align}
i^2 = j^2 = k^2 = ijk = -1
\end{align}$$

The set of quaternions is denoted by $\mathbb{H}$. The quaternion is a non-commutative number system, which means that the order of multiplication matters just like matricies.

Quaternion has a real part and three imaginary parts. Sometimes the imaginary parts are represented as a vector.  

## Conjugate & Norm

The norm of a quaternion is defined as the square of the self with conjugated self. The conjugate of a quaternion is the same as the original number, but the sign of the imaginary part is flipped.

$$\begin{align}
q &= w + xi + yj + zk, \quad w, x, y, z \in \mathbb{R} \quad q \in \mathbb{H} \\
&= w + \mathbf{v} \quad \text{where} \quad \mathbf{v} = xi + yj + zk \\
\bar{q} &= w - xi - yj - zk \quad \text{conjugate} \\
|q| &= \sqrt{w^2 + x^2 + y^2 + z^2} = \sqrt{q \bar{q}} \quad \text{norm}
\end{align}$$

## Addition & Subtraction

Quaternion addition & subtraction are defined as follows:

$$\begin{align}
q_1 &= w_1 + \mathbf{v}_1, \quad q_2 = w_2 + \mathbf{v}_2 \\
q_1 + q_2 &= (w_1 + w_2) + (\mathbf{v}_1 + \mathbf{v}_2) \\
q_1 - q_2 &= (w_1 - w_2) + (\mathbf{v}_1 - \mathbf{v}_2)
\end{align}$$

## Multiplication

Quaternion addition & subtraction are the same as complex numbers. Quaternion multiplication is defined as follows:

$$\begin{align}
q_1 &= w_1 + \mathbf{v}_1, \quad q_2 = w_2 + \mathbf{v}_2 \\
q_1 q_2 &= (w_1 w_2 - \mathbf{v}_1 \cdot \mathbf{v}_2) + (w_1 \mathbf{v}_2 + w_2 \mathbf{v}_1 + \mathbf{v}_1 \times \mathbf{v}_2)
\end{align}$$

In matrix form, the multiplication can be represented as follows:

$$\begin{align}
q_1 &= w_1 + \mathbf{v}_1, \quad q_2 = w_2 + \mathbf{v}_2 \\[10pt]
q_1 q_2 &= \begin{bmatrix} w_1 w_2 - \mathbf{v}_1 \cdot \mathbf{v}_2 \\ w_1 \mathbf{v}_2 + w_2 \mathbf{v}_1 + \mathbf{v}_1 \times \mathbf{v}_2 \end{bmatrix} \\[10pt]
& = \begin{bmatrix} w_1 & -\mathbf{v}_1^T \\ \mathbf{v}_1 & w_1 I + [\mathbf{v}_1]_{\times} \end{bmatrix} \begin{bmatrix} w_2 \\ \mathbf{v}_2 \end{bmatrix} \\[10pt]
&= \begin{bmatrix} w_1 & -x_1 & -y_1 & -z_1 \\ x_1 & w_1 & -z_1 & y_1 \\ y_1 & z_1 & w_1 & -x_1 \\ z_1 & -y_1 & x_1 & w_1 \end{bmatrix} \begin{bmatrix}w_2 \\ x_2 \\ y_2 \\ z_2 \end{bmatrix} \\[10pt]
[\mathbf{v}]_{\times} &= \begin{bmatrix} 0 & -v_z & v_y \\ v_z & 0 & -v_x \\ -v_y & v_x & 0 \end{bmatrix} \quad \text{cross product matrix}
\end{align}$$

## Inverse & Division

The inverse of a quaternion is defined as the conjugate of the quaternion divided by the norm of the quaternion.

$$\begin{align}
q^{-1} &= \frac{1}{q} = \frac{\bar{q}}{q \bar{q}}\\
&= \frac{\bar{q}}{|q|^2} = \frac{w - xi - yj - zk}{w^2 + x^2 + y^2 + z^2}\\
q_1/q_2 &= q_1 q_2^{-1}
\end{align}$$

## Quaternion Class

```cpp
// initializer, 1+2i+3j+4k
Quaternion<float> q1{1.f, 2.f, 3.f, 4.f}; // Re, i, j, k
Quaternion<float> q2{{1.f, 2.f, 3.f, 4.f}};
Quaternion<float> q3{1.f, Vectorf<3>{{2.f, 3.f, 4.f}}}; // Re, Im(Vec3)

// type alias
Quaternionf q4 = q1;

// cast to other object (4 x 1)
Vectorf<4> vec41 = q1.cast2Vector();
Matrixf<4,1> mat41 = q1.cast2Matrix();
q1 = vec41.cast2Quaternion();

// accessor
float re = q1.Re();
Vectorf<3> im = q1.Im();
q1.Re() = re;
q1.Im() = im;

float w = q1.w();
float x = q1.x();
float y = q1.y();
float z = q1.z();
q1.W() = w;
q1.X() = x;
q1.Y() = y;
q1.Z() = z;

// conjugate, norm
Quaternionf q5 = q1.conjugated();
float norm = q1.norm();

// inverse
Quaternionf q6 = q1.inversed();

// operators
Quaternionf q7 = q1 + q2;
Quaternionf q8 = q1 - q2;
Quaternionf q9 = q1 * q2; // quaternion multiplication
Quaternionf q10 = q1 / q2; // quaternion division

// result type casting
Vectorf<4> vec41 = SquareMatrixf<4>{} * q1; // matrix multiplication

// to multiplication matrix
SquareMatrixf<4> mat4 = q1.toMulMatrix();
// | w,     -V^T    |
// | v,  wI + [V]_x |
```
