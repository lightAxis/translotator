
# Complex Number

A complex number is a number that can be expressed in the form `a + bi`, where `a` and `b` are real numbers, and `i` is a solution of the equation `x^2 = -1`. Because no real number satisfies this equation, `i` is called an imaginary number. For the complex number `a + bi`, `a` is called the real part, and `b` is called the imaginary part. The set of complex numbers is denoted by $\mathbb{C}$.

## Conjugate & Norm

The norm of a complex number is defined as the square of the self with conjugated self. The conjugate of a complex number is the same as the original number, but the sign of the imaginary part is flipped.

$$\begin{align}
z &= a + bi, \quad a, b \in \mathbb{R} \quad z \in \mathbb{C}, i^2 = -1 \\
\bar{z} &= a - bi \quad \text{conjugate} \\
|z| &= \sqrt{a^2 + b^2} = \sqrt{z \bar{z}} \quad \text{norm}
\end{align}$$

## Addition, Subtraction

Addition and subtraction of complex numbers are defined as follows:

$$\begin{align}
z_1 &= a_1 + b_1 i, \quad z_2 = a_2 + b_2 i \\
z_1 + z_2 &= (a_1 + a_2) + (b_1 + b_2) i \\
z_1 - z_2 &= (a_1 - a_2) + (b_1 - b_2) i
\end{align}$$

## Multiplication

Multiplication of complex numbers is defined as follows:

$$\begin{align}
z_1 &= a_1 + b_1 i, \quad z_2 = a_2 + b_2 i \\
z_1 z_2 &= (a_1 a_2 - b_1 b_2) + (a_1 b_2 + a_2 b_1) i \\
&= \begin{bmatrix} a_1 a_2 - b_1 b_2 \\ a_1 b_2 + a_2 b_1 \end{bmatrix} \\[10pt]
&= \begin{bmatrix} a_1 & -b_1 \\ b_1 & a_1 \end{bmatrix} \begin{bmatrix} a_2 \\ b_2 \end{bmatrix} \\[10pt]
\end{align}$$

## Inverse & Division

Division is defined as multiplication by the inverse of the divisor:

$$\begin{align}
z &= a+bi\\
z^{-1} &= \frac{1}{a+bi} \\
&= \frac{a-bi}{(a+bi)(a-bi)} \quad \text{multiply by conjugate} \\
&= \frac{a-bi}{a^2+b^2} \\
&= \frac{a}{a^2+b^2} - \frac{b}{a^2+b^2}i \\
\\
z_1 / z_2 &= z_1 z_2^{-1}
\end{align}$$

## Complex Number Class

```cpp
// initializer, 1+2i
ComlexNum<float> z1{1.f, 2.f}; // Re, Im
ComplexNum<float> z2{{1.f, 2.f}};

// type alias
ComplexNumf z3 = z1

// cast to other object (2 x 1)
Vectorf<2> vec21 = z1.cast2Vector();
Matrixf<2,1> mat21 = z1.cast2Matrix();
z1 = vec21.cast2ComplexNum();

// accessor
float re = z1.re();
float im = z1.im();
z1.Re() = re;
z1.Im() = im;

// conjugate
ComplexNumf z1_conj = z1.conjugated();

// norm
float norm = z1.norm();
float normSq = z1.normSquared();
ComplexNumf z1_normed = z1.normalized();

// inverse
ComplexNumf z1_inv = z1.inversed();

// operators
ComplexNumf z3 = z1 + z2;
ComplexNumf z4 = z1 - z2;
ComplexNumf z5 = z1 * z2; // complex number multiplication
ComplexNumf z6 = z1 / z2; // z1 * z2.inversed()

// result type casting
Vectorf<2> vec21 = SquareMatirxf<2>{} * z1; // matrix multiplication

// to multiplication matrix
SquareMatrixf<2> mat2 = z1.toMulMatrix();
// | Re(), -Im() |
// | Im(),  Re() |

```
