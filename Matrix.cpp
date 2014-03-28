#include "Matrix.h"
template<class Obj>
Matrix<Obj>::Matrix()
{
    rows = 0;
    cols = 0;
    mArray = new Obj*[0];
    mArray[0] = new Obj[0];
    mArray[0][0] = 0;
}

template<class Obj>
Matrix<Obj>::Matrix(int rowIn, int colIn)
{

    ///set a rowxcol matrix with 0's//null gave warnings although I believe they are same
    rows = rowIn;
    cols = colIn;
    mArray = new Obj*[rows];
    for(int i = 0; i<rows; i++)mArray[i] = new Obj[cols];

    for (int i = 0; i<rows; i++)
        for(int j = 0; j<cols; j++)
            mArray[i][j] = 0;

}



template<class Obj>
Matrix<Obj>::Matrix(const Matrix<Obj> &rhs)
{
    rows = rhs.rows;
    cols = rhs.cols;

    mArray = new Obj*[rows];
    for(int i = 0; i<rows; i++) mArray[i]  = new Obj[cols];

    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<rows; j++)
        {
            mArray[i][j] = rhs.mArray[i][j];
        }
    }
}


template<class Obj>
const Matrix<Obj>&
Matrix<Obj>:: operator =(const Matrix<Obj>& rhs)
{
    if (this == &rhs)return *this;

    clearArrayMemory();
    cols = rhs.cols;
    rows = rhs.rows;
    mSize = rhs.mSize;
    //  Obj tempArray[rows][cols];
    mArray = new Obj*[rows];
    for(int i = 0; i<rows; i++) mArray[i]  = new Obj[cols];

    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            mArray[i][j]= rhs.mArray[i][j];
        }
    }
    return *this;
}



template<class Obj>
Matrix<Obj>&
Matrix<Obj>:: operator +=(const Matrix<Obj>& rhs)
{
    if (rhs.rows != rows||rhs.cols!=cols) throw "invalid operation";

    for(int i = 0; i<rows; i++)
        for(int j = 0; j<cols; j++)
            mArray[i][j]+=rhs.mArray[i][j];
    return *this;
}


template<class Obj>
Matrix<Obj>
Matrix<Obj>:: operator +(const Matrix<Obj>& rhs)
{
    if (rhs.rows != rows||rhs.cols!=cols) throw "invalid operation";
    Matrix tempMatrix = *this;
    tempMatrix += rhs;
    return tempMatrix;
}


template<class Obj>
void
Matrix<Obj>::convertStringToChar()
{
//warning here for comparing an int with userInput.size()
    convertedInput = new char[userInput.size()];
    for (int i = 0; i<userInput.size(); i++)
    {
        convertedInput[i] = userInput[i];
    }

    recastConvertedInput();
}

template<class Obj>
void
Matrix<Obj>:: recastConvertedInput()
{
    char*pch;
    int nums;
    sizeOfNewArray = 0;
    int tokenizedString[userInput.size()];

    pch = strtok(convertedInput," ,./][");

    while(pch!=NULL)
    {
        nums = atoi(pch);
        pch = strtok(NULL," ,.][");
        tokenizedString[sizeOfNewArray] = nums;
        sizeOfNewArray++;
    }
    // Obj resizedTokens[sizeOfNewArray];
    recastInput = new Obj[sizeOfNewArray];

    for (int i = 0; i<sizeOfNewArray; i++)
    {
        recastInput[i] = static_cast<Obj>(tokenizedString[i]);
        //std::cout<<"size of the new array ="<<sizeOfNewArray<<"\n";

    }
    delete []convertedInput;

    setMatrixArray();
}

template<class Obj>
void
Matrix<Obj>::setMatrixArray()
{

    delete[]mArray;
    rows = recastInput[0];
    cols = recastInput[1];
    Obj tempArray[sizeOfNewArray-2];
//set a new sized temporary array to insert into the new matrix
    for(int i = 2; i<sizeOfNewArray; i++)tempArray[i-2] = recastInput[i];
    delete[]recastInput;
    mArray = new Obj*[rows];
    for (int i = 0; i<rows; i++)mArray[i] = new Obj[cols];
    int h = 0;
    while(h<sizeOfNewArray-2)
    {
        for (int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                if (h == sizeOfNewArray-2)break;

                mArray[i][j] = tempArray[h];
                h++;
            }
        }
    }

}


template<class Obj>
int
Matrix<Obj>::numrows()
{
    return rows;
}


template<class Obj>
int
Matrix<Obj>::numcols()
{
    return cols;
}


template<class Obj>
void
Matrix<Obj>::clearArrayMemory()
{

    for(int i = 0; i<rows; i++)
    {
        for (int j = 0; j<cols; j++)
        {
            mArray[i][j]=0;
        }
        delete mArray[i];
    }
    delete []mArray;

}


template<class Obj>
Matrix<Obj>::~Matrix()
{

    for(int i = 0; i<rows; i++)
    {
        delete []mArray[i];
    }
    delete []mArray;
}
