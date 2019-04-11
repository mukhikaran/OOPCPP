//
//  pieces.hpp
//  Chess
//
//  Created by Karan Mukhi on 29/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#ifndef pieces_hpp
#define pieces_hpp

#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;

class Piece{
protected:
    char name;
    char side;
    char colour;
    
public:
    virtual ~Piece(){};
    virtual bool movement(int iRow, int iCol, int fRow, int fCol) const = 0;
    char getName() const {return name;}
    char getType() const{ return name;}
    char getColour() const{return colour;}
};

//Base class for King, Queen, Rook, Bishop
class linePiece: public Piece{
protected:
    bool straight; //If the piece can move in straight lines
    bool diag; //If the piece can move in diagonal lines
    bool dist; //Distance the piece can move, false for king, true for rook queen bishop
public:
    bool movement(int iRow, int iCol, int fRow, int fCol) const; //Returns true if the move is legal
};

//King class
class king: public linePiece{
public:
    king(char col) {name = 'K'; side = 'K'; colour = col; dist = false; diag = true; straight = true;}
};
//Queen class
class queen: public linePiece{
public:
    queen(char col) {name = 'Q'; side = 'Q'; colour = col; dist = true; diag = true; straight = true;}
};
//Rook class
class rook: public linePiece{
public:
    rook(char col, char s) {name = 'R'; side = s; colour = col; dist = true; diag = false; straight = true;}
};
//Bishop class
class bishop: public linePiece{
public:
    bishop(char col, char s) {name = 'N'; side = s; colour = col; dist = true; diag = true; straight = false;}
};

//Knight class
class knight: public Piece{
public:
    knight(char col, char s) {name = 'N'; side = s; colour = col;}
    //bool legalMove() const {return true;}
    bool movement(int iRow, int iCol, int fRow, int fCol) const;
};
    
//Pawn class
class pawn: public Piece{
public:
    pawn(char col, char s) {name = 'P'; side = s; colour = col;}
    //bool legalMove() const {return true;}
    bool movement(int iRow, int iCol, int fRow, int fCol) const {return true;}
    //bool movement(int iRow, int iCol, int fRow, int fCol) const;
};

#endif 
