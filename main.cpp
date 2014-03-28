#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
using namespace std;
void TestingMatrix();

int main()
{


    cout<<"Three empty matrices have been created"<<endl;
    cout<<"Please enter a matrix in the following form:"<<endl;
    cout<<"[#Rows, #Columns, numbers in row/column]"<<endl;
    cout<<"EXAMPLE:  [2 3 1 1 1 2 2 2] will output: "<<endl;
    cout<<"           1 1 1"<<endl;
    cout<<"           2 2 2"<<endl;


    TestingMatrix();
    return 0;
}

void TestingMatrix()
{
    Matrix<int>  a,b,c;


    cout<<"Initial Matrix set to ["<<a.numrows()<<"  "<<a.numcols()<<"]"<<endl;
    cout<<"Please enter a Matrix (a) which you will multiply by Matrix(b):"<<endl;
    cin>>a;
    cout<<a<<"\n";
    cout<<"Please enter a Matrix (b) which you will multiply by Matrix(a)"<<endl;
    cout<<"*remember the rules of multiplying matrices:"<<endl;

    cin>>b;
    cout<<b<<"\n";

    cout<<"The product of the two matrices are Matrix(c):"<<endl;
    c = a * b;
    cout<<c<<endl;


    cout<<"The sum of the Matrix(a) and Matrix(c):"<<endl;
    cout<<b+c<<endl;

    cout<<"The product of 5 and Matrix(b) is the new Matrix(d): "<<endl;
    Matrix<int> d(5*b);
    cout<<d<<endl;


    cout<<"Matrix(d) += Matrix(c) : "<<endl;

    d+=c;
    cout<<d<<endl;
    cout<<endl;

    cout<<endl;


    cout<< "a[0][0]:"<<endl;
    cout<< a[0][0]<<endl;

    cout<< "a[1][2]:"<<endl;
    cout<< a[1][2]<<endl;
    d = a+b;
}
