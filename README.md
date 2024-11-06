# translotator

Lightweight C++ header-only template library for translation, rotation and homogeneous transformation.  
Requires C++17 or Later. No dependencies with other libraries and stl.

## Features

- Translation, Rotation, Homogeneous Transformation
- Matrix based objects : Matrix N x M, SquareMatrix N x N, Vector N
- Number objects : Complex number, Quaternion
- Rotation objects : Unit Complex Number, Unit Quaternion, Axis Angle
- Supports variaous types of data (float, double, long double)
- Supports various operator overloadings for easy calculation
- Supports reinterpret_cast for zero-copy data type conversion between MatrixContainer

## TODOs

- add Rotation object : Euler Angle, SO(2), SO(3)
- add Number objects : Dual number, Dual Quaternion
- add Lie Group & Algebra : SO(2), SO(3), SE(2), SE(3)
- add Interpolation : Lerp, Slerp, ScLerp

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Contact

lightAxis - <jisuk500@gmail.com>
