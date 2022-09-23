//
//  Levels.hpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/21/22.
//

#ifndef Levels_hpp
#define Levels_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "GameTable.hpp"
#include "GameFunctions.hpp"
#include "Obstacles.hpp"
#include <time.h>

void Levels(sf::RenderWindow& window, Gametable& Table, int& NumObstacles, bool& NewGame);

#endif /* Levels_hpp */
