//Check type
bool checkType(string gType);
//Check mass
bool checkMass(double gMass);
//Check Mass fraction
bool checkFract(double gFract);


bool Galaxy::checkMass(double gMass){
    if ( gMass > 10e7 && gMass < 10e12){
        return true;
    }
    else return false;
}

bool Galaxy::checkRedshift(double gshift){
    if ( gshift > 0 && gshift  < 10){
        return true;
    }
    else return false;
};

bool Galaxy::checkMass(double gMass){
    if ( gMass > 10e7 && gMass < 10e12){
        return true;
    }
    else return false;
};
