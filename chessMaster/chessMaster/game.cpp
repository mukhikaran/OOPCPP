//
//  game.cpp
//  chessMaster
//
//  Created by Karan Mukhi on 08/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include "game.hpp"

game::game(){
    
    boardPoint = std::make_shared<board>();
    
    std::string player1, player2;
    std::cout << "Initialising new game.\nPlease enter the name of player one:\n";
    std::getline(std::cin, player1);
    std::cout<< "Please enter the name of player two:\n";
    std::getline(std::cin, player2);
    srand( static_cast<unsigned int>(time(NULL)));
    int randomval = rand() % 2;
    if(randomval){
        white = std::make_unique<player>(player1,true);
        black = std::make_unique<player>(player2,false);
    }
    else {
        white = std::make_unique<player>(player2,true);
        black = std::make_unique<player>(player1,false);
    }
    std::cout<< white->getName() << " is white. " << black->getName() << " is black.\n" << white->getName() << " to move first.\n";
    
    
}

void game::play(){
    bool checkmate(false);
    bool turn(true);
    moveCode move;
    this->boardPoint->print();
    while(!checkmate){
        while(true){
            try{
                if(turn){
                    std::cout << white->getName();
                    move = white->getMove();
                    //this->turn(white->getColour(), move);
                }
                else{
                    std::cout << black->getName();
                    move = black->getMove();
                    //this->turn(black->getColour(), move);
                }
                
                
                
                this->move(turn, move);
                
                break;
            }
            catch(int errorFlag)
            {
                if(errorFlag == 1) {std::cout << "Bad Format in input\n";}
                if(errorFlag == 2) {std::cout << "Column Error\n";}
                if(errorFlag == 3) {std::cout << "Row Error\n";}
            }
        }

        turn = !turn;
        checkmate = this->checkmate();
        
    }
}

void game::move(bool colour, const moveCode move){
    std::cout << colour << "\nEntered move: \n";
    move.printM();
}
