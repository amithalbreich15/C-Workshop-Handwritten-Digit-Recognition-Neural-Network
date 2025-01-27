//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Dense.h"

#define MLP_SIZE 4


#define BIAS_OR_WEIGHTS_SIZE_ERR "Error: One of matrices size of rows or "\
"columns does not fit!\n"
/**
 * @struct digit
 * @brief Identified (by Mlp network) digit with
 *        the associated probability.
 * @var value - Identified digit value
 * @var probability - identification probability
 */
typedef struct digit
{
    unsigned int value;
    float probability;
} digit;

const matrix_dims img_dims = {28, 28};
const matrix_dims weights_dims[] = {{128, 784},
                                    {64, 128},
                                    {20, 64},
                                    {10, 20}};
const matrix_dims bias_dims[]    = {{128, 1},
                                    {64, 1},
                                    {20, 1},
                                    {10, 1}};
/**
   * MlpNetwork Class - The class that holds the
   * MlpNetwork with all the layers.
   */
class MlpNetwork
{
public:
    /**
    * Constructor for MlpNetwork instance.
    * @param weights Weights list
    * @param biases Biases list
    */
    MlpNetwork(const Matrix *weights, const Matrix *biases);

   /**
   * Applies the entire network on input.
   * @param image Matrix that represents an image to be read.
   * @return digit struct with the highest probability to be the correct digit
   */
    digit operator()(const Matrix &image) const;
private:
    const Dense dense1, dense2, dense3, dense4;

};


#endif // MLPNETWORK_H
