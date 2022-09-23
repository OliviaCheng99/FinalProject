//
//  GameFunctions.cpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/21/22.
//

#include <iostream>
#include "GameFunctions.hpp"

// add in addLevel
Gametable::Gametable(int row, int column)
{
    rows = row;
    columns = column;
    data = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new int[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            data[i][j] = 0;
            // std::cout<<data[i][j] <<" ";
        }
    }
}

Gametable::~Gametable()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] data[i];
        data[i] = nullptr;
    }
    delete[] data;

    std::cout << "Destructor has been executed\n";
}

Gametable::Gametable(const Gametable &rhs)
{
    rows = rhs.rows;
    columns = rhs.columns;
    data = new int *[rhs.rows];
    for (int i = 0; i < rhs.rows; i++)
    {
        data[i] = new int[rhs.columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            data[i][j] = rhs.data[i][j];
        }
    }
}

Gametable &Gametable::operator=(const Gametable &rhs)
{
    if (*data == *(rhs.data))
    {
        return *this;
    }

    rows = rhs.rows;
    columns = rhs.columns;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            data[i][j] = rhs.data[i][j];
        }
    }
    return *this;
}
int Gametable::Rows()
{
    return rows;
}

int Gametable::Columns()
{
    return columns;
}

int Gametable::Width()
{
    return columns * pixel;
}

int Gametable::Height()
{
    return rows * pixel;
}

int Gametable::Pixel()
{
    return pixel;
}

int Gametable::get(int row, int column)
{
    return data[row][column];
}

void Gametable::set(int row, int column, int value)
{
    data[row][column] = value;
}

Obstacle::Obstacle()
{
    Column = 300;
    Row = 300;
    MoveInColumn = 5 - rand() % 10;
    MoveInRow = 5 - rand() % 10;
}

void Obstacle::move(Gametable &table)
{

    int row;
    int column;

    Column += MoveInColumn;
    row = Row / table.Pixel();
    column = Column / table.Pixel();
    if (table.get(row, column) == 1)
    {
        MoveInColumn = -MoveInColumn;
        Column += MoveInColumn;
    }
    Row += MoveInRow;
    row = Row / table.Pixel();
    column = Column / table.Pixel();
    if (table.get(row, column) == 1)
    {
        MoveInRow = -MoveInRow;
        Row += MoveInRow;
    }
}

void drop(Gametable &table, int row, int column)
{
    int up = row - 1;
    int down = row + 1;
    int left = column - 1;
    int right = column + 1;

    if (table.get(row, column) == 0)
    {
        table.set(row, column, -1);
    }
    if (table.get(up, column) == 0)
    {
        drop(table, up, column);
    }
    if (table.get(down, column) == 0)
    {
        drop(table, down, column);
    }
    if (table.get(row, left) == 0)
    {
        drop(table, row, left);
    }
    if (table.get(row, right) == 0)
    {
        drop(table, row, right);
    }
}
