//
//  pieces.h
//  Chess
//
//  Created by Karan Mukhi on 25/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//  Header file defining the square class.
//  This class stores data about each square on the chess board
//
//  Member variables:
//                      colour - Colour of the square
//                      piece - Code of the piece that is one the square

//  Member Functions:
//                      
//
//
//
//
//
//
//


#ifndef square_h
#define square_h
#include <string>
#include "pieces.h"

using namespace std;

class square
{
private:
    bool squareColour;
    Piece *piece;
    
public:
    //Constructors
    ~square(){delete piece;}
    square(): squareColour(false), piece(0){} //Default
    //Set/Get functions
    bool getColour() const {return squareColour;} //Gets colour of the square
    void setColour(char col){squareColour = col;} //Sets the colour of the square
    bool occupied() const; //Returns bool value depending on if there is a piece
    
    char getPiece() const {if(piece) return piece->getName(); else return'-';} //Gets piece occupying the square
    void newPiece(char col, char side, char name); //Adds piece to the square of type fullname
    void printInfo() const; //Prints information about the square
    void printLine(int i) const; //Prints a pictorial line in of the square
    void printSquare()const; //Prints the square in pictorial representation
    string pieceShape(int i) const; //Returns line i in the pictorial representation of the square;
    
};



#endif
