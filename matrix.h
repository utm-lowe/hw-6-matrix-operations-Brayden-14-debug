/**
 * @file matrix.h
 * @author Brayden Manning (bmannin4@skyhawks.utm.edu)
 * @brief Class definition and operator prototypes of the Matrix class. 
 * @version 0.1
 * @date 2024-10-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix 
{
public:

    /**
     * @brief Construct a new Matrix object
     * 
     * @param rows The number of rows in the matrix.
     * @param cols The number of columns in the matrix.
     */
    Matrix(unsigned int rows, unsigned int cols): m(rows), n(cols) {
        ar = new double*[m];
        for (int i = 0; i < m; ++i) {
            ar[i] = new double[n]();
        }
    }

    /**
     * @brief Copy constructor
     * 
     * @param m The matrix to copy.
     */
    Matrix(const Matrix& rhs): m(rhs.m), n(rhs.n){
        ar = new double*[m];
        for(int i = 0; i < m; ++i){
            ar[i] = new double[n];
            for(int j = 0; j < n; ++j){
                ar[i][j] = rhs.ar[i][j];
            }
        }
    }


    /**
     * @brief Destroy the Matrix object
     * 
     */
    virtual ~Matrix(){
        for (int i = 0; i < m; ++i) {
            delete[] ar[i];
        }
        delete[] ar;
    }

    /**
     * @brief Get the number of rows in the matrix.
     * 
     * @return int The number of rows in the matrix.
     */
    virtual int getRows() const {return m;}

    /**
     * @brief Get the number of columns in the matrix.
     * 
     * @return int The number of columns in the matrix.
     */
    virtual int getCols() const {return n;}

    /**
     * @brief Return a reference to the element at the specified row and column.
     *
     * @param row The row of the element.
     * @param col The column of the element.
     * @return double& A reference to the element at the specified row and column. 
     */
    virtual double& at(unsigned int row, unsigned int col);

    /**
     * @brief Return a const reference to the element at the specified row and column.
     *
     * @param row The row of the element.
     * @param col The column of the element.
     * @return double& A reference to the element at the specified row and column. 
     */
    virtual const double& at(unsigned int row, unsigned int col) const{
        return ar[row][col];
    }

    /**
     * @brief Overloaded assignment operator.
     * 
     * @param rhs The matrix to assign.
     */
    virtual Matrix& operator=(const Matrix& rhs){
        if (this != &rhs){
            for(int i = 0; i < m; i++) delete[] ar[i];
            delete[] ar;

            m = rhs.m;
            n = rhs.n;
            ar = new double*[m];
            for (int i = 0; i < m; ++i){
                ar[i] = new double[n];
                for (int j = 0; j < n; ++j){
                    ar[i][j] = rhs.ar[i][j];
                }
            }
        }
        return *this;
    }

private:
    double **ar;
    int m;
    int n;
};


/**
 * @brief Overloaded operator for the addition of two matrices.
 * 
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return Matrix The sum of the two matrices.
 */
Matrix operator+(const Matrix& m1, const Matrix& m2);

/**
 * @brief Overloaded operator for the subtraction of two matrices.
 * 
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return Matrix The difference of the two matrices.
 */
Matrix operator-(const Matrix& m1, const Matrix& m2);

/**
 * @brief Overloaded operator for the multiplication of two matrices.
 * 
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return Matrix The product of the two matrices.
 */
Matrix operator*(const Matrix& m1, const Matrix& m2);

/**
 * @brief Overloaded operator for the multiplication of a matrix by a scalar.
 * @param scalar The scalar value.
 * @param m The matrix.
 * @return Matrix The product of the matrix and the scalar.
 */
Matrix operator*(double scalar, const Matrix& m);

/* @brief Overloaded operator for the multiplication of a matrix by a scalar.
 * @param m The matrix.
 * @param scalar The scalar value.
 * @return Matrix The product of the matrix and the scalar.
 */
Matrix operator*(const Matrix& m, double scalar);

/**
 * @brief Overloaded operator for the output of a matrix.
 * 
 * @param os The output stream.
 * @param m The matrix.
 * @return std::ostream& The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Matrix& m);

/**
 * @brief Overloaded operator for the input of a matrix.
 * 
 * @param is The input stream.
 * @param m The matrix.
 * @return std::istream& The input stream.
 */
std::istream& operator>>(std::istream& is, Matrix& m);

#endif