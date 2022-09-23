//
//  Obstacles.hpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/22/22.
//

#ifndef Obstacles_hpp
#define Obstacles_hpp

#include <stdio.h>
#include "GameTable.hpp"
#include "GameFunctions.hpp"
#include <time.h>

// Class to create new obstacles
class Obstacle{
public:
    int Column, Row, MoveInColumn, MoveInRow;
    Obstacle();
    void move(Gametable& table);
};


#endif /* Obstacles_hpp */
