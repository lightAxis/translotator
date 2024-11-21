# Dual Quaternion

A dual quaternion is a pair of quaternions, one for rotation and the other for translation. It is used to represent rigid transformations in 3D space. The dual quaternion is defined as

$$\begin{align}
q_r + \epsilon q_d &\in \mathbb{DQ} \\
&= (w_r + x_ri + y_rj + z_rk) + \epsilon (w_d + x_di + y_dj + z_dk)
\end{align}$$

where $q_r$ is the real, $q_d$ is the dual quaternion, and $\epsilon$ is the dual unit. The dual unit $\epsilon$ satisfies the following equation:

$$\begin{align}
\epsilon^2 = 0, \quad \epsilon \neq 0
\end{align}$$

## Conjugate & Norm

There's three conjugate for dual quaternion. The primary conjugate, dual conjugate, and full conjugate.  

I will use the Primary conjugate most of the time, with the notation $\bar{d}$. The dual conjugate is not used in robotics, and the full conjugate is used for the action of unit dual quaternion.

### Primary Conjugate

The primary conjugate of a dual quaternion is defined as the conjugate of each quaternion.

$$\begin{align}
d &= q_r + \epsilon q_d \\
\bar{d} &= \bar{q_r} + \epsilon \bar{q_d} \\
&= (w_r - x_ri - y_rj - z_rk) + \epsilon (w_d - x_di - y_dj - z_dk)
\end{align}$$

The norm with the primary conjugate is defined as the square of the self with the primary conjugate.

$$\begin{align}
|d| &= \sqrt{d \bar{d}} \\
&= \sqrt{d_r \bar{d_r} + \epsilon (d_r \bar{d_d} + d_d \bar{d_r})} \\
&= \sqrt{\lvert d_r \rvert^2 + 2 \epsilon (w_r w_d + x_r x_d + y_r y_d + z_r z_d)} \\
&= \sqrt{\lvert d_r \rvert^2 + 2 \epsilon (\vec{q_r} \cdot \vec{q_d})} \quad \text{sqrt of dual number} \\
&= \lvert q_r \rvert + \epsilon \frac{\vec{q_r} \cdot \vec{q_d}}{\lvert q_r \rvert}
\end{align}$$

Unit Dual Quaternion is defined using this Conjugate and Norm

### Dual Conjugate

The dual conjugate of a dual quaternion is defined as the sign of the dual part flipped.

$$\begin{align}
d &= q_r + \epsilon q_d \\
d^* &= q_r - \epsilon q_d
\end{align}$$

This conjugate has no meaning in perspective of robotics.

### Full Conjugate

The full conjugate of a dual quaternion is defined as the conjugate of each quaternion and the sign of the dual part flipped.

$$\begin{align}
d &= q_r + \epsilon q_d \\
\bar{d}^* &= \bar{q_r} - \epsilon \bar{q_d} \\
&= (w_r - x_ri - y_rj - z_rk) - \epsilon (w_d - x_di - y_dj - z_dk)
\end{align}$$

This conjugate is used for action of unit dual quaternion just like SE(3) group.

## Addition & Subtraction

Dual quaternion addition & subtraction are defined as follows:

$$\begin{align}
d_1 &= q_{r1} + \epsilon q_{d1}, \quad d_2 = q_{r2} + \epsilon q_{d2} \\
d_1 + d_2 &= (q_{r1} + q_{r2}) + \epsilon (q_{d1} + q_{d2}) \\
d_1 - d_2 &= (q_{r1} - q_{r2}) + \epsilon (q_{d1} - q_{d2})
\end{align}$$

## Multiplication

Dual quaternion multiplication is defined as follows:

$$\begin{align}
d_1 &= q_{r1} + \epsilon q_{d1}, \quad d_2 = q_{r2} + \epsilon q_{d2} \\
d_1 d_2 &= (q_{r1} q_{r2}) + \epsilon (q_{r1} q_{d2} + q_{d1} q_{r2})
\end{align}$$

## Inverse & Division

The inverse of a dual quaternion is defined as the conjugate of the dual quaternion divided by the norm of the dual quaternion.

$$\begin{align}
d^{-1} &= \frac{1}{d} = \frac{\bar{d}}{|d|^2} \\
&= \frac{\bar{d}}{d \bar{d}} \\
&= \frac{\bar{d}}{\lvert d_r \rvert^2 + 2 \epsilon (\vec{q_r} \cdot \vec{q_d})} \\
&= \frac{\bar{q_r} - \epsilon \bar{q_d}}{\lvert q_r \rvert^2 + 2 \epsilon (\vec{q_r} \cdot \vec{q_d})} \\
&= \frac{\bar{q_r}}{\lvert q_r \rvert^2} + \epsilon \left( \frac{\bar{q_d}}{\lvert q_r \rvert^2} - 2 \frac{(\vec{q_r} \cdot \vec{q_d})}{\lvert q_r \rvert^4}q_r \right) \\
\end{align}$$

Divison is defined as multiplication with the inverse.

$$\begin{align}
d_1/d_2 &= d_1 d_2^{-1}
\end{align}$$

## Dual Quaternion Class

```cpp  
// initializer, (1+2i+3j+4k) + epsilon(5+6i+7j+8k)
DualQuaternion<float> dq1{Quaternion<float>{1.f, 2.f, 3.f, 4.f},
                          Quaternion<float>{5.f, 6.f, 7.f, 8.f}}; // Re, Du
DualQuaternion<float> dq2{{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f}};

// type alias
DualQuaternionf dq3 = dq1;

// access
Quaternionf q_r = dq1.Re();
Quaternionf q_d = dq1.Du();
dq1.Re() = q_r;
dq1.Du() = q_d;

float r_w = dq1.rw();
float r_x = dq1.rx();
float r_y = dq1.ry();
float r_z = dq1.rz();
float d_w = dq1.dw();
float d_x = dq1.dx();
float d_y = dq1.dy();
float d_z = dq1.dz();
dq1.rw() = r_w;
dq1.rx() = r_x;
dq1.ry() = r_y;
dq1.rz() = r_z;
dq1.dw() = d_w;
dq1.dx() = d_x;
dq1.dy() = d_y;
dq1.dz() = d_z;

// cast to other object (8 x 1)
Vectorf<8> vec81 = dq1.cast2Vector();
Matrixf<8,1> mat81 = dq1.cast2Matrix();

// conjugates
DualQuaternionf dq4 = dq1.conjugatedPrimary();
DualQuaternionf dq5 = dq1.conjugatedDual();
DualQuaternionf dq6 = dq1.conjugatedFull();

// norm
DualNumberf norm = dq1.normDualNum();
DualNumberf norm2 = dq1.normDualNumSqared();
float norm3 = dq1.normScalar();
norm3 = dq1.normDualNum().norm();

// inverse
DualQuaternionf dq7 = dq1.inversed(); // using Primary conjugate and Norm

// operators
DualQuaternionf dq8 = dq1 + dq2;
DualQuaternionf dq9 = dq1 - dq2;
DualQuaternionf dq10 = dq1 * dq2; // dual quaternion multiplication
DualQuaternionf dq11 = dq1 / dq2; // dual quaternion division

// result type casting
Vectorf<8> vec81 = SquareMatrixf<8>{} * dq1; // matrix multiplication

// to multiplication matrix
SquareMatrixf<8> mat8 = dq1.toMulMatrix();
```
