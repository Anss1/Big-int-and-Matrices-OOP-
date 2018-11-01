#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <iostream>
#include <algorithm>

using namespace std;

class BigDecimalInt
{
    int *arr1,size_s;
    char sign ;
public:
    BigDecimalInt(int);
    BigDecimalInt(string );

    BigDecimalInt operator+(BigDecimalInt );
    BigDecimalInt operator-(BigDecimalInt );

    friend ostream& operator<< (ostream&, BigDecimalInt );

    ~BigDecimalInt();

};

#endif // BIGDECIMALINT_H
