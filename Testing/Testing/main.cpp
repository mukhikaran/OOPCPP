//
//  main.cpp
//  Testing
//
//  Created by Karan Mukhi on 29/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include <iostream>
using namespace std;
bool movement(bool straight, bool diag, bool dist, int iRow, int iCol, int fRow, int fCol) {
    bool straightMove, diagMove;
    bool result(true);
    
    if(fRow==iRow||fCol==iCol) straightMove = true;
    else straightMove = false;
    straightMove *= straight;
    if(abs(fRow-iRow)==abs(fCol-iCol)) diagMove = true;
    else diagMove = false;
    diagMove *= diag;
    if(straightMove|| diagMove) result = true;
    else result = false;
    if(!dist){
        if(abs(fRow-iRow)<=1 && abs(fCol-iCol)<=1) result *= true;
        else result *= false;
    }
    return result;
}

int main() {
    bool straight = false;
    bool diag = true;
    bool dist = false;
    int iRow = 1;
    int fRow = 1
    ;
    int iCol = 1;
    int fCol = 3;
    cout << movement(straight, diag, dist, iRow, iCol, fRow, fCol);
    
    return 0;
}
