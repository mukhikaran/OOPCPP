//
//  char.cpp
//  Assignment7
//
//  Created by Karan Mukhi on 27/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;


int main(){
    for(int i = 0; i <= 255; i++) {
        fprintf(stdout, "[%d]: %c\n", i, i);
    }
    
    return 0;
}
