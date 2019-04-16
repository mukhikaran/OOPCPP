//
//  main.cpp
//  chessMaster
//
//  Created by Karan Mukhi on 08/04/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include <iostream>
#include <memory>
#include "game.hpp"
using namespace std;

int main() {
    cout << "Welcome to Chess!\n";
    game chess;
    chess.play();
    
    return 0;
}
