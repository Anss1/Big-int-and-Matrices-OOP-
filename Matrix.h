//we can replace this three lines and put #pragma once
#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
    int **data;
    int row, col;
public:
    friend istream& operator>> (istream&, Matrix );
    friend ostream& operator<< (ostream&, Matrix );

    Matrix();
    Matrix(int, int , int *);
    Matrix(const Matrix&);
    void setters(int, int , int *);
//**********************************************
    Matrix operator +(Matrix);
    Matrix operator -(Matrix);
    Matrix operator *(Matrix);
    Matrix operator+(int);
    Matrix operator-(int);
    Matrix operator*(int);
//************************************************
    Matrix operator+= (Matrix);
    Matrix operator-= (Matrix);
    Matrix operator+= (int);
    Matrix operator-= (int);
    Matrix operator++ ();
    Matrix operator-- ();
//****************************************************
    bool operator== (Matrix);
    bool operator!= (Matrix);
    bool Issquare();
    bool Issymetric();
    bool Isidentity();
    Matrix transpose();
//****************************************************

    ~Matrix();

};

// MATRIX_H
