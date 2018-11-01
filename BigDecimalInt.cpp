#include "BigDecimalInt.h"


BigDecimalInt::BigDecimalInt(int s)
{
    arr1 = new int [s];
}

BigDecimalInt::BigDecimalInt(string n)
{
    if(n[0] == '-')
    {
        sign = '-';
        size_s = n.size()-1;
        arr1 = new int[n.size()-1];
        reverse(n.begin(),n.end());
        for(unsigned int i=0 ; i< n.size()-1; i++)
        {
            arr1[i] = n[i] - '0';
        }
    }
    else
    {
        sign = '+';
        size_s = n.size();
        arr1 = new int[n.size()];
        reverse(n.begin(),n.end());
        for(unsigned int i=0 ; i< n.size(); i++)
        {
            arr1[i] = n[i] - '0';
        }
    }
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt big)
{
    BigDecimalInt temp(size_s);
    temp.size_s=size_s;
    if((sign == '+'&&big.sign == '+') || (sign == '-'&&big.sign == '-'))
    {
        for(int i=0; i<size_s; i++)
        {
            if(arr1[i] + big.arr1[i] > 9)
            {
                temp.arr1[i] = (arr1[i] + big.arr1[i]) - 10;
                if(i == (size_s-1))
                {
                    temp.arr1[++i] = 1;
                }
                else
                    arr1[i+1]++;
            }
            else
                temp.arr1[i] = arr1[i] + big.arr1[i];
        }
    }

    else if(sign == '+'&&big.sign == '-')
    {
        for(int i=0; i<size_s; i++)
        {
            if(arr1[i] - big.arr1[i] < 0)
            {
                if(arr1[i+1] > 0)
                {
                    arr1[i+1]--;
                    arr1[i] += 10;
                    temp.arr1[i] = arr1[i] - big.arr1[i];
                }
            }
            else
                temp.arr1[i] = arr1[i] - big.arr1[i];
        }
    }
    else
    {
        for(int i=0; i<size_s; i++)
        {
            if( big.arr1[i] - arr1[i]< 0)
            {
                if(big.arr1[i+1] > 0)
                {
                    big.arr1[i+1]--;
                    big.arr1[i] += 10;
                    temp.arr1[i] = big.arr1[i] - arr1[i];
                }
            }
            else
                temp.arr1[i] = big.arr1[i] - arr1[i];
        }
    }
    /*if(differncemin < differncemax-1)
    {
        if(valid)
        {
            for(int i=differncemin+1; i<differncemax; i++)
                temp.arr1[i] = (size_s > big.size_s ? arr1[i-1]:big.arr1[i-1]);
        }
        else
        {
            for(int i=differncemin; (i<differncemax); i++)
                temp.arr1[i] = (size_s > big.size_s ? arr1[i-1]:big.arr1[i-1]);
        }
    }
    */
    return temp;
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt big)
{
    BigDecimalInt temp(size_s);
    temp.size_s = size_s;
    if((sign == '+'&&big.sign == '+') || (sign == '-'&&big.sign == '-'))
    {
        for(int i=0; i<size_s; i++)
        {
            if(arr1[i] - big.arr1[i] < 0)
            {
                if(arr1[i+1] > 0)
                {
                    arr1[i+1]--;
                    arr1[i] += 10;
                    temp.arr1[i] = arr1[i] - big.arr1[i];
                }
            }
            else
                temp.arr1[i] = arr1[i] - big.arr1[i];
        }
    }
    else
    {
        for(int i=0; i<size_s; i++)
        {
            if(arr1[i] + big.arr1[i] > 9)
            {
                temp.arr1[i] = (arr1[i] + big.arr1[i]) - 10;
                if(i == (size_s-1))
                {
                    temp.arr1[++i] = 1;
                }
                else
                    arr1[i+1]++;
            }
            else
                temp.arr1[i] = arr1[i] + big.arr1[i];
        }
    }

    return temp;
}
ostream &operator<< (ostream& out,BigDecimalInt obj)
{
    for(int i=obj.size_s-1; i>=0; i--)
    {
        out<<obj.arr1[i];
    }
    out<<endl;
    return out;
}



BigDecimalInt::~BigDecimalInt()
{
    delete[] arr1;
}
