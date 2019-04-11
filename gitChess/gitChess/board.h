//
//  board.h
//  Chess
//
//  Created by Karan Mukhi on 27/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#ifndef board_h
#define board_h
#include "square.h"

class board
{
private:
    square **boardPoint;
    
public:
    board(); //Default constructor
    ~board();//Destructor
    
    void backRow(bool colour); //Forms row of non-pawn pieces
    void frontRow(bool colour); //Forms row of pawn pieces
    void emptyRow(int row); //Forms row of empty squares
    void print() const; //Prints out board in user friendly manner
    void printInfo() const; //Prints out board in non user friendy manner
    bool move(const string code); //Moves pieces based on code - returns true if move is valid and false if not
    
    //Access functions returning squares corresponding to the coordinates i,j
    square & operator()(int i, int j);
    square & operator()(int i, int j) const;
    
};
#endif /* board_h */
