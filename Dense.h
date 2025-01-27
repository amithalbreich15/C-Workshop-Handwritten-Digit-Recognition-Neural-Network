#include "Activation.h"

#ifndef DENSE_H
#define DENSE_H

#define BIAS_WEIGHTS_ROWS_ERR "Error: size of bias rows is incompatible with "\
"weights rows!\n"

/**
     * Dense Class - class that describes a layer on the network.
     */
class Dense
{
private:
    const Matrix _weights;
    const Matrix _bias;
    const Activation act;
public:
    // Constructor for Dense instance:
    /**
     * Constructor for Dense instance.
     * @param weights Weights Matrix
     * @param bias Bias vector (also Matrix)
     * @param act_type Activation Type
     */
    Dense(const Matrix &weights, const Matrix &bias, ActivationType act_type);

    /**
    * Getter of weights of specific layer
    * @return The weights of specific layer
    */
    Matrix get_weights() const;

    /**
    * Getter of bias of specific layer
    * @return The bias of specific layer
    */
    Matrix get_bias() const;

    /**
    * Getter of activation of this layer
    * @return the activation of this layer
    */
    Activation get_activation() const;

    /**
    * Applies the layer on input and returns output matrix
    * @param m input matrix
    * @return the output matrix.
    */
    Matrix operator()(const Matrix &m) const;

};

#endif //DENSE_H
