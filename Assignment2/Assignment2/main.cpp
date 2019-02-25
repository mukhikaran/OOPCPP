//
//  main.cpp
//  Assignment2
//
//  Created by Karan Mukhi on 06/02/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

//Mean function
double mean(double* data, int n){
    double mean(0);
    for (int i(0); i < n; i++){
        mean += data[i];
        
    }
    return (mean/n);
}

//SD function
double sd(double* data, int n){
    double m(mean(data, n));
    double sum(0);
    for (int i(0); i<n;i++){
        sum += pow((data[i] - m),2);
    }
    sum = sum/(n-1);
    sum = pow(sum,0.5);
    
    return sum;
}

//Standard error in mean
double error(double* data, int n){
    double std(sd(data,n));
    std = std/pow(n,0.5);
    return std;
}

int main() {
    
    cout << "This program calculates the mean and standard deviation of a data file. \n\n";
    // Read in file
    cout << "Please enter the file name: \n";
    string filename;
    getline(cin,filename);
    fstream myfile;
    filename = "/Users/karanmukhi/Desktop/oop/Assignment2/millikan.dat.txt";
    myfile.open(filename);
    cout << "Opening: "<<filename<<"\n";
    // Check file read correctly
    if(!myfile.good()){
        cerr<< "Error: File could not be opened\n";
        return 1;
    }
    //Find number of lines in data
    int n(0);
    double test(0);
    while(!myfile.eof()){
        myfile>>test;
        n++;
        if(myfile.fail()){
            myfile.clear();
            myfile.ignore(200,'\n');
            cout<<"Error reading line: " << n<<endl;
            n-=1;
        }
    
    }
    cout << "Number of lines read: " << n <<'\n';

    myfile.close();
    myfile.open(filename);
    // Create array for data
    double* data = new double[n];
    //cout << "Size of data" <<  (sizeof(data)/sizeof(*data)) <<" " << n<< '\n';
    for (int i(0); i<n; i++){
        myfile>>data[i];
        if(myfile.fail()){
            myfile.clear();
            myfile.ignore(200,'\n');
            i-=1;
        }
    }
    //Calculate statistical variables
    double M(mean(data,n));
    double SD(sd(data,n));
    double SEM(error(data,n));
    delete[] data;
    //Print
    cout <<endl <<"The average is: " << M << " +/- " << SD << endl << "The standard error in mean is: " << SEM << endl;
    return 0;
}
