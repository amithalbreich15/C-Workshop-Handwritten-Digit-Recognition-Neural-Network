#include "MlpNetwork.h"

#define ZERO_DIGIT 0

#define TEN_DIGIT 10

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

/**
* Constructor for MlpNetwork instance.
* @param weights Weights list
* @param biases Biases list
*/
MlpNetwork::MlpNetwork(const Matrix *weights, const Matrix *biases) :
        dense1(weights[0], biases[0], RELU),
        dense2(weights[1], biases[1], RELU),
        dense3(weights[2], biases[2], RELU),
        dense4(weights[3], biases[3], SOFTMAX)
{
    for (int i = 0; i < MLP_SIZE; ++i)
    {
        if (weights[i].get_rows() != weights_dims[i].rows ||
            weights[i].get_cols() != weights_dims[i].cols ||
            biases[i].get_rows() != bias_dims[i].rows ||
            biases[i].get_cols() != bias_dims[i].cols)
        {
            exit_func(BIAS_OR_WEIGHTS_SIZE_ERR);
        }
    }
}

/**
* Applies the entire network on input.
* @param image Matrix that represents an image to be read.
* @return digit struct with the highest probability to be the correct digit
*/
digit MlpNetwork::operator()(const Matrix &image) const
{
    Matrix out1 = dense1(image);
    Matrix out2 = dense2(out1);
    Matrix out3 = dense3(out2);
    Matrix final_output = dense4(out3);
    digit best_match;
    best_match.value = ZERO_DIGIT;
    best_match.probability = 0.0;
    for (int i = ZERO_DIGIT; i < TEN_DIGIT; i++)
    {
        if (final_output[i] > best_match.probability)
        {
            best_match.probability = final_output[i];
            best_match.value = i;
        }
    }
    return best_match;
}
