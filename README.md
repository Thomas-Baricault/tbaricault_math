# tbaricault/math

[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
![C++23](https://img.shields.io/badge/C%2B%2B-23-blue)
![CMake](https://img.shields.io/badge/CMake-3.20%2B-blue)

## Description

This is a C++23 library providing classes for mathematical objects like vectors, matrixes and quaternions.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
    - [Download and install](#download-and-install)
    - [Uninstall](#uninstall)
    - [CMake](#cmake)
    - [Include](#include)
    - [Environment](#environment)
- [Documentation](#documentation)
- [Examples](#examples)
    - [Vectors demonstration](#vectors-demonstration)
    - [Rect demonstration](#rect-demonstration)
    - [Matrix demonstration](#matrix-demonstration)
- [License](#license)

## Features

- 2 and 3 dimensional vector class
- Rectangle class
- Matrix class
- Quaternion class

## Requirements

- C++23 or later
- CMake 3.20 or later
- [tbaricault/str](https://github.com/Thomas-Baricault/tbaricault_str)
- [tbaricault/uniconvert](https://github.com/Thomas-Baricault/tbaricault_uniconvert)

## Usage

### Download and install

```bash
git clone https://github.com/Thomas-Baricault/tbaricault_math.git
cd tbaricault_math
make install
```

### Uninstall

```bash
make uninstall
```

### CMake

Add the library to your project:

```cmake
find_package(tbaricault_math REQUIRED)

target_link_libraries(
    my_target
    PRIVATE
        tbaricault::math
)
```

### Include

```cpp
#include <tbaricault/math.hpp>
```

### Environment

If you have a custom C++ installation, you can edit the `ENV` variable in the `Makefile` to specify your environment path.

Example on Windows with MSYS2/MinGW64:

```makefile
ENV = C:/msys64/mingw64
```

## Documentation

Read the complete documentation at [https://docs.thomas-baricault.fr/math](https://docs.thomas-baricault.fr/math).

## Examples

### Vectors demonstration

```cpp
#include <iostream>
#include <tbaricault/math.hpp>


int main()
{
    {
        tbaricault::math::Vector2 a(1, 2);
        tbaricault::math::Vector2 b(3, 4);

        auto c = a + b;

        std::cout << c.x << " " << c.y << std::endl;
    }

    {
        tbaricault::math::Vector3 a(1, 2, 3);
        tbaricault::math::Vector3 b(4, 5, 6);

        auto c = a + b;

        std::cout << c.x << " " << c.y << " " << c.z << std::endl;
    }

    return (0);
}
```

Output:

```text
4 6
5 7 9
```

### Rect demonstration

```cpp
#include <iostream>
#include <tbaricault/math.hpp>


int main()
{
    tbaricault::math::Rect a(0, 0, 100, 100);
    tbaricault::math::Rect b(50, 50, 100, 100);

    auto c = a & b;

    std::cout << "(" << c.x << " ; " << c.y << ")" << std::endl;
    std::cout << c.w << "x" << c.h << std::endl;

    return (0);
}
```

Output:

```text
(50 ; 50)
50x50
```

### Matrix demonstration

```cpp
#include <iostream>
#include <tbaricault/math.hpp>


int main()
{
    tbaricault::math::Matrix<3, 2, int> a({
        {1, 2},
        {3, 4},
        {5, 6}
    });

    tbaricault::math::Matrix<2, 2, int> b({
        {7, 8},
        {9, 0}
    });

    auto c = a * b;

    for (auto i = 0; i < c.rows(); i++)
    {
        for (auto j = 0; j < c.columns(); j++)
            std::cout << c(i, j) << " ";
        std::cout << std::endl;
    }

    return (0);
}
```

Output:

```text
19 11 
23 15 
27 19 
```

## Roadmap

- Dynamically allocated matrix

## License

This project is licensed under the MIT License.

See [LICENSE](LICENSE) for details.
