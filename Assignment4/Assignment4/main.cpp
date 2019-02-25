//
//  main.cpp
//  Assignment4
//
//  Created by Karan Mukhi on 20/02/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Galaxy
{
private:
    string name, hubbleType;
    double redshift, totalMass, stellarMassFraction;
    vector<Galaxy> satellites;

public:
    //Default Constructor
    Galaxy():
    name{"Unknown"},
    hubbleType{"Unspecified"},
    redshift{0},
    totalMass{0},
    stellarMassFraction{0}
    {}
    
    //Constructor
    Galaxy(string name, string gType, double gShift, double gMass, double gFract):
    name{name},
    redshift{checkRedshift(gShift)},
    totalMass{checkMass(gMass)},
    stellarMassFraction{checkFract(gFract)},
    hubbleType{checkType(gType)}
    {}
    //Destructor
    ~Galaxy() {}
    //Stellar mass
    double stellarMass(){return stellarMassFraction*totalMass;}
    //Change galaxy's Hubble type
    void changeType(string newType){hubbleType = checkType(newType);}
    //Add Satellite
    void addSat(Galaxy g){satellites.push_back(g);}
    //Print
    void printData();
    //Print vector
    void printVect();
    //Check valid inputs;
    string checkType(string gType);
    double checkMass(double gMass);
    double checkRedshift(double gShift);
    double checkFract(double gFract);
};

void Galaxy::printData(){
    cout << name<<"\n"<<"Galaxy Type: " << hubbleType << "\nRedshift: " << redshift
    << "\nTotal Mass " << totalMass << "\nStellar Mass Fraction: " << stellarMassFraction << "\nStellar Mass: " << stellarMass()
    << "\nNumber of Satellites: " << satellites.size() << "\n";
    if (satellites.size()){
        cout << "\n\nSatellites of " << name <<": \n\n";
        printVect();
    }
    cout << "\n\n";
    
}

string Galaxy::checkType(string gType){
    while(!(
          gType == "E0"
       || gType == "E1"
       || gType == "E2"
       || gType == "E3"
       || gType == "E4"
       || gType == "E5"
       || gType == "E6"
       || gType == "E7"
       || gType == "S0"
       || gType == "Sa"
       || gType == "Sb"
       || gType == "Sc"
       || gType == "SBa"
       || gType == "SBb"
       || gType == "SBc"
       || gType == "Irr"
       )){
        cout << "Please enter a valid type for " << name<< ": \n";
        cin >> gType;
    }
    return gType;
}

double Galaxy::checkMass(double gMass){
    while(!( gMass > 10e7 && gMass < 10e12)){
        cout << "Please enter a valid mass for " << name << ": \n";
        cin >> gMass;
    }
    return gMass;
}

double Galaxy::checkRedshift(double gShift){
    while(!( gShift > 0 && gShift  < 10)){
        cout << "Please enter a valid redshift for " << name << ": \n";
        cin >> gShift;
    }
    return gShift;
}

double Galaxy::checkFract(double gFract){
    while(!( gFract > 0 && gFract  < 0.05)){
        cout << "Please enter a valid mass fraction for " << name << ": \n";
        cin >> gFract;
    }
    return gFract;
}
void Galaxy::printVect(){
    vector<Galaxy>::iterator start{satellites.begin()}, end{satellites.end()}, current;
    for( current = start; current < end; current++){
        current->printData();
    }
}

int main() {
    Galaxy MilkyWay("Milky Way", "S10", 7,10,0.09);
    Galaxy M83("M83", "Irr", 1,10e9,0.03);
    Galaxy MC("Midnight City", "E0", 4,10e9,0.03);
    vector<Galaxy> vect;
    vect.push_back(MilkyWay);
    vect.push_back(M83);
    vect.push_back(MC);
    vector<Galaxy>::iterator start{vect.begin()}, end{vect.end()}, current;
    for(current = start; current < end; current++){
        current->printData();
    }
    MilkyWay.changeType("E7");
    MilkyWay.addSat(M83);
    MilkyWay.addSat(MC);
    MilkyWay.printData();
    return 0;
}


