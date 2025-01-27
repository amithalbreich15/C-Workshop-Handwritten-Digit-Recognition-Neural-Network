//Activation.h

#include "Matrix.h"
#include <iostream>
#include <cstdint>
#include <string>

#ifndef ACTIVATION_H
#define ACTIVATION_H

#define INCOMPATIBLE_ACT_TYPE_ERR "Error: Incompatible Activation Type.\n"
#define DIVISION_BY_ZERO_ERR "Error: Zero Division Error!\n"
/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType {
    RELU,
    SOFTMAX
};

   /**
   * Activation class - holds the activation type and performs activation
   * function on a layer.
   */
class Activation
{
    ActivationType act_func;
public:
    // Constructor for Activation instance:
    /**
    * Constructor for Activation instance.
    * @param act_type Activation Type to preform.
    */
    explicit Activation(ActivationType act_type);

    /**
    * Getter for Activation Type.
    * @return the Activation Type.
    */
    ActivationType get_activation_type() const;

    /**
    * Applies activation function on input vector.
    * @param input_vector input vector
    * @return Output vector after activation was done on vector (RELU/SOFTMAX)
    */
    Matrix operator()(const Matrix &input_vector) const;
};

#endif //ACTIVATION_H
