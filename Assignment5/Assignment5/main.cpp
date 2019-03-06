//
//  main.cpp
//  Assignment5
//
//  Created by Karan Mukhi on 25/02/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//  Program defining the class of complex numbers
//  and main function demonstraiting the class

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// Complex Class
class complex {
    //Includes member variables, basic operations on complex numbers and iostream
    //Friend stream functions
    friend ostream & operator<<(ostream &os, const complex &z);
    friend istream & operator>>(istream &is, complex &z);
    
private:
    //
    double Re, Im;
    
public:
    //Default constructor
    complex(){Re = 0; Im = 0;}
    //Constuctor
    complex(double r, double i){Re = r; Im = i;}
    //Destroyer
    ~complex(){}
    
    //Member Functions
    double getReal() const {return Re;}
    double getImag() const {return Im;}
    double getArg() const {return fmod(atan(Im/Re),atan(1)*4);}
    complex getCon() const {return complex(Re, -Im);}
    double getMod() const {
        double mod;
        mod = pow(Re,2) + pow(Im,2);
        mod = sqrt(mod);
        return mod;
    }
    void setReal(double r){Re = r;}
    void setIm(double i){Im = i;}
    //Overloading Operators
    complex operator+(const complex &c) const;
    complex operator-(const complex &c) const;
    complex operator*(const complex &c) const;
    complex operator/(const complex &c) const;

};
//Stream overloaded operators
ostream & operator<<(ostream &os, const complex &z){
    char sign;
    if (z.Im<0){sign = '-';}
    else sign = '+';
    os << z.Re << " " << sign << " i" << abs(z.Im);
    return os;
};

istream & operator>>(istream &is, complex &z){
    string str, r, i, s;
    double re, im;
    getline(cin,str);
    size_t space = str.find(" i");
    r = str.substr(0,space-1);
    s = str.substr(space-1,1);
    i = str.substr(space+2);
    re = stod(r);
    im = stod(i);
    if (s=="-"){im = -im;}
    z.setIm(im);
    z.setReal(re);
    return is;
};

//Overloaded operator function defininitions 
complex complex::operator+(const complex &c) const{
    return complex(Re + c.getReal(),Im + c.getImag());
    
}

complex complex::operator-(const complex &c) const{
    return complex(Re - c.getReal(),Im - c.getImag());
    
}

complex complex::operator*(const complex &c) const{
    double real = Re*c.getReal() - Im*c.getImag();
    double imag = Im*c.getReal() + Re*c.getImag();
    return complex(real, imag);
}

complex complex::operator/(const complex &c) const{
    double real = Re*c.getReal() + Im*c.getImag();
    double imag = Im*c.getReal() - Re*c.getImag();
    real = real/c.getMod();
    imag = imag/c.getMod();
    return complex(real, imag);
}

//Main function demostrating the complex class
int main() {
    complex z(1,-2);
    complex a;
    cout << "Please enter a complex number: \n";
    cin >> a;
    cout << a;
    cout << "\nModulus: " << a.getMod() << "\nArgument: " << a.getArg();
    cout << "\nComplex conjugate: " << a.getCon();
    cout <<"\n(" << a << ")*(" << z<<") = "  << a*z;
    cout <<"\n(" << a << ")/(" << z <<") = " << a/z << "\n";
    
    
    return 0;
}
