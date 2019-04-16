//
//  piece.cpp
//  chessMaster
//
//  Created by Karan Mukhi on 08/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include "piece.hpp"

bool linePiece::legalMove(const moveCode & move) const{
    if(!distance){
        if(abs(move.finalSquare.col - move.initialSquare.col) <= 1 && abs(move.finalSquare.row - move.initialSquare.row) <= 1) return true;
        else return false;
    }
    
    if(straight){
        if(move.finalSquare.col == move.initialSquare.col || move.finalSquare.row == move.initialSquare.row) return true;
        else return false;
    }
    if(diagonal){
        if(abs(move.finalSquare.col - move.initialSquare.col) == abs(move.finalSquare.row - move.initialSquare.row)) return true;
        else return false;
    }
    return false;
}

bool knight::legalMove(const moveCode & move) const{
    if(abs(move.finalSquare.col - move.initialSquare.col) == 2 && abs(move.finalSquare.row - move.initialSquare.row) == 1) return true;
    if(abs(move.finalSquare.col - move.initialSquare.col) == 1 && abs(move.finalSquare.row - move.initialSquare.row) == 2) return true;
    else return false;
}
