
//
//  main.cpp
//  Assignment7
//
//  Created by Karan Mukhi on 15/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//  Code implementing a class for cartesian vectors of arbitary length
//  Implementation of a class for 4-vectors that inherits attributes from the cVector class
//  Main demostrates the features of both classes

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

//Cartesian Vector class
class cVector
{
    //Friends
    friend ostream & operator<<(ostream &os, const cVector &vect);
    friend istream & operator>>(istream &is, cVector &vect);
    
protected:
    double *vdata;
    int dim;
    
public:
    
    //Default constructor
    cVector(){vdata = NULL; dim = 0;}
    //Parameterised Constructor
    cVector(int d){dim = d; vdata = new double[dim];}
    //Copy constructor
    cVector(cVector &vect);
    //Move copy
    cVector(cVector &&vect);
    //Destructor
    ~cVector(){delete[] vdata;}
    
    //Access functions
    double getDim() const {return dim;}
    void setDim(int n){dim = n; delete vdata; vdata = new double[n];}
    
    //Operations
    double dot(cVector const &vect) const;
    double gamma() const;
    //Overloaded operators
    double & operator()(int i);
    double & operator()(int i) const;
    cVector & operator=(cVector &vect);
    cVector & operator=(cVector &&vect);
};
//Four vector class definition
class mVector: public cVector {
    
    //Friends
    friend ostream & operator<<(ostream &os, const mVector &vect);
    friend istream & operator>>(istream &is, mVector &vect);
    
public:
    //Parameterised constructor
    mVector(){dim = 4; vdata = new double[4];}
    mVector(double t, double x, double y, double z);
    mVector(double t, cVector &vect);
    mVector(mVector & vect);
    mVector(mVector && vect);
    mVector & operator=(mVector &vect);
    mVector & operator=(mVector &&vect);
    
    //Operations
    double dot(mVector & vect) const;
    double & operator()(int i);
    double & operator()(int i) const;
    void boost(cVector & beta);
    cVector pos();
    
    
};

//Particle Class Definition
class particle {
    
private:
    mVector position;
    cVector beta;
    double mass;
    
public:
    //Parameterised constructor
    particle(mVector & r, double & m, cVector &b){position = r; mass = m; beta = b;}
    
    //Member functions
    double gamma() const;
    double energy() const;
    cVector momentum() const;
};
//cVector Class Functions
//Stream Operators
ostream &operator<<(ostream &os, cVector &vect){
    if(vect.getDim() == 0){cout << "Empty Vector\n";}
    for(int i = 1; i <= vect.getDim(); i++){
        if(i==1){cout << "(";}
        if(i!= vect.getDim()){cout << vect(i) <<",";}
        else {cout << vect(i) <<")\n";}
    }
    return os;
}
istream &operator>>(istream &is, cVector &vect){
    int n;
    cout << "Enter number of dimensions of vector:\n";
    cin >> n;
    vect.setDim(n);
    for(int i = 1; i<=vect.getDim(); i ++){
        cout << "Please enter element " << i << ":\n";
        cin >> vect(i);
    }
    return is;
}

//Copy constructor
cVector::cVector(cVector &vect){
    vdata = 0; dim = vect.getDim();
    if(dim>0){
        vdata = new double[dim];
        for(int i = 0; i < dim; i++){
            vdata[i] = vect(i+1);
        }
    }
}
//Move copy
cVector::cVector(cVector &&vect){
    swap(dim, vect.dim);
    swap(vdata, vect.vdata);
}
//Assignment operator
cVector & cVector::operator=(cVector &vect){
    if(&vect == this){return *this;}
    delete vdata;
    dim = vect.getDim();
    vdata = new double[dim];
    if(dim > 0){
        for(int i = 1; i <= dim; i++){
            vdata[i-1] = vect(i);
        }
    }
    return *this;
}
//Move operator
cVector & cVector::operator=(cVector &&vect){
    swap(dim, vect.dim);
    swap(vdata, vect.vdata);
    return *this;
}
//Element value
double & cVector::operator()(int i){
    if(i <= dim){
        return vdata[i-1];
    }
    cout << "This vector empty\n";
    exit(9);
}

double & cVector::operator()(int i) const {
    if(i <= dim){
        return vdata[i-1];
    }
    cout << "This vector is empty\n";
    exit(9);
}
//DotProduct
double cVector::dot(cVector const &vect) const{
    if (dim != vect.getDim()){
        cout << "Cannot dot vectors of different length\n";
    }
    double result(0);
    for(int i = 1; i <= dim; i++){
        result += (*this)(i) * vect(i);
    }
    return result;
}

//mVector functions
ostream &operator<<(ostream &os, mVector &vect){
    for(int i = 0; i < vect.getDim(); i++){
        if(i==0){cout << "(";}
        if(i < vect.getDim()-1){cout << vect(i) <<",";}
        else {cout << vect(i) << ")\n";}
    }
    return os;
}
istream &operator>>(istream &is, mVector &vect){
    vect.setDim(4);
    char coord('n');
    for(int i = 0; i< vect.getDim(); i++){
        if(i == 0){coord = 't';}
        if(i == 1){coord = 'x';}
        if(i == 2){coord = 'y';}
        if(i == 3){coord = 'z';}
        cout << "Please enter " << coord << " coordinate:\n";
        cin >> vect(i);
    }
    return is;
}

//Parameterised constructors
mVector::mVector(double t, double x, double y, double z){
    (*this).setDim(4);
    (*this)(0) = t;
    (*this)(1) = x;
    (*this)(2) = y;
    (*this)(3) = z;
}

mVector::mVector(double t, cVector &vect){
    (*this).setDim(4);
    (*this)(0) = t;
    (*this)(1) = vect(1);
    (*this)(2) = vect(2);
    (*this)(3) = vect(3);
}

//Copy constructor
mVector::mVector(mVector &vect){
    this->setDim(4);
    for(int i = 0; i < dim; i++){
        vdata[i] = vect(i);
    }
}
//Move copy
mVector::mVector(mVector &&vect){
    swap(dim, vect.dim);
    swap(vdata, vect.vdata);
    vect.setDim(0);
}

//Copy assignment constructor
mVector & mVector::operator=(mVector &vect){
    if(&vect == this){return *this;}
    this->setDim(4);
    for(int i = 0; i < 3; i++){
        vdata[i] = vect(i);
    }
    return *this;
}
//Move operator
mVector & mVector::operator=(mVector &&vect){
    swap(dim, vect.dim);
    swap(vdata, vect.vdata);
    vect.setDim(0);
    return *this;
}

double & mVector::operator()(int i){
    if(i <= 3){
        return vdata[i];
    }
    cout << "Invalid index. Valid indexes: t = 0, x = 1, y = 2, z = 3\n";
    exit(9);
}

double & mVector::operator()(int i) const{
    if(i <= 3){
        return vdata[i];
    }
    cout << "Invalid index. Valid indexes: t = 0, x = 1, y = 2, z = 3\n";
    exit(9);
}

double mVector::dot(mVector &vect) const{
    double result(0);
    for(int i = 0; i < dim; i++){
        if (i==0){result += (*this)(i) * vect(i);}
        else {result -= (*this)(i) * vect(i);}
    }
    return result;
}

//Lorentz boost
void mVector::boost(cVector & beta){
    if(beta.getDim()!= 3) {cout << "Beta vector must be 3D\n"; exit(9);}
    cVector r(this->pos());
    for (int i = 1; i <= 3; i++){
        (*this)(i) = (*this)(i) + ((beta.gamma() - 1.0) * r.dot(beta)/beta.dot(beta) - beta.gamma() * (*this)(0))*beta(i);
    }
    (*this)(0) = beta.gamma()*((*this)(0) - beta.dot(r));
}

cVector mVector::pos(){
    cVector r(3);
    r(1) = (*this)(1);
    r(2) = (*this)(2);
    r(3) = (*this)(3);
    return r;
}

double cVector::gamma() const {
    if(dim != 3) {cout << "Beta vector must be 3D\n"; exit(9);}
    double result;
    result = sqrt(1 - (*this).dot(*this));
    return 1/result;
}

//Particle Class member function definitions
double particle::gamma() const {
    return beta.gamma();
}
double particle::energy() const {
    double result;
    result = this->gamma() * mass;
    return result;
}
cVector particle::momentum() const {
    cVector result(3);
    for (int i = 1; i<=3; i++){
        result(i) = beta(i) * this->gamma() * mass;
    }
    return result;
}

void cdemo(){
    cout << "Demonstrate Cartesian Vector Class\n\n";
    cVector a, b;
    cout << "Enter a cartesian vector 'a'\n";
    cin >> a;
    cVector c(a);
    cout << "You entered: " << c << endl;
    cout << "Enter another cartesian vector 'b'\n";
    cin >> b;
    c = b;
    cout << "You entered: " << b;
    cout << "a.b: " << a.dot(b) << endl;
    cout << "First element of a is " << a(1) << endl;
    cVector d(move(a));
    cout << a << endl;
    cout << d << endl;
    cVector e = move(c);
    cout << c << endl << e;
    cout <<"\n\n\n";
}

void mdemo(){
    cout << "Demonstrate Minkowski Vector Class\n\n";
    mVector a(0.1,2,3,4),c(a),d = a;
    cout << "4-Vector (a): " << a << "and a copy: " << c << "and an assignment: " << d << endl;
    cVector beta;
    cout << "Enter a 3 vector, used for parameterised contruction (b) and boost:\n";
    cin >> beta;
    mVector b(5,beta);
    cout << b << endl;
    a.boost(beta);
    cout << "a boosted by beta: " << a <<endl;
    cout << "a.b: " << a.dot(b) << endl;
    cout << "\n\n\n";
}

void pdemo(){
    cout << "Demonstrate Partilce Class\n\n";
     mVector r(1,2,3,4);
     cVector b, momentum;
     double m;
     cout << "Enter a boost vector:\n";
     cin >> b;
     cout << "Enter a mass:\n";
     cin >> m;
     particle p(r,m,b);
     cout << "Gamma: "<< p.gamma()<<endl;
     cout << "Energy: " << p.energy() << endl;
     momentum = p.momentum();
     cout << "Momentum: " << momentum << endl;
    
}

int main(){
    string a[3] = {"111", "000", "111"};
    string b = a[1];
    char c[3];
    if(b[2]) cout << "true";
    else cout << "unture;";
    return 0;
}

