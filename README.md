# C++ Workshop Handwritten Digit Recognition Neural Network
---
This project focuses on the implementation of a neural network to recognize handwritten digits (0-9) based on their grayscale images. The network is implemented using **C++**, without relying on external machine learning libraries, highlighting foundational programming principles in neural networks, numerical computations, and object-oriented design.

---

### **Project Overview**

1. **Objective**:
   - Build a neural network capable of identifying digits from grayscale images with high accuracy (~96%).
   - The network consists of multiple layers and incorporates the "Rule of Three" for object handling.

2. **Core Features**:
   - **Matrix Operations**: Efficiently handle numerical computations for neural networks.
   - **Activation Functions**: Support for `ReLU` and `Softmax` for activation layers.
   - **Forward Propagation**: Implementation of fully connected layers to compute outputs.
   - **C++ Standards**: STL features are not used, ensuring custom implementation of containers and algorithms.

---

### **Project Components**

#### **Matrix Class**
- Represents a two-dimensional matrix for handling weights, biases, and intermediate computations in the neural network.
- **Features**:
  - Matrix arithmetic: Addition, scalar multiplication, and matrix multiplication.
  - Transpose and vectorize functionality for matrix transformations.
  - Overloaded operators: `+`, `*`, `()`, `[]`, and stream operators for input/output.

#### **Activation Class**
- Defines activation layers with two types: `ReLU` and `Softmax`.
- Applies activation functions element-wise or across vectors as needed.

#### **Dense Class**
- Represents a single layer in the neural network.
- Encapsulates the weights, biases, and activation function for the layer.
- Performs forward propagation for a single layer.

#### **MlpNetwork Class**
- Manages the structure of the neural network, connecting all layers.
- Implements the forward pass of the entire network.
- Outputs the predicted digit alongside the probability distribution.

---

### **Implementation Details**

1. **Layer Structure**:
   - Input Layer: Processes 28x28 grayscale images, flattened into a vector of size 784.
   - Four Hidden Layers:
     - Layer 1: 784 -> 128 neurons (ReLU)
     - Layer 2: 128 -> 64 neurons (ReLU)
     - Layer 3: 64 -> 20 neurons (ReLU)
     - Layer 4: 20 -> 10 neurons (Softmax)

2. **Pipeline**:
   - The neural network computes predictions using matrix operations and activation functions.
   - Input images are preprocessed into grayscale vectors.
   - Each layer transforms its input using its weights, biases, and activation function.

3. **Error Handling**:
   - Implements robust error handling, providing informative error messages and ensuring program stability.

---

### **How to Run**
1. Compile the code using the provided `Makefile`:
   ```bash
   make mlpnetwork
   ```
2. Execute the neural network:
   ```bash
   ./mlpnetwork w1 w2 w3 w4 b1 b2 b3 b4
   ```
   Replace `w1` to `b4` with paths to the weight and bias files for each layer.
3. Feed images to the network by providing the image file path as input when prompted.

---

### **Key Concepts**
- **Rule of Three**: Ensures proper management of resources through constructors, destructors, and copy operators.
- **Numerical Stability**: Matrix computations are designed to minimize numerical errors.
- **Streamlined Design**: Clear separation of layers, activation functions, and matrix computations promotes modularity.

---

### **Future Improvements**
- Extend to support variable layer counts and sizes during runtime.
- Optimize computational efficiency for larger datasets.
- Introduce training capabilities for the neural network.
- 
---

## References
- [Neural Networks: Theory and Implementation](https://www.youtube.com/watch?v=aircAruvnKk)
- Course Materials: **C++ Programming Workshops (Course 67312)**

--- 
