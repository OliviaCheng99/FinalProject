//
//  GameTable.cpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/22/22.
//

#include "GameTable.hpp"
#include <iostream>

Gametable::Gametable(int row, int column){
    rows = row;
    columns = column;
    data = new int* [rows];
    for (int i = 0; i < rows; i++){
        data[i] = new int[columns];
    }
    
    for(int i=0; i < rows; i++){
            for(int j=0; j < columns; j++){
                data[i][j]=0;
               // std::cout<<data[i][j] <<" ";
            }
    }
    
    
}

Gametable::~Gametable(){
    for (int i = 0; i < rows; i++){
    delete [] data[i];
    data[i] = nullptr;
    }
    delete []data;
    
    std::cout << "Destructor has been executed\n";
}

Gametable::Gametable(const Gametable& rhs){
    rows = rhs.rows;
    columns = rhs.columns;
    data = new int* [rhs.rows];
    for (int i = 0; i < rhs.rows; i++){
        data[i] = new int[rhs.columns];
    }
    
    for(int i=0; i < rows; i++){
            for(int j=0; j < columns; j++){
                data[i][j] = rhs.data[i][j];
            }
    }
    
}

Gametable& Gametable::operator=(const Gametable& rhs){
    if(*data == *(rhs.data)){
        return *this;
    }
    
    rows = rhs.rows;
    columns = rhs.columns;
    for(int i=0; i < rows; i++){
            for(int j=0; j < columns; j++){
                data[i][j] = rhs.data[i][j];
            }
    }
    return *this;
}
    
int Gametable::Size(){
    return rows*columns;
}
    
int Gametable::Rows(){
    return rows;
}

int Gametable::Columns(){
    return columns;
}

int Gametable::Width(){
    return columns*pixel;
}

int Gametable::Height(){
    return rows*pixel;
}

int Gametable::Pixel(){
return pixel;
}

int Gametable::get(int& row, int& column){
    return  data[row][column];
}

void Gametable::set(int& row, int& column, int value){
    data[row][column] = value;
}
