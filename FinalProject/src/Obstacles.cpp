//
//  Obstacles.cpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/22/22.
//

#include "Obstacles.hpp"
#include <iostream>


Obstacle::Obstacle(){
Column=750; //Inicial position
Row=500; // Inicial position
    MoveInColumn=5-rand()%11; //Getting a Randon Position in Columns
    MoveInRow=5-rand()%11; //Getting a Randon Position in Rows
}

void Obstacle::move(Gametable& table){
   
    int row;
    int column;
    
    Column+=MoveInColumn;
    row = Row/table.Pixel();
    column = Column/table.Pixel();
    if(table.get(row, column) == 1){ //Changing direction of the Obstacles Left or Right (Columns)
        MoveInColumn=-MoveInColumn;
        Column+=MoveInColumn;
    }
    Row+=MoveInRow;
    row = Row/table.Pixel();
    column = Column/table.Pixel();
    if(table.get(row, column) == 1){ // Changing direction of the Obstacles UP or Down (Rows)
        MoveInRow=-MoveInRow;
        Row+=MoveInRow;
    }
}
