//
//  player.cpp
//  chessInterface
//
//  Created by Karan Mukhi on 01/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include "player.h"


player::player(std::string & playerName){
    this->setName(playerName);
}
void player::setName(std::string & playerName){
    name = playerName;
}

moveCode player::move() const{
    moveCode playerInput;
    playerInput = inputMove();

    return playerInput;
}

moveCode player::inputMove()const{
    moveCode move;
    std::string initialInput, finalInput;
    std::string input;
    
    std::cout << name << "'s move\n\nPlease enter a move:\n";
    if(std::getline(std::cin,input)){
        std::size_t space = input.find(" to ");
        if(space==std::string::npos) throw 4; //Input not formatted correctly;
        initialInput = input.substr(0,space);
        finalInput = input.substr(space+4);
    }
    else throw 3;
    move.initialSquare = convertInput(initialInput);
    move.finalSquare = convertInput(finalInput);
    return move;
}

squareCode player::convertInput(std::string squareString) const{
    squareCode result;
    char col(squareString[0]), row(squareString[1]);
    switch(col){
        case 'a':
        case 'A': result.col = 1;
            break;
        case 'b':
        case 'B': result.col = 2;
            break;
        case 'c':
        case 'C': result.col = 3;
            break;
        case 'd':
        case 'D': result.col = 4;
            break;
        case 'e':
        case 'E': result.col = 5;
            break;
        case 'f':
        case 'F': result.col = 6;
            break;
        case 'g':
        case 'G': result.col = 7;
            break;
        case 'h':
        case 'H': result.col = 8;
            break;
        default:
            throw 1; //Row exception
            break;
    }
    int rowInt = (int)(row - '0');
    if(rowInt<1||rowInt>8) throw  2; //Column exception
    else result.row = rowInt;
    return result;
}


