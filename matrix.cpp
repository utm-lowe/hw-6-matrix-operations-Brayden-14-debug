#include "matrix.h"
#include <iomanip>

double& Matrix::at(unsigned int row, unsigned int col){
    return ar[row][col];
}

Matrix operator+(const Matrix& m1, const Matrix& m2){
    Matrix res(m1.getRows(), m1.getCols());
    for (int i = 0; i < m1.getRows(); ++i)
        for (int j = 0; j < m1.getCols(); ++j)
            res.at(i,j) = m1.at(i,j) + m2.at(i,j);
    return res;
}

Matrix operator-(const Matrix& m1, const Matrix& m2){
    Matrix res(m1.getRows(), m1.getCols());
    for (int i = 0; i < m1.getRows(); ++i)
        for (int j = 0; j < m1.getCols(); ++j)
            res.at(i,j) = m1.at(i,j) - m2.at(i,j);
    return res;
}

Matrix operator*(const Matrix& m1, const Matrix& m2){
    Matrix res(m1.getRows(), m2.getCols());
    for (int i = 0; i < m1.getRows(); ++i)
        for (int j = 0; j < m2.getCols(); ++j){
            double sum = 0.0;
            for (int k = 0; k < m1.getCols(); ++k)
                sum += m1.at(i,k) * m2.at(k,j);
            res.at(i,j) = sum;
        }
    return res;
}

Matrix operator*(double scalar, const Matrix& m){
    Matrix res(m.getRows(), m.getCols());
    for (int i = 0; i < m.getRows(); ++i)
        for (int j = 0; j < m.getCols(); ++j)
            res.at(i,j) = scalar * m.at(i,j);
    return res;
}

Matrix operator*(const Matrix& m, double scalar){
    return scalar * m;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m){
    for (int i = 0; i < m.getRows(); ++i){
        for (int j = 0; j < m.getCols(); ++j)
            os << std::setw(10) << m.at(i,j) << " ";
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m){
    for (int i = 0; i < m.getRows(); ++i)
        for (int j = 0; j < m.getCols(); ++j)
            is >> m.at(i,j);
    return is;
}