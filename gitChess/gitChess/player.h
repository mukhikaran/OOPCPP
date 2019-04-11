//
//  player.hpp
//  chessInterface
//
//  Created by Karan Mukhi on 01/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>
#include <iostream>

struct squareCode{
    int row;
    int col;
};

struct moveCode{
    squareCode initialSquare;
    squareCode finalSquare;
};

class player{
private:
    std::string name;
    char colour;
public:
    player(std::string & playerName);
    void setName(std::string & playerName);
    void setColour(char col){colour = col;}
    std::string getName(){return name;}
    moveCode inputMove()const;
    moveCode move() const;
    squareCode convertInput(std::string squareString) const;
};

#endif /* player_hpp */
