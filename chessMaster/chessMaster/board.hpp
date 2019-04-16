//
//  board.hpp
//  chessMaster
//
//  Created by Karan Mukhi on 08/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include <vector>
#include <memory>
#include <string>
#include "piece.hpp"



class square; //Forward declaration of square class

class board {
private:
    std::shared_ptr<std::vector<std::vector<square> > > boardPoint;
    
public:
    board(); //Constructor
    std::vector<square> backRow(bool colour) const; //Forms row of non-pawn pieces
    std::vector<square> frontRow(bool colour) const; //Forms row of pawns
    std::vector<square> emptyRow(bool colour) const; //Forms empty row
    void printInfo() const; //Prints board
    void printRowInfo(const std::vector<square> & printSquare) const;
    void print() const; //Prints board
    void printRow(const std::vector<square> & printSquare) const;
    void move(bool colour, moveCode move); //Player of colour, colour makes movement
    square * operator()(int col, int row); //Returns pointer to square col,row
    square * operator()(int col, int row) const; //Const of above
    square * operator()(squareCode targetSquare); //Returns pointer of squareCode
    square * operator()(squareCode targetSquare) const; //Const above
    bool check(bool colour) const; // Checks if player of colour is in check
    bool checkmate(bool colour) const; // Checks if player of colour is in checkmate
};

class square{
private:
    bool squareColour; //Colour of the square
    std::shared_ptr<piece> occupation; //Pointer to piece occupying square, default null
    std::weak_ptr<board> homeBoard; //Pointer to board
public:
    square(const std::string pieceName, const bool inputColour, std::weak_ptr<std::vector<std::vector<square> > > homeBoard);
    std::shared_ptr<piece> getOccupation() const {return occupation;}
    bool getColour() const {return squareColour;}
    void printInfo() const; //Prints information about the square;
    void printLine(const int line) const; //Prints a line in of the square;
    bool getSquareColour(){return squareColour;}
};
#endif /* board_hpp */
