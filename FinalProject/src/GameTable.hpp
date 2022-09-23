//
//  GameTable.hpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/22/22.
//

#ifndef GameTable_hpp
#define GameTable_hpp

#include <stdio.h>

//Clase to create the game table.
class Gametable{
private:
    int rows, columns;
    int** data;
    const int pixel=30; // We created images with a size of 30 x 30 pixels to display.
    
public:
    Gametable(int rows, int columns);
    ~Gametable();
    Gametable(const Gametable& rhs);
    
    Gametable& operator=(const Gametable& rhs);
    
    int Size();
    int Rows();
    int Columns();
    int Width();
    int Height();
    int Pixel();
    int get(int& row, int& column);
    void set(int& row, int& column, int Value);
};

#endif /* GameTable_hpp */
