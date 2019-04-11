//
//  board.cpp
//  Chess
//
//  Created by Karan Mukhi on 29/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include "square.h"
#include "board.h"
#include <iostream>

using namespace std;

board::board(){
    boardPoint = new square*[8];
    for(int i(0); i < 8; i++){
        boardPoint[i] = new square[8];
    }
    this->backRow(true);
    this->backRow(false);
    this->frontRow(true);
    this->frontRow(false);
    for(int row(3); row <= 6; row++){
        this->emptyRow(row);
    }
}
//Destructor
board::~board(){
    for(int i(0); i < 8; i++){
        delete[] boardPoint[i];
    }
}

//Square access functions
//Returns the square on the ith row and jith column
square & board::operator()(int i, int j){
    return *(boardPoint[i-1] + j-1);
}
square & board::operator()(int i, int j) const{
    return *(boardPoint[i-1] + j-1);
}

//Inputs rows of squares onto the board that have back row pieces
void board::backRow(bool colour){
    int row;
    char pieceColour;
    bool sColour;
    string pieceNames[8] = {"QR", "QN", "QB", "KK", "QQ", "KB", "KN", "KR"};
    if(colour){pieceColour = 'W'; row = 1;}
    else {pieceColour = 'B'; row = 8;}
    
    if(colour){sColour = false;}
    else sColour = true;
    
    for(int col(1); col<=8; col++){
        (*this)(row,col).setColour(sColour);
        (*this)(row,col).newPiece(pieceColour, pieceNames[col-1][0], pieceNames[col-1][1]);
        sColour = !sColour;
    }
}

//Inputs rows of squares onto the board that have pawns on them
void board::frontRow(const bool colour){
    int row;
    char pieceColour;
    bool squareColour;
    string pieceNames[8] = {"AP", "BP", "CP", "DP", "EP", "FP", "GP", "HP"};
    
    if(colour){pieceColour = 'W'; row = 2;}
    else {pieceColour = 'B'; row = 7;}
    
    if(colour){squareColour = true;}
    else squareColour = false;
    
    for(int col(1); col<=8; col++){
        (*this)(row,col).setColour(squareColour);
        (*this)(row,col).newPiece(pieceColour, pieceNames[col-1][0], pieceNames[col -1][1]);
        squareColour = !squareColour;
    }
}
//Inputs rows of squares onto the board that have no pieces
void board::emptyRow(int row){
    bool squareColour;
    int j = row%2;
    squareColour = j;
    for(int col(0); col<8; col++){
        (*this)(row,col).setColour(squareColour);
        squareColour = !squareColour;
    }
}

void board::print()const{
    int width(9);
    for(int i(1); i<8*width+3;i++) cout << "#";
    cout<<endl;
    for(int i(1); i <= 8; i++){
        for(int k(0); k<7; k++){
            cout << "#";
            for(int j(1); j<= 8; j++){
                (*this)(i,j).printLine(k);
            }
            cout << "#\n";
        }
    }
    for(int i(1); i<8*width+3;i++) cout << "#";
    cout<<endl;
}

void board::printInfo()const{
    for(int i(1); i <= 8; i++){
        for(int j(1); j<= 8; j++){
            (*this)(i,j).printInfo();
        }
        cout << endl;        
    }
}



//Converts user input to coordinte between 0 and 7 for the row
int rowCode(const string &position){
    
    if(position.length()!=2) return -1;
    char c = position[1];
    int r = c - '0';
    if(r<0 || r>7) return -1;
    else return r;
}
//Converts user input to coordinte between 0 and 7 for the column
int colCode(const string &position){
    
    if(position.length()!=2) return -1;
    char c = position[0];
    if(c=='A' || c == 'a') return 0;
    if(c=='B' || c == 'b') return 1;
    if(c=='C' || c == 'c') return 2;
    if(c=='D' || c == 'd') return 3;
    if(c=='E' || c == 'e') return 4;
    if(c=='F' || c == 'f') return 5;
    if(c=='G' || c == 'g') return 6;
    if(c=='H' || c == 'h') return 7;
    else return -1;
}

