#ifndef MATRIX_H
#define MATRIX_H
#include<string.h>
#include<iostream>
#include<cstdlib>
using namespace std;

template<class Obj>

class Matrix
{
public:
    int a, b;
    /*big three for the Matrix class + an overload constr*/
    Matrix();
    Matrix (int rowIn, int colIn);
    Matrix(const Matrix<Obj> &rhs);
    const Matrix<Obj>& operator = (const Matrix<Obj>& rhs);


    //Mathematical operator & friends


    //gets matrix indices
    const Obj*  operator[](int indx) const
    {
        return mArray[indx];
    }


    //throw an error if sizes dont match
    //go through the array and add corresponding rhs indices to this
    //return this
    Matrix &  operator +=(const Matrix<Obj>& rhs);


    //takes the rhs
    //gets it into the +=op
    //sets it to a tempMatrix
    //returns the tempMatrix
    Matrix    operator + (const Matrix<Obj>& rhs);
    friend Matrix operator *(int num,const Matrix & rhs)
    {
        Matrix tempMatrix(rhs);
        for(int i = 0; i<tempMatrix.rows; i++)
            for(int j = 0; j<tempMatrix.rows; j++)
                tempMatrix.mArray[i][j] = num * rhs.mArray[i][j];
        return tempMatrix;
    }


    //if the cols on left dont match the rows on right ->error
    //set the constructors 2 arguments for the dimensiond of the final matrix
    //multiplly the matrices
    //return a temp matrix that is the product of the 2 matrices
    friend Matrix operator *(const Matrix & lhs,const Matrix & rhs)
    {
        if (lhs.cols!=rhs.rows)throw "Error";
        Matrix tempMatrix(lhs.rows,rhs.cols
                         );

        for(int i = 0; i<lhs.rows; i++)
            for (int j = 0; j<lhs.cols; j++)
                for (int k = 0; k<rhs.rows; k++)
                    tempMatrix.mArray[i][j] += lhs.mArray[i][k]*rhs.mArray[k][j];
        return tempMatrix;
    }




    //stream overloads
    friend std::ostream& operator <<(std::ostream& out, const Matrix & m)
    {
        //loop through and output.

        for(int i = 0; i<m.rows; i++)
        {
            for(int j = 0; j<m.cols; j++)
            {
                out<<m.mArray[i][j]<<" ";
            }
            out<<"\n";
        }

        return out;
    }

    friend std::istream& operator >>(std::istream& is,  Matrix & m)
    {
        std::getline(std::cin, m.userInput);
        m.convertStringToChar();
        return is;
    }

    int numrows();
    int numcols();


    virtual ~Matrix();

private:
    Obj **mArray;
    int rows, cols;
    int mSize;
    int sizeOfNewArray;
    std::string userInput;
    char * convertedInput;
    Obj * recastInput;

    ///private functions just to do the prep work for the matrix(s)//
    //next time this will be it's own class
    //I am sorry I do that this time
    void convertStringToChar();//converts the input string to a char array
    void recastConvertedInput();//casts the chars to  Obj
    void clearArrayMemory();//sets the mArray to 0 & deletes it for safety
    void setMatrixArray();//sets the actual matrix



};

#endif // MATRIX_H
