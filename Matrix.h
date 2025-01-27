// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <cmath>

#define IDX_OUT_OF_BOUNDS_ERR "Error: Index out of bounds!\n"
#define ROWS_OR_COLS_ERR "Error: Incompatible _rows or _cols number!\n"
#define MEMORY_ALLOC_FAIL "Error: Failed to allocate memory "\
"for matrix elements.\n"
#define FILE_SIZE_ERR "Error: File size does not fit!\n"
#define OPEN_FILE_ERR "Error: Failed to open file!\n"
#define MAT_ADDITION_ERR "Error: Cannot add matrices - sizes are unequal!\n"
#define MAT_MULTIPLICATION_ERR "Error: Cannot multiply matrices!\n"
#define MIN_VALUE 0.1
#define DOT_ERR "Error: cannot perform 'dot' function on matrices!\n"


/**
 * @struct MatrixDims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and in main.cpp.
 */
typedef struct matrix_dims
{
    int rows, cols;
} matrix_dims;

class Matrix
{
private:
    matrix_dims dims{};
    float **elem;
    /**
    * Helper function that dynamically allocates memory for matrix elements.
    */
    void alloc_matrix_elements();

public:
    // Constructors:
    /**
    * Main Constructor:
    * Creates a matrix instance of size rows*cols.
    * @param rows
    * @param cols
    */
    Matrix(int, int);

   /**
   * Default Constructor:
   * Creates a matrix instance of size 1x1.
   */
    Matrix();

    // Destructor:
    /**
     * Destructor of Matrix instance.
     */
    ~Matrix();

    /**
    * Copy Constructor:
    * Copy constructor of class Matrix.
    * @param m
    */
    Matrix(const Matrix &);

    /**
    * Get the number of rows in matrix.
    * @return Number of rows as int.
    */
    int get_rows() const;

    /**
    * Get the number of columns in matrix.
    * @return Number of columns as int.
    */
    int get_cols() const;

    /**
    * Prints the matrix elements one by one with a space between each value
    * each matrix row in a separate row.
    */
    void plain_print() const;

    /**
    * Matrix assignment.
    * @param m A matrix
    * @return The matrix (this) after copy assignment with m matrix data.
    */
    Matrix &operator=(const Matrix &);

    /**
    * Returns the i'th element in the matrix.
    * @param i the index of element
    * @return the i'th element.
    */
    float operator[](int) const;

    /**
    * Const version of operator[]
    * Returns the i'th element in the matrix.
    * @param i the index of element
    * @return the i'th element.
    */
    float &operator[](int);

    /**
    * returns the value of the element in the given index.
    * @param i row index
    * @param j col index
    * @return Value in index (i,j) of matrix.
    */
    float operator()(int, int) const;

    /**
    * Const version of operator [].
    * returns the value of the element in the given index.
    * @param i row index
    * @param j col index
    * @return Value in index (i,j) of matrix.
    */
    float &operator()(int, int);

    /**
    * Adds the other matrix to this matrix
    * @param m A matrix
    * @return Returns this matrix after we add the other matrix to it.
    */
    Matrix &operator+=(const Matrix &);

    /**
    * Reads from a binary file and fills the matrix.
    * @param is the input stream
    * @param read_mat a matrix to fill
    */
    friend std::istream &operator>>(std::istream&, Matrix&);

   /**
   * Prints image from the matrix.
   * @param os the outstream
   * @param m a matrix
   * @return Out stream of the matrix data as an image of a number
   * built with asterisks.
   */
    friend std::ostream &operator<<(std::ostream &, const Matrix &);

    /**
    * Returns the product of 2 matrices multiplication as in linear algebra.
    * @param m1 first matrix
    * @param m2 second matrix
    * @return m1 * m2 as new instance matrix.
    */
    friend Matrix operator*(const Matrix &, const Matrix &);

    /**
    * Scalar multiplication on right.
    * Returns a matrix * scalar.
    * @param mat A const matrix.
    * @param scalar scalar to multiply the matrix with.
    * @return A matrix with all elements multiplied by the scalar.
    */
    friend Matrix operator*(float , const Matrix &);

    /**
    * Scalar multiplication on left.
    * Returns a scalar * matrix.
    * @param scalar scalar to multiply the matrix with.
    * @param mat A const matrix.
    * @return A matrix with all elements multiplied by the scalar.
    */
    friend Matrix operator*(const Matrix &, float );

    /**
    * Sums 2 matrices.
    * @param m1 first matrix.
    * @param m2 second matrix.
    * @return Returns a new Matrix instance which equals the result
    * of addition: m1+m2.
    */
    friend Matrix operator+(const Matrix &, const Matrix &);

    /** This function Transposes the matrix and returns the
    * same matrix as transposed.
    *
    * @return Transposed matrix as this object.
    */
    Matrix &transpose();

    /**
    * Calculates dot product of this matrix and m.
    * @param m other matrix
    * @return A new matrix instance
    * which is the dot product of this matrix and m.
    */
    Matrix dot(const Matrix &m) const;

    /** Returns the matrix as vector - with rows*cols size of rows and cols
    * as 1 - so we get the matrix values represented as a new matrix
    * which is a vector.
    *
    * @return The matrix represented as a vector - returns *this the same
    * object as vector.
    */
    Matrix &vectorize();

    /**
    * Calculates the frobenius norm of the matrix.
    * @return The frobenius norm of the matrix.
    */
    float norm() const;
};


#endif //MATRIX_H
