//
// Created by eric on 2020-10-08.
//

#ifndef ASN01_MATRIX_HPP
#define ASN01_MATRIX_HPP


#include <vector>
#include <iostream>

using namespace std;

class Matrix {
protected:
    int rows;
    int cols;
    vector<vector<double>> mat;
public:
    Matrix();
    Matrix(int n);
    Matrix(int r, int c);
    Matrix(vector<double> v);
    void set_value(int r, int c, double val);
    double get_value(int r, int c);
    void clear();
    ~Matrix();
    friend ostream& operator <<(ostream& os, const Matrix& matrix);
    friend bool operator == (const Matrix& a, const Matrix& b);
    friend bool operator != (const Matrix& a, const Matrix& b);
    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);
    void mySwap(Matrix& first, Matrix& second);
    Matrix& operator=(Matrix& m);
    Matrix& operator+=(const Matrix& m);
    Matrix& operator-=(const Matrix& m);
    friend Matrix operator+(Matrix &m, const Matrix& n);
    friend Matrix operator-(Matrix &m, const Matrix& n);
    Matrix& operator*=(const Matrix& m);
    friend Matrix operator*(Matrix &m, const Matrix& n);
};


#endif //ASN01_MATRIX_HPP
