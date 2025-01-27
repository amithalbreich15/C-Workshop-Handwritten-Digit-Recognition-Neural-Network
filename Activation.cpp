#include <cmath>
#include <iostream>
#include <ostream>
#include "Activation.h"

using std::ostream;  using std::istream;  using std::endl;
using std::cout; using std::cin; using std::cerr;

/**
* Helper function that prints a message and then terminates the program with
* EXIT_FAILURE Code.
* @param error_msg An error message to present in cerr before
* program terminates.
* @param
*/
static void exit_func(const std::string &error_msg)
{
    cerr << error_msg << endl;
    exit(EXIT_FAILURE);
}

/**
* Getter for Activation Type.
* @return the Activation Type.
*/
ActivationType Activation::get_activation_type() const
{
    return act_func;
}

// Constructor for Activation instance:
/**
* Constructor for Activation instance.
* @param act_type Activation Type to preform.
*/
Activation::Activation(const ActivationType act_type) : act_func(act_type)
{
    if (act_type != SOFTMAX && act_type != RELU)
    {
        exit_func(INCOMPATIBLE_ACT_TYPE_ERR);
    }
}

/**
* Applies activation function on input vector.
* @param input_vector input vector
* @return Output vector after activation was done on vector (RELU/SOFTMAX)
*/
Matrix Activation::operator()(const Matrix &input_vector) const
{
    Matrix output_vector(input_vector.get_rows(), input_vector.get_cols());
    output_vector = input_vector;

    switch (act_func)
    {
        case RELU:
            for (int i = 0; i < output_vector.get_rows(); ++i)
            {
                for (int j = 0; j < output_vector.get_cols(); ++j)
                {
                    if (output_vector(i, j) < 0)

                    {
                        output_vector(i, j) = 0;
                    }
                }
            }
            break;
        case SOFTMAX:
            float sum = 0;
            for (int i = 0; i < output_vector.get_rows(); ++i)

            {
                for (int j = 0; j < output_vector.get_cols(); ++j)
                {
                    sum+= std::exp(output_vector(i,j));
                    output_vector(i,j) = std::exp(output_vector(i,j));
                }
            }
            if (sum == 0)
            {
                exit_func(DIVISION_BY_ZERO_ERR);
            }
            output_vector = ((1/sum) * output_vector);
            break;
    }
    return output_vector;
}

