//
//  game.hpp
//  chessMaster
//
//  Created by Karan Mukhi on 08/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include<memory>
#include "player.hpp"
#include "board.hpp"

class game {
private:
    std::unique_ptr<player> white;
    std::unique_ptr<player> black;
    std::shared_ptr<board> boardPoint;
    
public:
    game();
    ~game(){std::cout << "Ending game\n";}
    void play();
    void move(bool colour, const moveCode move);
    bool checkmate() const {return false;}
    std::shared_ptr<board> getBoard() const {return boardPoint;}
};

#endif /* game_hpp */
