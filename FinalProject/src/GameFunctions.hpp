//
//  GameFunctions.hpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/21/22.
//

#ifndef GameFunctions_hpp
#define GameFunctions_hpp

#include <stdio.h>

//Clase to create the game table.
class Gametable{
private:
    int rows, columns;
    int** data;
    const int pixel=20; // We created images with a size of 20 x 20 pixels to display.
    
public:
    Gametable(int rows, int columns);
    ~Gametable();
    Gametable(const Gametable& rhs);
    
    Gametable& operator=(const Gametable& rhs);
    
    int Rows();
    int Columns();
    int Width();
    int Height();
    int Pixel();
    int get(int& row, int& column);
    void set(int& row, int& column, int Value);
};

// Class to create new obstacles
class Obstacle{
public:
    int Column, Row, MoveInColumn, MoveInRow;
    Obstacle();
    void move(Gametable& table);
};

//Function

void drop(Gametable& table, int row, int column);

#endif /* GameFunctions_hpp */
