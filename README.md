# C++ Workshop Handwritten Digit Recognition Neural Network in C++
---

## Overview

This project is part of **The Hebrew University of Jerusalem**’s course on **C++ Programming Workshops (Course 67312)**. It involves developing a neural network in C++ for recognizing handwritten digits (0-9) using the theoretical foundations of **Artificial Neural Networks (ANNs)** and practical implementation techniques in C++. The project emphasizes understanding **classes**, **operator overloading**, **references**, and the **Rule of Three** in C++.

## Project Goals

1. **Build a Neural Network**:
   - Recognize digits written in grayscale images of size 28x28 pixels.
   - Use a fully connected neural network with the following architecture:
     - 4 layers with **ReLU** and **Softmax** activation functions.
     - Weight matrices and bias vectors for each layer.

2. **Apply C++ Concepts**:
   - Implement core matrix operations (addition, multiplication, transpose, etc.).
   - Overload operators for matrix operations to simplify code readability.
   - Manage memory efficiently using C++’s Rule of Three.

3. **Achieve High Accuracy**:
   - Aim for ~96% accuracy on digit recognition tasks.
   - Handle numerical precision issues for consistent performance.

---

## Features

### Neural Network Architecture
- **Input Layer**: Vectorized grayscale images (28x28 → 784x1).
- **Hidden Layers**:
  1. Layer 1: 784 → 128 neurons, ReLU activation.
  2. Layer 2: 128 → 64 neurons, ReLU activation.
  3. Layer 3: 64 → 20 neurons, ReLU activation.
- **Output Layer**: 20 → 10 neurons, Softmax activation.
  
### Matrix Class
- Implements a versatile `Matrix` class with:
  - Construction: default, parameterized, copy constructor.
  - Arithmetic operators: `+`, `*` (scalar/matrix), `+=`.
  - Methods: `transpose()`, `vectorize()`, `norm()`, `dot()`.
  - Indexing: `()` for 2D access, `[]` for flat memory mapping.
  - Input/Output: Stream operators (`<<`, `>>`) for formatted I/O.

### Program Flow
1. Load image data and network weights from binary files.
2. Process the image through the neural network.
3. Output the predicted digit and its confidence level.

---

## Example Usage

### Running the Program
To execute the program, provide the paths to weight and bias files followed by the image file:

```bash
$ ./mlpnetwork w1 w2 w3 w4 b1 b2 b3 b4
```

The program outputs the detected digit and confidence. Example interaction:
```
Input Image: ./digit.png
Detected Digit: 7
Confidence: 90%
```

### Visualization
The program includes functionality to visualize images represented as matrices. Each pixel’s brightness is shown as either `**` (dark) or whitespace (light).

---

## Installation and Requirements

### Prerequisites
- C++17 or later.
- Standard libraries (no use of STL).
- Development environment capable of compiling and running C++ code.

### Compilation
Compile the project using `g++`:
```bash
$ g++ -std=c++17 -o mlpnetwork main.cpp matrix.cpp
```

---

## Notes

1. The neural network implementation simplifies many theoretical aspects to focus on practical programming skills.
2. The project strictly avoids the use of STL containers like `std::vector`, relying instead on manual memory management.
3. Expected inaccuracies may occur due to numerical precision or inherent network limitations.

---

## References
- [Neural Networks: Theory and Implementation](https://www.youtube.com/watch?v=aircAruvnKk)
- Course Materials: **C++ Programming Workshops (Course 67312)**

--- 
