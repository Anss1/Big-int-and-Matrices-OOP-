#include "Matrix.h"
#include "BigDecimalInt.h"

int num = 1;

int main()
{

    int ch,s,choose;
    cout<<"\t\t\t\t\t  *** The list of Classes ***\n\n\n"
        <<"1- Matrix.\n2- Big decimal int.\n\n\n";
    cout<<"Enter your choice : ";
    cin>>ch;
    system("cls");
    if(ch == 1)
    {
        int r,c;
        cout<<"How many matrices do you want? --> ";
        cin>>s;
        system("cls");
        Matrix mat[s];

        for(int z=0; z<s; z++)
        {
            char mult;
            cout<<"Enter the Dim of the( "<<num++<< " )Matrix by adding (x or X) between them : ";
            cin>>r>>mult>>c;
            assert(mult=='x'||mult=='X');    //you must cin>>x or X after first number
            cout<<endl<<endl;
            int data1[r*c];
            cout<<"Enter data of the matrix : ";
            for(int i=1; i<= r*c; i++)
            {
                cin>>data1[i];
            }
            mat[z].setters(r,c,data1);
            system("cls");
        }
        cout<<"\t\t\t\t\t  *** The list of operations ***\n\n\n";
        cout<<"1- Addition of two matrices."
            <<"\n2- Subtraction of two matrices.\n3- Multiplication of two matrices."
            <<"\n4- Add number to the matrix and return new matrix.\n5- Sub number from the matrix and return new matrix."
            <<"\n6- Multiply number by the matrix.\n7- Add second matrix to first one."
            <<"\n8- Sub second matrix from first one.\n9- Add a scalar to matrix."
            <<"\n10- Sub a scalar from matrix.\n11- Add 1 to each element of matrix."
            <<"\n12- Sub 1 from each element of matrix.\n13- Check if two matrix are identical."
            <<"\n14- Check if two matrix are not identical.\n15- Check if the matrix is square."
            <<"\n16- Check if the matrix is symmetric.\n17- Check if the matrix is identity.\n18- Transpose the matrix.\n\nEnter the number of operation : ";
        cin>>choose;
        system("cls");

        if(choose==1)
        {
            int nx[2];
            char m;
            cout<<"Enter the pattern like (number of first mat + number of second mat) : ";
            cin>>nx[0]>>m>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]+mat[nx[1]])<<endl;
        }
        else if(choose==2)
        {
            int nx[2];
            char m;
            cout<<"Enter the pattern like (number of first mat - number of second mat) : ";
            cin>>nx[0]>>m>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]-mat[nx[1]])<<endl;
        }
        else if(choose==3)
        {
            int nx[2];
            char m;
            cout<<"Enter the pattern like (number of first mat * number of second mat) : ";
            cin>>nx[0]>>m>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]*mat[nx[1]])<<endl;
        }
        else if(choose==4)
        {
            int nx[2];
            char m;
            cout<<"Enter the pattern like (number of first mat + the scalar) : ";
            cin>>nx[0]>>m>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]+nx[1])<<endl;
        }
        else if(choose==5)
        {
            int nx[2];
            char m;
            cout<<"Enter the pattern like (number of first mat - the scalar) : ";
            cin>>nx[0]>>m>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]-nx[1])<<endl;
        }
        else if(choose==6)
        {
            int nx[2];
            char m;
            cout<<"Enter the pattern like (number of first mat * the scalar) : ";
            cin>>nx[0]>>m>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]*nx[1])<<endl;
        }
        else if(choose==7)
        {
            int nx[2];
            char m[2];
            cout<<"Enter the pattern like (number of first mat += number of second mat) : ";
            cin>>nx[0]>>m[0]>>m[1]>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]+=mat[nx[1]])<<endl;
        }
        else if(choose==8)
        {
            int nx[2];
            char m[2];
            cout<<"Enter the pattern like (number of first mat -= number of second mat) : ";
            cin>>nx[0]>>m[0]>>m[1]>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]-=mat[nx[1]])<<endl;
        }
        else if(choose==9)
        {
            int nx[2];
            char m[2];
            cout<<"Enter the pattern like (number of first mat += the scalar) : ";
            cin>>nx[0]>>m[0]>>m[1]>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]-nx[1])<<endl;
        }
        else if(choose==10)
        {
            int nx[2];
            char m[2];
            cout<<"Enter the pattern like (number of first mat -= the scalar) : ";
            cin>>nx[0]>>m[0]>>m[1]>>nx[1];
            system("cls");
            cout<<(mat[nx[0]]-nx[1])<<endl;
        }
        else if(choose==11)
        {
            int nx;
            cout<<"Enter number of mat : ";
            cin>>nx;
            system("cls");
            ++mat[nx];
            cout<<(mat[nx])<<endl;
        }
        else if(choose==12)
        {
            int nx;
            cout<<"Enter number of mat : ";
            cin>>nx;
            system("cls");
            --mat[nx];
            cout<<(mat[nx])<<endl;
        }
        else if(choose==13)
        {
            int nx[2];
            char m[2];
            cout<<"Enter the pattern like (number of first mat == number of second mat) : ";
            cin>>nx[0]>>m[0]>>m[1]>>nx[1];
            system("cls");
            if((mat[nx[0]]== mat[nx[1]]))
                cout<<"The matrices are identical.\n";
            else
                cout<<"The matrices are not identical.\n";
        }
        else if(choose==14)
        {
            int nx[2];
            char m[2];
            cout<<"Enter the pattern like (number of first mat != number of second mat) : ";
            cin>>nx[0]>>m[0]>>m[1]>>nx[1];
            system("cls");
            if((mat[nx[0]]!= mat[nx[1]]))
                cout<<"The matrices are not identical.\n";
            else
                cout<<"The matrices are identical.\n";
        }
        else if(choose==15)
        {
            int nx;
            cout<<"Enter the number of matrix : ";
            cin>>nx;
            system("cls");
            if(mat[nx].Issquare())
                cout<<"the matrix is square.\n";
            else
                cout<<"the matrix is not square.\n";
        }
        else if(choose==16)
        {
            int nx;
            cout<<"Enter the number of matrix : ";
            cin>>nx;
            system("cls");
            if(mat[nx].Issymetric())
                cout<<"the matrix is symmetric.\n";
            else
                cout<<"the matrix is not symmetric.\n";
        }
        else if(choose==17)
        {
            int nx;
            cout<<"Enter the number of matrix : ";
            cin>>nx;
            system("cls");
            if(mat[nx].Isidentity())
                cout<<"the matrix is identity.\n";
            else
                cout<<"the matrix is not identity.\n";
        }
        else if(choose==18)
        {
            int nx;
            cout<<"Enter the number of matrix : ";
            cin>>nx;
            system("cls");
            cout<<mat[nx].transpose()<<endl;
        }
    }
    else if(ch==2)
    {
        BigDecimalInt num1("333333333333333333333333333333");
        BigDecimalInt num2("-111111111111111111111111111111");
        BigDecimalInt num3 = num2 + num1;
        BigDecimalInt num4 = num2 - num1;
        cout << "num2 + num1 = " << num3 << endl;
        cout << "num2 - num1 = " << num4 << endl;
    }
    return 0;
}
