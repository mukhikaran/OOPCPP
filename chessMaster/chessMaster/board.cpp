//
//  board.cpp
//  chessMaster
//
//  Created by Karan Mukhi on 08/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include "board.hpp"
using namespace std;


board::board(){
    boardPoint = make_shared<vector<vector<square>>>();
    boardPoint->push_back(backRow(false));
    boardPoint->push_back(frontRow(true));
    bool startColour(false);
    for(int i(0); i<4; i++){
        boardPoint->push_back(emptyRow(startColour));
        startColour = !startColour;
    }
    boardPoint->push_back(frontRow(false));
    boardPoint->push_back(backRow(true));
    cout << (*this)(1,2)->getSquareColour();
}
std::vector<square> board::backRow(bool colour) const{
    char pieceColour;
    bool squareColour(colour);
    std::string pieces[8]{"QR","QN","QB","QQ","KK","KB", "KN", "KR"};
    if(colour) pieceColour = 'B';
    else pieceColour = 'W';
    std::vector<square> result;
    for(int i(0); i<8; i++){
        result.push_back(square(pieceColour+pieces[i], squareColour, boardPoint));
        squareColour = !squareColour;
    }
    return result;
}

std::vector<square> board::frontRow(bool colour) const{
    char pieceColour;
    bool squareColour(true);
    if(colour) pieceColour = 'W';
    else pieceColour = 'B';
    std::string pieces[8]{"1P","2P","3P","4P","5P","6P", "7P", "8P"};
    std::vector<square> result;
    for(int i(0); i<8; i++){
        result.push_back(square(pieceColour+pieces[i], squareColour, boardPoint));
        squareColour = !squareColour;
    }
    return result;
}

std::vector<square> board::emptyRow(bool colour) const{
    std::vector<square> result;
    for(int i(0); i<8; i++){
        result.push_back(square("-", colour, boardPoint));
        colour = !colour;
    }
    return result;
}

void board::printInfo() const{
    for_each(boardPoint->begin(), boardPoint->end(), [this] (const vector<square> row){
        printRow(row);
        cout << endl;
    });
    
}

void board::printRowInfo(const vector<square> & row) const {
    for_each(row.begin(), row.end(), [] (const square & printSquare){
        if(printSquare.getOccupation()){
        cout << printSquare.getOccupation()->getColour() <<  printSquare.getOccupation()->getSide() << printSquare.getOccupation()->getType() << " ";
        }
        else cout << " " << printSquare.getColour() << "  ";
    });
}

void board::print() const{
    for_each(boardPoint->begin(), boardPoint->end(), [this] (const vector<square> row){
        printRow(row);
        cout << endl;
    });
    
}

void board::printRow(const vector<square> & row) const {
    for(int i(0); i<7; i++){
        for(int j(0); j<8; j++){
            row[j].printLine(i);
        }
    }
}

square * board::operator()(int col, int row){
    return &(*(boardPoint))[row-1][col-1];
}

square * board::operator()(int col, int row) const{
    return &(*(boardPoint))[row-1][col-1];
}

square * board::operator()(squareCode targetSquare){
    return &(*(boardPoint))[targetSquare.row - 1][targetSquare.col - 1];
}

square * board::operator()(squareCode targetSquare) const{
    return &(*(boardPoint))[targetSquare.row - 1][targetSquare.col - 1];
}









square::square(const std::string pieceName, const bool inputColour, std::weak_ptr<std::vector<std::vector<square>>> homeBoard){
    squareColour = inputColour;
    homeBoard = homeBoard;
    if(pieceName == "-") occupation = NULL;
    else{
        char pieceColour = pieceName[0];
        char pieceSide = pieceName[1];
        char pieceType = pieceName[2];
                                       
        if(pieceType == 'K') occupation = std::make_shared<king>(pieceColour);
        else if(pieceType == 'Q') occupation = std::make_shared<queen>(pieceColour);
        else if(pieceType == 'R') occupation = std::make_shared<rook>(pieceColour, pieceSide);
        else if(pieceType == 'B') occupation = std::make_shared<bishop>(pieceColour, pieceSide);
        else if(pieceType == 'N') occupation = std::make_shared<knight>(pieceColour, pieceSide);
        else if(pieceType == 'P') occupation = std::make_shared<pawn>(pieceColour, pieceSide);
        else exit(7); // Exit with error code 7 if pieces not labeled correctly.

    }
}
void square::printInfo() const{
    cout << squareColour << " Piece: " << occupation->getColour() << " " << occupation->getSide() << " " << occupation->getType() << endl;
}

void square::printLine(const int line) const{
    std::vector<std::string> output;
    char background, pieceColour;
    if(squareColour) background = '-'; //white background
    else background = '+'; //black background
    
    if(occupation){
        if(occupation->getColour() == 'B') pieceColour = 'B'; //black piece
        else pieceColour = 'W';
        
        if(occupation->getType() == 'K'){
            output.push_back("11111111111111");
            output.push_back("11001100110011");
            output.push_back("11110000000111");
            output.push_back("11111000011111");
            output.push_back("11111000011111");
            output.push_back("11100000000111");
            output.push_back("11111111111111");
        }
        else if(occupation->getType() == 'Q'){
            output.push_back("11111111111111");
            output.push_back("11101011010111");
            output.push_back("11111000011111");
            output.push_back("11110000011111");
            output.push_back("11111000011111");
            output.push_back("11100000000111");
            output.push_back("11111111111111");
        }
        else if(occupation->getType() == 'R'){
            output.push_back("11111111111111");
            output.push_back("11100000000111");
            output.push_back("11111000011111");
            output.push_back("11111000011111");
            output.push_back("11111000011111");
            output.push_back("11100000000111");
            output.push_back("11111111111111");
        }
        else if(occupation->getType() == 'N'){
            output.push_back("11111111111111");
            output.push_back("11000000000011");
            output.push_back("11000111000111");
            output.push_back("11000111110111");
            output.push_back("11000001111111");
            output.push_back("11000000011111");
            output.push_back("11111111111111");
        }
        else if(occupation->getType() == 'B'){
            output.push_back("11111111111111");
            output.push_back("11111100111111");
            output.push_back("11111000011111");
            output.push_back("11110000001111");
            output.push_back("11111000011111");
            output.push_back("11110000001111");
            output.push_back("11111111111111");
        }
        else if(occupation->getType() == 'P'){
            output.push_back("11111111111111");
            output.push_back("11111111111111");
            output.push_back("11111100111111");
            output.push_back("11111000011111");
            output.push_back("11111000011111");
            output.push_back("11110000001111");
            output.push_back("11111111111111");
        }
        
        for(int i(0); i < 14; i ++){
            if(output[line][i]) cout << background;
            else cout << pieceColour;
        }
    }
    
    
    else {//Blank square
        for(int i(0); i < 14; i++){
            cout << background;
        }
    }
}
