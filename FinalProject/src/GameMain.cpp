// MDS PROGRAM - CS6010 FINAL PROJECT
// SEPTEMBER 2022
//
// RICARDO SANCHEZ
// OLIVIA CHENG
//
// CREATION OF XONIX GAME

#include "GameFunctions.hpp"
#include "GameTable.hpp"
#include "Obstacles.hpp"
#include "Levels.hpp"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

int main()
{
    srand(time(NULL));

    Gametable Table(30, 50);
  
    int NumObstacles = 5;
    bool NewGame, NextLevel;
    
    sf::RenderWindow window(sf::VideoMode(Table.Width(), Table.Height()), "CS6010 FINAL PROJECT");
    window.setFramerateLimit(60);
    
    Startgame(Table);
    NewGame=true;
    
    Levels(window, Table, NumObstacles, NewGame);
    
    return 0;
}
