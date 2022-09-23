//
//  GameFunctions.hpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/21/22.
//

#ifndef GameFunctions_hpp
#define GameFunctions_hpp

#include <stdio.h>
#include <iostream>
#include "GameTable.hpp"

//Function

void Startgame(Gametable& table);
bool CheckTable(Gametable& table);
void drop(Gametable& table, int row, int column);
void RestartTable(Gametable& table);

#endif /* GameFunctions_hpp */
