//
//  player.hpp
//  chessMaster
//
//  Created by Karan Mukhi on 08/04/2019.
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
    
    void print() const {
        std::cout  << col << "," << row << std::endl;
    }
};


struct moveCode{
    squareCode initialSquare;
    squareCode finalSquare;
    
    void printM() const {
        std::cout<<"Initi: ";
        initialSquare.print();
        std::cout<<"Final: ";
        finalSquare.print();
        
    }
};


class player {
    
private:
    bool colour;
    std::string name;
public:
    player(std::string playerName, bool playerColour);
    ~player(){std::cout << name << " deleted\n";}
    void setColour(bool colour);
    bool getColour() const {return colour;}
    std::string getName() const {return name;}
    moveCode getMove() const;
};
#endif /* player_hpp */
