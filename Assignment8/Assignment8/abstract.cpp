//
//  main.cpp
//  Assignment8
//
//  Created by Karan Mukhi on 24/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//  Contains:
//              -Abstract Shape Class with pure virtual functions, info, area, volume
//              -Derived 2D Class and definition of four derived classes: Square, Rectangle, Circle, Ellipse
//              -Derived 3D Class and definition of four derived classes: Cube, Cuboid, Sphere, Ellipsoid
//
//  Member functions return the area and volume of the shapes and an info function that returns information about the shape

#include <iostream>
#include <cmath>
using namespace std;

const double pi(3.1415926);

class shape{
public:
    virtual ~shape(){};
    virtual void info() const =0;
    virtual double area() const =0;
    virtual double volume() const =0;
};

//Base class for 2D shapes
class twoD: public shape
{
public:
    void info() const {cout << "Area: " << this->area() << endl;} //Define virtual info funtion for 2D shapes
};

//Base class for 3D shapes
class threeD: public shape
{
public:
    void info() const {cout << "Area: " << this->area() << ", Volume: " << this -> volume() << endl;} //Define virtual infor funtion for 3D shapes
};

//Square Class
class square: public twoD
{
private:
    double length;
public:
    square(){ length = 0;}
    square(double len){length = 0;}
    double area() const {return length * length;}
    double volume() const{return 0;}
};

//Rectangle Class
class rectangle: public twoD
{
private:
    double length;
    double width;
public:
    rectangle(){length=0;width=0;}
    rectangle(double len, double wid): length(len), width(wid) {}
    double area() const {return length*width;}
    double volume() const {return 0;}
};

//Circle Class
class circle: public twoD
{
private:
    double radius;
public:
    circle(){radius=0;}
    circle(double rad) : radius(rad) {}
    double area() const {return pi*radius * radius;}
    double volume() const{return 0;}
};
//Ellipse Class
class ellipse: public twoD
{
private:
    double majorAxis;
    double minorAxis;
public:
    ellipse(){majorAxis=0;minorAxis=0;}
    ellipse(double maj, double min): majorAxis(maj), minorAxis(min) {}
    double area() const {return pi*majorAxis*minorAxis;}
    double volume() const {return 0;}
};


//3D Class Definitions
//Cube
class cube: public threeD
{
private:
    double length;
public:
    cube(): length(0) {}
    cube(double l): length(l) {}
    double area() const {return 6*length*length;}
    double volume() const {return length*length*length;}
};
//Cuboid
class cuboid: public threeD
{
private:
    double height;
    double length;
    double width;
public:
    cuboid(): height(0), length(0), width(0) {}
    cuboid(double h, double l, double w): height(h), length(l), width(w) {}
    double area() const {return 2*(height*length + length*width + width*height);}
    double volume() const {return height*length*width;}
};

//Sphere
class sphere: public threeD
{
private:
    double radius;
public:
    sphere(): radius(0) {}
    sphere(double r): radius(r) {}
    double area() const {return 4*pi*radius*radius;}
    double volume() const {return 4*pi*radius*radius*radius/3;}
};

//Ellipsoid
class ellipsoid: public threeD
{
private:
    double a;
    double b;
    double c;
public:
    ellipsoid(): a(0), b(0), c(0) {}
    ellipsoid(double h, double l, double w): a(h), b(l), c(w) {}
    double area() const {
        double p(1.61);
        double sum((pow(a,p)*pow(b,p)+pow(a,p)*pow(c,p)+pow(b,p)*pow(c,p))/3);
        return 4*pi*pow(sum,1/p);}
    double volume() const {return 4*a*b*c*pi/3;}
};

//Prism
class prism: public threeD
{
private:
    double height;
    shape *crossSection;
public:
    prism(): height(0), crossSection(NULL) {}
    prism(double h, shape &cross): height(h), crossSection(&cross) {}
    double area() const {return 0;}
    double volume() const {return crossSection->area()*height;}
};


