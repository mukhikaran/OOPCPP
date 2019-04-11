//
//  pieces.cpp
//  Chess
//
//  Created by Karan Mukhi on 29/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include "pieces.h"

bool linePiece::movement(int iRow, int iCol, int fRow, int fCol) const{
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

bool knight::movement(int iRow, int iCol, int fRow, int fCol) const{
    if (abs(iRow - fRow) == 2 && abs(iCol-fCol) == 1) return true;
    if (abs(iRow - fRow) == 1 && abs(iCol-fCol) == 2) return true;
    else return false;
}

/*bool pawn::movement(int iRow, int iCol, int fRow, int fCol) const{
    bool twoSpace;
    twoSpace = if(thisSquare->getRow() == 2);
    if(board(iRow,iCol+1)->occupied) return false;
    if(fCol == iCol && fRow == iRow+1) return true;
    if(twoSapce){   //Can move two spaces in first go
        if(fCol == iCol && fRow == iRow+2) return true;
    }
    if(square this(iRow + 1, iCol + 1)->occupied()!=
    
}*/
