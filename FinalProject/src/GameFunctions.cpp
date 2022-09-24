//
//  GameFunctions.cpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/21/22.
//

#include "GameFunctions.hpp"

void Startgame(Gametable& table){

    // Filling the game table with a frame of tiles.
    for (int i = 0; i < table.Rows(); i++)
    {
        for (int j = 0; j < table.Columns(); j++)
        {
            if (i == 0 || j == 0 || i == table.Rows() - 1 || j == table.Columns() - 1)
            {
                table.set(i, j, 1);
                // std::cout << Table.get(i, j)<< " ";
            }
         }
     }
}

bool CheckTable(Gametable& table){
    int counter=0;
    // Filling the game table with a frame of tiles.
    for (int i = 0; i < table.Rows(); i++)
    {
        for (int j = 0; j < table.Columns(); j++)
        {
            if(table.get(i, j) == 1)
            {
                counter++;
            }
         }
     }
    if (counter >= 0.5*table.Size()){ //Next level if player reach complete 50% of the Table.
        //0.5*table.Size()
        return true;
    }
    return false;
}

void RestartTable(Gametable& table){
    for(int i=0; i < table.Rows(); i++){
            for(int j=0; j < table.Columns(); j++){
                table.set(i, j, 0);
            }
    }
}
//This Function helps to check if all the cells arround the obstacle are empty
//This will help us to fill the closed espaces we create with the body and head
void ObstacleSpace(Gametable& table, int row, int column){
        int up = row-1;
        int down = row+1;
        int left = column-1;
        int right = column+1;
        
        if(table.get(row, column) == 0){
            table.set(row, column, -1);
        }
        if(table.get(up, column) == 0){
            ObstacleSpace(table, up, column);
        }
        if(table.get(down, column) == 0){
            ObstacleSpace(table, down, column);
        }
        if(table.get(row, left) == 0){
            ObstacleSpace(table, row, left);
        }
        if(table.get(row, right) == 0){
            ObstacleSpace(table, row, right);
        }
    }

