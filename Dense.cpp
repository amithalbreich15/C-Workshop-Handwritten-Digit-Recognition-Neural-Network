
#include "Matrix.h"
#include "Dense.h"

using std::string;
using std::cerr;
using std::endl;

/**
* Helper function that prints a message and then terminates the program with
* EXIT_FAILURE Code.
* @param error_msg An error message to present in cerr before
* program terminates.
* @param
*/
static void exit_func(const string &error_msg)
{
    cerr << error_msg << endl;
    exit(EXIT_FAILURE);
}

// Constructor for Dense instance:
/**
 * Constructor for Dense instance.
 * @param weights Weights Matrix
 * @param bias Bias vector (also Matrix)
 * @param act_type Activation Type
 */
Dense::Dense(const Matrix &weights, const Matrix &bias,
             ActivationType act_type)
        : _weights(weights), _bias(bias),
          act(act_type)
{
    if (bias.get_rows() != weights.get_rows())
    {
        exit_func(BIAS_WEIGHTS_ROWS_ERR);
    }
}

/**
* Getter of weights of specific layer
* @return The weights of specific layer
*/
Matrix Dense::get_weights() const
{
    return _weights;
}

/**
* Getter of bias of specific layer
* @return The bias of specific layer
*/
Matrix Dense::get_bias() const
{
    return _bias;
}

/**
* Applies the layer on input and returns output matrix
* @param m input matrix
* @return the output matrix.
*/
Activation Dense::get_activation() const
{
    return act;
}

Matrix Dense::operator()(const Matrix &m) const
{
    Matrix mult_res_mat = (_weights * m);
    Matrix add_result = mult_res_mat + _bias;
    return act(add_result);
}

