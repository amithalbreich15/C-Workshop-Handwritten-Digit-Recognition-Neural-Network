#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>
#include "Matrix.h"

using std::ostream;  using std::istream;  using std::endl;
using std::cout; using std::cin;
using std::sqrt; using std::cerr;

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
* Helper function that dynamically allocates memory for matrix elements.
*/
void Matrix::alloc_matrix_elements()
{
    elem = new(std::nothrow) float *[dims.rows];
    if (!elem)
    {
        exit_func(MEMORY_ALLOC_FAIL);
    }
    for (int i = 0; i < dims.rows; ++i)
    {
        elem[i] = new(std::nothrow) float[dims.cols];
        if (!elem[i])

        {
            for (int j = 0; j < i; ++j)
            {
                delete[] elem[j];
            }
            delete[] elem;
            exit_func(MEMORY_ALLOC_FAIL);
        }
    }
}

// Constructors:
/**
* Main Constructor:
* Creates a matrix instance of size rows*cols.
* @param rows
* @param cols
*/
Matrix::Matrix(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        exit_func(ROWS_OR_COLS_ERR);
    }
    dims.rows = rows;
    dims.cols = cols;
    alloc_matrix_elements();
    for (int i = 0; i < dims.rows; ++i)
    {
        for (int j = 0; j < dims.cols; ++j)
        {
            (*this)(i, j) = 0;
        }
    }
}

/**
* Default Constructor:
* Creates a matrix instance of size 1x1.
*/
Matrix::Matrix() : Matrix(1,1)
{}

/**
* Destructor of Matrix instance.
*/
Matrix::~Matrix()

{
    for (int i = 0; i < dims.rows; ++i)

    {
        delete[] elem[i];
    }
    delete[] elem;
}

/**
* Copy Constructor:
* Copy constructor of class Matrix.
* @param m
 */
Matrix::Matrix(const Matrix &m) : Matrix(m.dims.rows, m.dims.cols)
{
    for (int i = 0; i < dims.rows; ++i)
    {
        for (int j = 0; j < dims.cols; ++j)
        {
            (*this)(i, j) = m(i, j);
        }
    }
}

/**
* Get the number of rows in matrix.
* @return Number of rows as int.
*/
int Matrix::get_rows() const

{
    return dims.rows;
}

/**
* Get the number of columns in matrix.
* @return Number of columns as int.
*/
int Matrix::get_cols() const

{
    return dims.cols;
}

/**
* Prints the matrix elements one by one with a space between each value
* each matrix row in a separate row.
*/
void Matrix::plain_print() const
{
    for (int i = 0; i < dims.rows; ++i)
    {
        cout << (*this)(i, 0);
        for (int j = 1; j < dims.cols; ++j)
        {
            cout << " " << (*this)(i, j);
        }
        cout << endl;
    }
    cout << endl;
}

/**
* Matrix assignment.
* @param m A matrix
* @return The matrix (this) after copy assignment with m matrix data.
*/
Matrix &Matrix::operator=(const Matrix &m)
{
    if (this == &m)
    {
        return *this;
    }

    if (dims.rows != m.dims.rows || dims.cols != m.dims.cols)
    {
        for (int i = 0; i < dims.rows; ++i)
        {
            delete[] elem[i];
        }
        delete[] elem;

        dims.rows = m.dims.rows;
        dims.cols = m.dims.cols;
        alloc_matrix_elements();
    }
    for (int i = 0; i < dims.rows; ++i)
    {
        for (int j = 0; j < dims.cols; ++j)
        {
            (*this)(i, j) = m(i, j);
        }
    }
    return *this;
}

/**
* Const version of operator[].
* Returns the i'th element in the matrix.
* @param i the index of element
* @return the i'th element.
*/
float Matrix::operator[](int i) const
{
    if (i < 0 || i >= dims.rows * dims.cols)
    {
        exit_func(IDX_OUT_OF_BOUNDS_ERR);
    }
    return elem[i / dims.cols][i % dims.cols];
}

/**
*
* Returns the i'th element in the matrix.
* @param i the index of element
* @return the i'th element.
*/
float &Matrix::operator[](int i)
{
    if (i < 0 || i >= dims.rows * dims.cols)
    {
        exit_func(IDX_OUT_OF_BOUNDS_ERR);
    }
    return elem[i / dims.cols][i % dims.cols];
}

/**
 * Const version of operator [].
* returns the value of the element in the given index.
* @param i row index
* @param j col index
* @return Value in index (i,j) of matrix.
*/
float Matrix::operator()(int i, int j) const
{
    if (i >= dims.rows || j >= dims.cols || i < 0 || j < 0)
    {
        exit_func(IDX_OUT_OF_BOUNDS_ERR);
    }
    return elem[i][j];
}

/**
* returns the value of the element in the given index.
* @param i row index
* @param j col index
* @return Value in index (i,j) of matrix.
*/
float &Matrix::operator()(int i, int j)
{
    if (i >= dims.rows || j >= dims.cols || i < 0 || j < 0)
    {
        exit_func(IDX_OUT_OF_BOUNDS_ERR);
    }
    return elem[i][j];
}

/**
* Adds the other matrix to this matrix
* @param m A matrix.
* @return Returns this matrix after we add the other matrix to it.
*/
Matrix &Matrix::operator+=(const Matrix &m)
{
    if (dims.rows != m.dims.rows || dims.cols != m.dims.cols)
    {
        exit_func(MAT_ADDITION_ERR);
    }
    for (int i = 0; i < dims.rows; ++i)
    {
        for (int j = 0; j < dims.cols; ++j)
        {
            (*this)(i, j) += m(i, j);
        }
    }
    return *this;
}

/**
* Reads from a binary file and fills the matrix.
* @param is the input stream
* @param read_mat a matrix to fill
*/
std::istream &operator>>(std::istream& is, Matrix& read_mat)
{
    if (!is)
    {
        exit_func(OPEN_FILE_ERR);
    }
    is.seekg(0, std::istream::end);
    size_t file_len = is.tellg();
    is.seekg(0, std::istream::beg);
    size_t matrix_len =
            read_mat.dims.cols * read_mat.dims.rows * sizeof(float);
    if (file_len == matrix_len)
    {
        for (int i = 0; i < read_mat.dims.rows; ++i)
        {
            size_t read_size = sizeof(float) * read_mat.dims.cols;
            is.read((char *) (read_mat.elem[i]), read_size);
        }
    }
    if (is.eof() || is.fail())
    {
        exit_func(FILE_SIZE_ERR);
    }
    return is;
}

/**
* Prints image from the matrix.
* @param os the outstream
* @param m a matrix
* @return Out stream of the matrix data as an image of a number
* built with asterisks.
*/
ostream &operator<<(ostream &os, const Matrix &m)
{
    for (int i = 1; i < m.dims.rows; ++i)
    {
        for (int j = 1; j < m.dims.cols; ++j)
        {
            if (m(i, j) > MIN_VALUE)
            {
                os << "**";
            } else
            {
                os << "  ";
            }
        }
        os << endl;
    }
    return os;
}

/**
* Returns the product of 2 matrices multiplication as in linear algebra.
* @param m1 first matrix
* @param m2 second matrix
* @return m1 * m2 as new instance matrix.
*/
Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    if (m1.dims.cols != m2.dims.rows)
    {
        exit_func(MAT_MULTIPLICATION_ERR);
    }
    Matrix mult_mat(m1.dims.rows, m2.dims.cols);
    for (int i = 0; i < mult_mat.dims.rows; ++i)
    {
        for (int j = 0; j < mult_mat.dims.cols; ++j)
        {
            for (int k = 0; k < m1.dims.cols; ++k)
            {
                mult_mat(i, j) += m1(i, k) * m2(k, j);
            }
        }
    }
    return mult_mat;
}

/**
* Scalar multiplication on right.
* Returns a matrix * scalar.
* @param mat A const matrix.
* @param scalar scalar to multiply the matrix with.
* @return A matrix with all elements multiplied by the scalar.
*/
Matrix operator*(const Matrix &mat, float scalar)
{
    Matrix scalar_mat(mat);
    for (int i = 0; i < mat.dims.rows; ++i)
    {
        for (int j = 0; j < mat.dims.cols; ++j)
        {
            scalar_mat(i, j) *= scalar;
        }
    }
    return scalar_mat;
}

/**
* Scalar multiplication on left.
* Returns a scalar * matrix.
* @param scalar scalar to multiply the matrix with.
* @param mat A const matrix.
* @return A matrix with all elements multiplied by the scalar.
*/
Matrix operator*(float scalar, const Matrix &mat)
{
    return mat*scalar;
}

/**
* Sums 2 matrices.
* @param m1 first matrix.
* @param m2 second matrix.
* @return Returns a new Matrix instance which equals the result of addition:
* m1+m2.
*/
Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    if (m1.dims.rows != m2.dims.rows ||
        m1.dims.cols != m2.dims.cols)
    {
        exit_func(MAT_ADDITION_ERR);
    }
    Matrix add_mat(m1.dims.rows, m1.dims.cols);
    for (int i = 0; i < m1.dims.rows; i++)
    {
        for (int j = 0; j < m1.dims.cols; j++)
        {
            add_mat(i, j) = m1(i, j) + m2(i, j);
        }
    }
    return add_mat;
}

/** This function Transposes the matrix and returns the
 * same matrix as transposed.
 *
 * @return Transposed matrix - returns the same matrix (this).
 */
Matrix &Matrix::transpose()
{
    Matrix transposed(dims.cols, dims.rows); // switch col num with row num.
    for (int i = 0; i < dims.rows; ++i)
    {
        for (int j = 0; j < dims.cols; ++j)
        {
            transposed(j, i) = (*this)(i, j);
        }
    }
    *this = transposed; // Assignment of transposed matrix to *this object.
    return *this;
}

/** Returns the matrix as vector - with rows*cols size of rows and cols as 1 -
 * so we get the matrix values represented as a new matrix which is a vector.
 *
 * @return The matrix represented as a vector - returns *this the same object
 * as vector.
 */
Matrix &Matrix::vectorize()
{
    const Matrix vectorized(dims.rows * dims.cols, 1);
    for (int i = 0; i < dims.rows; ++i)
    {
        for (int j = 0; j < dims.cols; ++j)
        {
            *vectorized.elem[i * dims.cols + j] = (*this)(i,j);
            // Assigns element of the matrix in an array of floats where each
            // array (pointer) stores only 1 float value.
        }
    }
    *this = vectorized; // assignment of vectorized matrix to *this object.
    return *this;
}

/**
* Calculates dot product of this matrix and other matrix.
* @param m Other matrix
* @return A new matrix instance
* which is the dot product of this matrix and m.
*/
Matrix Matrix::dot(const Matrix &m) const
{
    if (dims.rows != m.dims.rows || dims.cols != m.dims.cols)
    {
        exit_func(DOT_ERR);
    }
    Matrix dot_mat(dims.rows, dims.cols);
    for (int i = 0; i < dims.rows; ++i)
    {
        for (int j = 0; j < dims.cols; ++j)
        {
            dot_mat(i, j) = m(i, j) * (*this)(i, j);
            // Dot product for each elem
        }
    }
    return dot_mat;
}

/**
* Calculates the frobenius norm of the matrix.
* @return The frobenius norm of the matrix as a float.
*/
float Matrix::norm() const
{
    float sq_sum = 0;
    for (int i = 0; i < dims.rows; i++)
    {
        for (int j = 0; j < dims.cols; j++)
        {
            sq_sum += (*this)(i, j)*(*this)(i, j);
        }
    }
    // Return the square root of the sum of squares
    return sqrtf(sq_sum);
}
