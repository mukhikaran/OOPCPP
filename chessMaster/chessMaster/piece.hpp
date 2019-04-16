//
//  piece.hpp
//  chessMaster
//
//  Created by Karan Mukhi on 08/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#ifndef piece_hpp
#define piece_hpp
#include "player.hpp"
//#include "square.hpp"
#include <stdio.h>

class piece {
    //Abstract base class for all pieces
protected:
    char colour;
    char side; //Which side of the board the piece is - 'K' or 'Q' for back pieces, A->H for pawns
    char type; //Name code of piece
    //square* homeSquare;
public:
    virtual ~piece(){}
    virtual bool legalMove(const moveCode & move) const = 0;
    char getColour() const {return colour;}
    char getSide() const {return side;}
    char getType() const {return type;}
    
};

class linePiece: public piece {
    //A class for all pieces that travel back and forwards in straight lines, i.e. king, queen, rook and bishop
protected:
    bool straight; //Sets whether the piece can move in straight lines
    bool diagonal; //Sets whether the piece can move on diagonals
    bool distance; //Sets how far the piece can move, false for the king
public:
    bool legalMove(const moveCode & move) const;
};

class king: public linePiece {
public:
    king(char inputColour){
        colour = inputColour;
        side = 'K';
        type = 'K';
        straight = true;
        diagonal = true;
        distance = false;
    }
    
};

class queen: public linePiece {
public:
    queen(char inputColour){
        colour = inputColour;
        side = 'Q';
        type = 'Q';
        straight = true;
        diagonal = true;
        distance = true;
    }
    
};

class rook: public linePiece {
public:
    rook(char inputColour, char inputSide){
        colour = inputColour;
        side = inputSide;
        type = 'R';
        straight = true;
        diagonal = false;
        distance = true;
    }
    
};

class bishop: public linePiece {
public:
    bishop(char inputColour, char inputSide){
        colour = inputColour;
        side = inputSide;
        type = 'B';
        straight = false;
        diagonal = true;
        distance = true;
    }
    
};

class knight: public piece {
public:
    knight(char inputColour, char inputSide){
        colour = inputColour;
        side = inputSide;
        type = 'N';
    }
    bool legalMove(const moveCode & move) const;
};

class pawn: public piece{
public:
    pawn(char inputColour, char inputSide){
        colour = inputColour;
        side = inputSide;
        type = 'P';
    }
    bool legalMove(const moveCode & move) const{return true;}
};
#endif /* piece_hpp */
