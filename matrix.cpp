//
// Created by eric on 2020-10-08.
//

#include "matrix.hpp"
#include <iostream>
#include <math.h>
Matrix::Matrix() {
    mat.assign(1, vector<double>(1,0));
    rows = 1;
    cols = 1;
}

Matrix::Matrix(int n) {
    if (n <= 0) {
        throw "Number smaller than or equal to zero";
    }
    mat.assign(n, vector<double>(n,0));
    rows = n;
    cols = n;
}

Matrix::Matrix(int r, int c) {
    if (r <= 0 || c <= 0) {
        throw "Number smaller than or equal to zero";
    }
    mat.assign(r, vector<double>(c,0));
    rows = r;
    cols = c;
}

Matrix::Matrix(vector<double> v) {
    double sr = sqrt(v.size());
    int index = 0;
    if (sr - floor(sr) == 0) {
        rows = sr;
        cols = sr;
        for (int i = 0; i < sr; i++) {
            mat.push_back(vector<double>());
            for (int j = 0; j < sr; j++) {
                mat[i].push_back(v[index++]);
            }
        }
    } else {
        throw "The vector size is not a square";
    }
}

void Matrix::set_value(int r, int c, double val) {
    if (r < 0 || c < 0) {
        throw "Number smaller than or equal to zero";
    }
    if (r >= mat.size() || c >= mat[0].size()) {
        throw "Number too large";
    }
    mat[r][c] = val;
}

double Matrix::get_value(int r, int c) {
    if (r < 0 || c < 0) {
        throw "Number smaller than or equal to zero";
    }
    if (r >= mat.size() || c >= mat[0].size()) {
        throw "Number too large";
    }
    return mat[r][c];
}

void Matrix::clear() {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); i++) {
            mat[i][j] = 0;
        }
    }
}

Matrix::~Matrix() {
    cout << "Matrix has been destroyed" << endl;
}

ostream &operator<<(ostream &os, const Matrix &matrix) {
    for (int i = 0; i < matrix.mat.size(); i++) {
        for (int j = 0; j < matrix.mat[0].size(); j++) {
            os << matrix.mat[i][j]<< " ";
        }
        os << endl;
    }
    os << endl;
    return os;
}

bool operator==(const Matrix &a, const Matrix &b) {
    if (a.rows == b.rows && a.cols == b.cols) {
        for (int i = 0; i < a.mat.size(); i++) {
            for (int j = 0; j < a.mat[0].size(); j++) {
                if (abs(a.mat[i][j] - b.mat[i][j]) >= 1) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool operator!=(const Matrix &a, const Matrix &b) {
    return !(a == b);
}

void Matrix::mySwap(Matrix &first, Matrix &second) {
    swap(first.cols, second.cols);
    swap(first.rows, second.cols);
    swap(first.mat, second.mat);

}

Matrix &Matrix::operator=(Matrix &m) {
    mySwap(*this, m);
    return *this;
}

Matrix &Matrix::operator++() {
    for (int i = 0; i < this->mat.size(); i++) {
        for (int j = 0; j < this->mat[0].size(); j++) {
            ++mat[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp(*this);
    for (int i = 0; i < this->mat.size(); i++) {
        for (int j = 0; j < this->mat[0].size(); j++) {
            mat[i][j]++;
        }
    }
    return temp;
}

Matrix &Matrix::operator--() {
    for (int i = 0; i < this->mat.size(); i++) {
        for (int j = 0; j < this->mat[0].size(); j++) {
            --mat[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix temp(*this);
    for (int i = 0; i < this->mat.size(); i++) {
        for (int j = 0; j < this->mat[0].size(); j++) {
            mat[i][j]--;
        }
    }
    return temp;
}

Matrix &Matrix::operator+=(const Matrix &m) {
    if (this->cols == m.cols && this->rows == m.rows) {
        for (int i = 0; i < this->mat.size(); i++) {
            for (int j = 0; j < this->mat[0].size(); j++) {
                this->mat[i][j] += m.mat[i][j];
            }
        }
        return *this;
    } else {
        throw "Cannot += because matrices are not the same size";
    }
}

Matrix &Matrix::operator-=(const Matrix &m) {
    if (this->cols == m.cols && this->rows == m.rows) {
        for (int i = 0; i < this->mat.size(); i++) {
            for (int j = 0; j < this->mat[0].size(); j++) {
                this->mat[i][j] -= m.mat[i][j];
            }
        }
        return *this;
    } else {
        throw "Cannot -= because matrices are not the same size";
    }
}

Matrix operator+(Matrix &m, const Matrix &n) {
    if (m.cols == n.cols && m.rows == n.rows) {
        m += n;
        return m;
    } else {
        throw "Cannot + because matrices are not the same size";
    }
}

Matrix operator-(Matrix &m, const Matrix &n) {
    if (m.cols == n.cols && m.rows == n.rows) {
        m -= n;
        return m;
    } else {
        throw "Cannot - because matrices are not the same size";
    }
}

Matrix &Matrix::operator*=(const Matrix &m) {
    vector<vector<double>> temp(m.cols, vector<double>(this->cols));
    if (this->cols == m.rows) {
        for (int i = 0; i < this->cols; i++) {
            for (int j = 0; j < m.cols; j++) {
                for (int k = 0; k < this->rows; k++) {
                    temp[i][j] += this->mat[i][k] * m.mat[k][j];
                }
            }
        }
        this->mat = temp;
        return *this;
    } else {
        throw "Cannot *= because number of columns don't match number of rows";
    }
}

Matrix operator*(Matrix &m, const Matrix &n) {
    if (m.cols == n.rows) {
        m *= n;
        return m;
    } else {
        throw "Cannot *= because number of columns don't match number of rows";
    }
}



