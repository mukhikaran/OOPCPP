//
//  game.hpp
//  chessInterface
//
//  Created by Karan Mukhi on 01/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <memory>
#include <string>
#include "player.h"
#include "board.h"
class game {
private:
    std::unique_ptr<player> whitePlayer;
    std::unique_ptr<player> blackPlayer;
    std::shared_ptr<board> board;
public:
    game();
    std::string getWhiteName() const {return whitePlayer->getName();};
    std::string getBlackName() const {return blackPlayer-> getName();};
    void play();
};
#endif /* game_hpp */
