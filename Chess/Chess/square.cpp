//
//  square.cpp
//  Chess
//
//  Created by Karan Mukhi on 29/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include "square.h"
#include <string>
#include <iostream>

using namespace std;

/*square::square(bool col, string p)
{
    colour = col;
    if(p == "-") piece = 0;
        else{
            char col, side, name;
            col = p[0];
            side = p[1];
            name = p[2];
            if(name == 'K') piece = new king(col);
            if(name == 'Q') piece = new queen(col);
            if(name == 'R') piece = new rook(col,side);
            if(name == 'B') piece = new bishop(col,side);
            if(name == 'N') piece = new knight(col,side);
            if(name == 'P') piece = new pawn(col,side);
        }
}*/

void square::newPiece(char col, char side, char name){
    if(name == 'K') piece = new king(col);
    if(name == 'Q') piece = new queen(col);
    if(name == 'R') piece = new rook(col,side);
    if(name == 'B') piece = new bishop(col,side);
    if(name == 'N') piece = new knight(col,side);
    if(name == 'P') piece = new pawn(col,side);
}

void square::printInfo() const {
    cout << " C: " << squareColour << "  P: " << (*this).getPiece();
}

string square::pieceShape(int i) const{
    string result;
    
    if(piece->getType()=='P'){
        string pawn[9] = {"111111111","111111111","111101111","111000111","111000111","110000011","111111111"};
        result = pawn[i];
    }
    else if(piece->getType()=='B'){
        string bishop[9] = {"111111111","111101111","111000111","110000011","111000111","110000011","111111111"};
        result = bishop[i];
    }
    else if(piece->getType()=='N'){
        string knight[9] = {"111111111","100000001","100011001","100011101","100011111","100000011","111111111"};
        result = knight[i];
    }
    else if(piece->getType()=='R'){
        string rook[9] = {"111111111","100000001","111000111","111000111","111000111","100000001","111111111"};
        result = rook[i];
    }
    else if(piece->getType()=='Q'){
        string queen[9] = {"111111111","110101011","111000111","111000111","110000011","100000001","111111111"};
        result = queen[i];
    }
    else if(piece->getType()=='K'){
        string king[9] = {"111111111","101010101","110000011","110000011","111000111","100000001","111111111"};
        result = king[i];
    }
    return result;
}

bool square::occupied() const{
    if(piece) return true;
    else return false;
}

void square::printLine(int i) const{
    char output;
    char sColour;
    if(squareColour) sColour = '-'; //white square
    else sColour = '+'; //black //square
    if(piece){
        char pieceColour;
        string pPiece = this->pieceShape(i);
        if(piece->getColour() == 'B') pieceColour = 'B'; //Black piece
        else pieceColour = 'W'; //White piece
        for(int i(0); i<9; i++){
            if(pPiece[i]=='1') output = sColour;
            else output = pieceColour;
            cout << output;
        }
    }
        else {
            output = sColour;
            for(int i(0); i<9; i++){
                cout << output;
            }
        }
    
    
}
void square::printSquare() const{
    for(int l(0); l<7; l++){
        this->printLine(l);
        cout << endl;
    }
}
