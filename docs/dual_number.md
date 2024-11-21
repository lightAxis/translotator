# Dual Number

A dual number is a number of the form $a + b \epsilon$, where $a$ and $b$ are real numbers, and $\epsilon$ is a symbol that satisfies $\epsilon^2 = 0$. The dual number system is an extension of the real numbers that is useful for performing automatic differentiation. Sometimes related to homogeneous transformation in robotics.

## Conjugate & Norm

The norm of a dual number is defined as the square of the self with conjugated self. The conjugate of a dual number is the same as the original number.

$$\begin{align}
d &= a + b \epsilon, \quad a, b \in \mathbb{R} \quad d \in \mathbb{D} \\
\bar{d} &= a - b \epsilon \quad \text{dual conjugate} \\
|d| &= \sqrt{a^2} = \lvert a \rvert = \sqrt{d \bar{d}} \quad \text{norm}
\end{align}$$

## Addition & Subtraction

Dual number addition & subtraction are defined as follows:

$$\begin{align}
d_1 &= a_1 + b_1 \epsilon, \quad d_2 = a_2 + b_2 \epsilon \\
d_1 + d_2 &= (a_1 + a_2) + (b_1 + b_2) \epsilon \\
d_1 - d_2 &= (a_1 - a_2) + (b_1 - b_2) \epsilon
\end{align}$$

## Multiplication

Dual number multiplication is defined as follows:

$$\begin{align}
d_1 &= a_1 + b_1 \epsilon, \quad d_2 = a_2 + b_2 \epsilon \\
d_1 d_2 &= a_1 a_2 + a_1 b_2 \epsilon + a_2 b_1 \epsilon + b_1 b_2 \epsilon^2 \\
&= a_1 a_2 + (a_1 b_2 + a_2 b_1) \epsilon \\
&=\begin{bmatrix} a_1 & 0 \\ b_1 & a_1 \end{bmatrix} \begin{bmatrix} a_2 \\ b_2 \end{bmatrix}
\end{align}$$

## Inverse & Division

The inverse of a dual number is defined as the reciprocal of the dual number.

$$\begin{align}
d^{-1} &= \frac{1}{d} = \frac{1}{a + b \epsilon} = \frac{1}{a + b \epsilon} \frac{a - b \epsilon}{a - b \epsilon} \\
&= \frac{a - b \epsilon}{a^2} = \frac{a}{a^2} - \frac{b}{a^2} \epsilon
\end{align}$$

Division is defined as the multiplication of the first number by the inverse of the second number.

$$\begin{align}
d_1/d_2 &= d_1 d_2^{-1}
\end{align}$$

## Square Root

The square root of a dual number is defined as follows:

$$\begin{align}
d &= a + b \epsilon \\
\sqrt{d} &= \sqrt{a + b \epsilon} = \sqrt{a} + \frac{b}{2\sqrt{a}} \epsilon \\
\because \left( \sqrt{a} + \frac{b}{2 \sqrt{a}} \epsilon \right)^2 &= a+b \epsilon \\
\end{align}$$

## Dual Number Class

```cpp
/// initializer
DualNumber<float> d1{1.f, 2.f}; // Re, Du
DualNumber<float> d2{{1.f, 2.f}};

// type alias
DualNumberf d3 = d1;

// cast to other objects (2 x 1)
Vector2f v = d1.cast2Vector();
Matrix2f m = d1.cast2Matrix();

// accessor
float re = d1.Re();
float du = d1.Du();
d1.Re() = re;
d1.Du() = du;

// conjugate, norm
DualNumber<float> d4 = d1.conjugated();
float norm = d1.norm();

// inverse
DualNumber<float> d5 = d1.inversed();

// operators
DualNumber<float> d6 = d1 + d2;
DualNumber<float> d7 = d1 - d2;
DualNumber<float> d8 = d1 * d2; // Dual number multiplication
DualNumber<float> d9 = d1 / d2; // Dual number division

// result type casting
Vector2f v = SquareMatrix2f{} * d1; // matrix multiplication

// to multiplication matrix
SquareMatrix2f m = d1.toMatrix();
// | Re()  0   |  
// | Du() Re() |
```
