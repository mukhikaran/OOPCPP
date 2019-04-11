//
//  game.cpp
//  chessInterface
//
//  Created by Karan Mukhi on 01/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

game::game(){
    std::string player1, player2;
    std::cout << "Please enter the name of player one:\n";
    getline(std::cin,player1);
     //Initialise Player 1
    std::cout << "Please enter the name of player two:\n";
    getline(std::cin,player2);
    srand(int(time(0)));
    int colourDecider = rand() % 2;
    std::cout << colourDecider;
    if(colourDecider){
        whitePlayer = std::make_unique<player>(player1);
        blackPlayer = std::make_unique<player>(player2);
        
    }
    else{
        whitePlayer = std::make_unique<player>(player2);
        blackPlayer = std::make_unique<player>(player1);
    }
    std::cout << "\n\n\n"<< whitePlayer->getName() << " is white, " << blackPlayer->getName() << " is black.\n";
    
    
    //TODO initialise board
    
}
/*
void game::setPlayer(std::unique_ptr<player> player){
    
    std::cout << "Please enter the name of player one: \n";
    std::cin>>player->setName();
}
*/



void game::play(){
    int moveNumber(0);
    bool checkMate(false);
    while(true){
        this->board->print();
        moveNumber++;
        while(true){
            try{
                std::cout << moveNumber << std::endl;
                if(moveNumber%2) whitePlayer->move();
                else blackPlayer->move();
                break;
            }
            catch(int errorflag)
            {
                if(errorflag == 1) std::cout << "Column error" << std::endl;
                if(errorflag == 2) std::cout << "Row error" << std::endl;
                if(errorflag == 3) std::cout << "Bad input" << std::endl;
                if(errorflag == 4) std::cout << "Bad Format" << std::endl;
            }
        }
        
        
        /*std::cout <<"Row movement: " <<movement.initialSquare.row <<"->" << movement.finalSquare.row << std::endl;
        std::cout << "Column movement: " << movement.initialSquare.col <<"->" << movement.finalSquare.col << std::endl;
        //board.move();*/
        if(checkMate){ //End game
        std::cout << "Checkmate!\n";
        return;
        }
    }

}
