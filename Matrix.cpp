#include "Matrix.h"

Matrix::Matrix():row(0),col(0){}
Matrix::Matrix(int _row, int _col, int num[])
{
    row = _row;
    col = _col;

    data = new int *[_row];
    for(int i=0; i<_row; i++)
        data[i]=new int[_col];


    for(int i=0; i<_row; i++)
    {
        for(int j=0; j<_col; j++)
            data[i][j]=num[i*_col+j];
    }
}
void Matrix::setters(int _r,int _c,int _num[])
{
    row = _r;
    col = _c;

    data = new int *[_r];
    for(int i=0; i<_r; i++)
        data[i]=new int[_c];

    for(int i=0; i<_r; i++)
    {
        for(int j=0; j<_c; j++)
            data[i][j]=_num[i*_c+j];
    }
}
Matrix::Matrix(const Matrix &newobj)
{
    row = newobj.row;
    col = newobj.col;

    data = new int *[newobj.row];
    for(int i=0; i<newobj.row; i++)
        data[i]=new int[newobj.col];


    for(int i=0; i<newobj.row; i++)
    {
        for(int j=0; j<newobj.col; j++)
            data[i][j]=newobj.data[i][j];
    }
}
ostream& operator<< (ostream& output, Matrix m)
{
    output<<"Matrix as follows ("<<m.row<<"x"<<m.col<<")"<<endl;
    for(int i=0; i<m.row; i++)
    {
        for(int j=0; j<m.col; j++)
            output<<m.data[i][j]<<" ";
        output<<endl;
    }
    return output;
}
Matrix Matrix:: operator +(Matrix m1)
{
    int data1[row*col];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            data1[i*m1.col+j]=m1.data[i][j] + data[i][j];
    }
    Matrix m3(m1.row,m1.col,data1);
    return m3;
}
Matrix Matrix:: operator -(Matrix m1)
{
    int data1[row*col];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            data1[i*m1.col+j] = data[i][j] - m1.data[i][j] ;
    }
    Matrix m3(m1.row,m1.col,data1);
    return m3;
}
Matrix Matrix:: operator *(Matrix m1)
{
    assert(col == m1.row);
    int data1[row][m1.col];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < m1.col; j++)
        {
            data1[i][j]=0;
        }
    for(int i=0; i < row; i++)
    {
        for(int j=0; j < m1.col; j++)
        {
            for(int k=0; k < col; k++)
                data1[i][j] += data[i][k] * m1.data[k][j];
        }
    }
    Matrix m3(row,m1.col,*data1);
    return m3;
}
Matrix Matrix:: operator+(int scalar)
{
    int data1[row*col];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            data1[i*col+j]=data[i][j] + scalar;
    }
    Matrix m3(row,col,data1);
    return m3;
}
Matrix Matrix:: operator-(int scalar)
{
    int data1[row*col];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            data1[i*col+j]=data[i][j] - scalar;
    }
    Matrix m3(row,col,data1);
    return m3;
}
Matrix Matrix:: operator*(int scalar)
{
    int data1[row*col];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            data1[i*col+j]=data[i][j] * scalar;
    }
    Matrix m3(row,col,data1);
    return m3;
}
Matrix Matrix:: operator+= (Matrix m1)
{
    for(int i=0; i<row;i++)
    {
        for(int j=0; j<col;j++)
            data[i][j] += m1.data[i][j];
    }
    return (*this);
}
Matrix Matrix:: operator-= (Matrix m1)
{
    for(int i=0; i<row;i++)
    {
        for(int j=0; j<col;j++)
            data[i][j] -= m1.data[i][j];
    }
    return (*this);
}
Matrix Matrix:: operator+= (int scalar)
{
    for(int i=0; i<row;i++)
    {
        for(int j=0; j<col;j++)
            data[i][j] += scalar;
    }
    return (*this);
}

Matrix Matrix:: operator-= (int scalar)
{
    for(int i=0; i<row;i++)
    {
        for(int j=0; j<col;j++)
            data[i][j] -= scalar;
    }
    return (*this);
}
Matrix Matrix:: operator++ ()
{
    for(int i=0; i<row;i++)
    {
        for(int j=0; j<col;j++)
            ++data[i][j];
    }
    return (*this);
}
Matrix Matrix:: operator-- ()
{
    for(int i=0; i<row;i++)
    {
        for(int j=0; j<col;j++)
            --data[i][j];
    }
    return (*this);
}
bool Matrix:: operator== (Matrix m1)
{
    for(int i=0; i<row;i++)
    {
        for(int j=0; j<col;j++)
            if(data[i][j] != m1.data[i][j])
                {return false;return 0;}
    }
    return true;
}
bool Matrix:: operator!= (Matrix m1)
{
    for(int i=0; i<row;i++)
    {
        for(int j=0; j<col;j++)
            if(data[i][j] == m1.data[i][j])
                {return false;return 0;}
    }
    return true;
}
bool Matrix:: Issquare()
{
    if(col==row)
        return true;
    else
        return false;
}
bool Matrix:: Issymetric()
{
    if(col != row)
    {
        return false;
        return 0;
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            if(data[i][j] != data[j][i])
            {return false;return 0;}
    }
    return true;
}
bool Matrix:: Isidentity()
{
    if(col != row)
    {
        return false;
        return 0;
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            if((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0))
            {return false;return 0;}
    }
    return true;

}
Matrix Matrix:: transpose()
{
    int data1[row*col];
    for(int i=0; i<row;i++)
    {
        for(int j=0; j<col;j++)
            data1[i*col+j]= data[j][i];
    }
    Matrix m3(row,col,data1);
    return m3;
}








Matrix::~Matrix()
{
    for(int i=0; i<row; i++)
        delete[] data[i];
    delete[] data;


}

