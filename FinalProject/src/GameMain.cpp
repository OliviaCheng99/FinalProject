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
    
    sf::Texture T1, T2, T3, T4, T5, T6, T7, T8, T9;
    T1.loadFromFile("Images/Background.png");
    T2.loadFromFile("Images/GameOver.png");
    T3.loadFromFile("Images/Tile.png");
    T4.loadFromFile("Images/Head.png");
    T5.loadFromFile("Images/Body.png");
    T6.loadFromFile("Images/Obstacle1.png");
    T7.loadFromFile("Images/Obstacle2.png");
    T8.loadFromFile("Images/Obstacle3.png");
    T9.loadFromFile("Images/Win.png");
    
    sf::Sprite Sbackground(T1), Sgameover(T2), Stile(T3), Shead(T4),
               Sbody(T5), Sobstacle1(T6), Sobstacle2(T7), Sobstacle3(T8), Swinner(T9);
    
    Sgameover.setPosition(375, 225);
    Sobstacle1.setOrigin(20, 20);
    Sobstacle2.setOrigin(20, 20);
    Sobstacle3.setOrigin(20, 20);
    
    Startgame(Table);
    NewGame=true;
    
    Levels(window, Table, NumObstacles, NewGame);
    
    return 0;
}

//Develop a plan for your final project with your partner.
//
//Your plan should include at least the following information:
//
//What classes will you need to create?
// We created two classes one to create the game table and one to create the obstacles.

//What methods will they need?
//For the table we create methods that give us information about, position, size, number of pixels, number of column and row, and one to set and get values to the cells. For the Obstacle we create one method to create the movement on the table.
// out of the classes we also use some functions to help us: startgame, checkstatus, and resettable and Obstaclespace, they were very important in the program to help us to have control of the entire grid.

//What data will they need to store?
//We store int numbers in each cell of the grid to identify what type of image to display. we store 0 for blank spaces, 1 for set a tile, 2 for the trayectory of the head.

//In what order will you implement them?
//we need to create the game table first to set and start a new game, then we create the obstacles we want in the game. after that we play the levels where bassically we are checking the status of the cells to see if we crush with our own trayectory or with an obtacle. after comply the task in the first table, you will continue to the next level until reach level 3.

//What tests will you write along the way to verify that you're making progress?
//Because we were using rows and columns to set and get positions, in order to test if we were getting the right data we printed the data to confirm the values were correct. they are going to be around the code as comments now. These testes helped to understand better how the values were moving arround the game table (grid).
//  We use the rule of three to prevent any moemory leak, we have a copy constructor, a copy assignment opertor and the destructor. We ran the program using the address sanitazer to check for any other memory problem but we did not get any error.
