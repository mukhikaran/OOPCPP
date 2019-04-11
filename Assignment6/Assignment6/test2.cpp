//
//  main.cpp
//  Assignment6
//
//  Created by Karan Mukhi on 06/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//  Definition of a matrix class with overloaded functions
//  and main function to demostrate capabilities

#include <iostream>
using namespace std;

class matrix
{
    //Friends
    friend ostream & operator<<(ostream &os, const matrix &mat);
    friend istream & operator>>(istream &is, matrix &mat);
private:
    double *mdata;
    int rows, columns;

public:
    
    //Default constructor
    matrix(){mdata = 0; rows = columns = 0;}
    //Parameterised constructor
    matrix(int row, int col){rows = row; columns = col; mdata = new double[row*col];}
    //Copy Constructor
    matrix(matrix &mat);
    //Destructor
    ~matrix(){delete mdata;}
    //Copy constructor
    
    
    
    //Access functions
    int getRows() const {return rows;}
    int getCols() const {return columns;}
    int getIndex(int row, int col) const;
    void setRows(int r) {rows = r; delete mdata; mdata = new double[rows*columns];}
    void setCols(int c) {columns = c; delete mdata; mdata = new double[rows*columns];}
    
    matrix minor(int row, int col);
    //Overloaded operators
    double & operator()(int i, int j);
    double & operator()(int i, int j) const;
    matrix & operator=(matrix &mat);
    //matrix & operator=(matrix &&mat);
    matrix operator+(matrix &mat);
    matrix operator-(const matrix &mat);
    matrix operator*(const matrix &mat);
};

//Function Definitions

//Copy constructor
matrix::matrix(matrix & mat){
    mdata = 0; rows = mat.getRows(); columns = mat.getCols();
    if(rows>0 && columns>0){
        mdata = new double[rows*columns];
        for(int i=1; i<=rows;i++){
            for(int j=1; j<=columns; j++){
                mdata[getIndex(i,j)] = mat(i,j);
            }
        }
    }
}
//Assignment Operator
matrix & matrix::operator=(matrix &mat){
    if(&mat == this) return *this;
    delete mdata;
    rows = mat.getRows(); columns = mat.getCols();
    if(rows>0 && columns>0){
        mdata = new double[rows*columns];
        for(int i = 1; i<=rows; i++){
            for(int j = 1; j<=columns; j++){
                mdata[getIndex(i,j)] = mat(i,j);
            }
        }
    }
    return *this;
}
//Move Operator
/*matrix & matrix::operator=(matrix &&mat){
 rows = mat.getRows(); columns = mat.getCols();
 mdata = mat.mdata;
 mat.setCols(0); mat.setRows(0);
 mat.mdata = NULL;
 return *this;
 }
*/
//Element value
double & matrix::operator()(int i, int j) {
    if(getIndex(i,j)>=0){
        return mdata[getIndex(i,j)];
    }
    cout << "Invalid matrix index.\n";
    exit(1);
}

//Friend Functions:
ostream & operator<<(ostream &os, matrix &mat){
    cout << endl;
    for(int i = 1; i<=mat.getRows(); i++){
        for(int j = 1; j<=mat.getCols(); j++){
            cout << mat(i,j) << " ";
        }
        cout << endl;
    }
    cout << "\n\n";
    return os;
}

istream & operator>>(istream &is,  matrix &mat){
    int a;
    cout << "Enter number of rows:\n";
    cin >> a;
    mat.setRows(a);
    cout << "Enter number of columns:\n";
    cin >> a;
    mat.setCols(a);
    for(int i = 1; i<=mat.getRows();i++){
        for(int j = 1; j<=mat.getCols();j++){
            cout << "Please enter the (" << i << "," << j << ") element:\n";
            cin >> mat(i,j);
        }
    }
    return is;
}

//Get Index
int matrix::getIndex(int row, int col) const{
    if (row > 0 && row <= rows && col > 0 && col<=columns){
        return (col-1) + (row-1)*columns;
    }
    return -1;
}
//Matrix of minors
matrix matrix::minor(int row, int col){
    matrix result(rows-1,columns-1);
    int k(0),l(0);
    for(int i=1; i<=result.rows;i++){
        for(int j=1; j<=result.columns; j++){
            k = i; l = j;
            if(i>=row) k++;
            if(j>=col) l++;
            result(i,j) = mdata[getIndex(k,l)];
        }
    }
    return result;
}
//Overloaded operators
//Addition
matrix matrix::operator+(matrix &mat) {
    matrix result(rows, columns);
    if (rows != mat.getRows() || columns != mat.getCols()){exit(9);}
    for(int i=1; i<=rows;i++){
        for(int j=1; j<=columns; j++){
            result(i,j) = (*this)(i,j) + mat(i,j);
            //cout << result;
        }
    }
    cout << result;
    return result;
}
//Subtraction

//Multiplication
/*matrix matrix::operator*(const matrix &mat) const {
    matrix result(rows,mat.getCols());
    if (columns == mat.getRows()){
        double res(0);
        for(int i=1; i<=rows;i++){
            for(int j=1; j<=columns; j++){
                for(int k=1; k<=columns; k++){
                    res += mdata[getIndex(i,k)] * mat(k,j);
                }
                result(i,j) = res;
                res = 0;
            }
        }
    }
    return result;
}*/
int main() {
    // insert code here...
    
    matrix b, a, c;
    cin >> b;
    c = b;
    a = b + c;
    cout << a;

    return 0;
}

