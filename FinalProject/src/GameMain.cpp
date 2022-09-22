// MDS PROGRAM - CS6010 FINAL PROJECT
// SEPTEMBER 2022
//
// RICARDO SANCHEZ
// OLIVIA CHENG
//
// CREATION OF XONIX GAME

#include "GameFunctions.hpp"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

int main()
{

    int column = 0, row = 0, MoveInColumn = 0, MoveInRow = 0;
    Gametable Table(30, 50);
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(Table.Width(), Table.Height()), "CS6010 FINAL PROJECT");
    window.setFramerateLimit(60);

    sf::Texture T1, T2, T3, T4, T5, T6;
    T1.loadFromFile("Images/Background.png");
    T2.loadFromFile("Images/Tile.png");
    T3.loadFromFile("Images/Head.png");
    T4.loadFromFile("Images/Body.png");
    T5.loadFromFile("Images/Obstacle.png");
    T6.loadFromFile("Images/GameOver.png");

    sf::Sprite Sbackground(T1), Stile(T2), Shead(T3), Sbody(T4), Sobstacle(T5), Sgameover(T6);
    Sgameover.setPosition(250, 150);
    Sobstacle.setOrigin(20, 20);

    int NumObstacles = 2;
    Obstacle obs[10];
    bool newgame = true;

    float timer = 0, delay = 0;
    sf::Clock clock;

    // Filling the game table with a frame of tiles.
    for (int i = 0; i < Table.Rows(); i++)
    {
        for (int j = 0; j < Table.Columns(); j++)
        {
            if (i == 0 || j == 0 || i == Table.Rows() - 1 || j == Table.Columns() - 1)
            {
                Table.set(i, j, 1);
                // std::cout << Table.get(i, j)<< " ";
            }
        }
    }

    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::N)
                {
                    for (int i = 1; i < Table.Rows() - 1; i++)
                    {
                        for (int j = 1; j < Table.Columns() - 1; j++)
                        {
                            Table.set(i, j, 0);
                        }
                    }

                    column = 0;
                    row = 0;
                    newgame = true;
                }
            }
        }

        // Checking if player press direction keys from Keyboard

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            MoveInColumn = 0;
            MoveInRow = -1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            MoveInColumn = 0;
            MoveInRow = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            MoveInColumn = -1;
            MoveInRow = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            MoveInColumn = 1;
            MoveInRow = 0;
        }

        if (!newgame)
            continue;

        if (timer > delay)
        {
            column += MoveInColumn;
            row += MoveInRow;

            if (column < 0)
            {
                column = 0;
            }
            if (column > Table.Columns() - 1)
            {
                column = Table.Columns() - 1;
            }
            if (row < 0)
            {
                row = 0;
            }
            if (row > Table.Rows() - 1)
            {
                row = Table.Rows() - 1;
            }
            if (Table.get(row, column) == 2)
            {
                newgame = false;
            }
            if (Table.get(row, column) == 0)
            {
                Table.set(row, column, 2);
            }
            timer = 0;
        }

        for (int i = 0; i < NumObstacles; i++)
        {
            obs[i].move(Table);
        }

        if (Table.get(row, column) == 1)
        {
            MoveInColumn = MoveInRow = 0;

            for (int i = 0; i < NumObstacles; i++)
            {
                drop(Table, obs[i].Row / Table.Pixel(), obs[i].Column / Table.Pixel());
            }

            for (int i = 0; i < Table.Rows(); i++)
            {
                for (int j = 0; j < Table.Columns(); j++)
                {
                    if (Table.get(i, j) == -1)
                    {
                        Table.set(i, j, 0);
                    }
                    else
                    {
                        Table.set(i, j, 1);
                    }
                }
            }
        }

        for (int i = 0; i < NumObstacles; i++)
        {
            int row = obs[i].Row / Table.Pixel();
            int column = obs[i].Row / Table.Pixel();
            if (Table.get(row, column) == 2)
            {
                newgame = false;
            }
        }

        window.clear();

        window.draw(Sbackground);

        for (int i = 0; i < Table.Rows(); i++)
        {
            for (int j = 0; j < Table.Columns(); j++)
            {
                if (Table.get(i, j) == 0)
                {
                    continue;
                }
                if (Table.get(i, j) == 1)
                {
                    Stile.setPosition(j * Table.Pixel(), i * Table.Pixel());
                    window.draw(Stile);
                }
                if (Table.get(i, j) == 2)
                {
                    Sbody.setPosition(j * Table.Pixel(), i * Table.Pixel());
                    window.draw(Sbody);
                }
            }
        }

        Shead.setPosition(column * Table.Pixel(), row * Table.Pixel());
        window.draw(Shead);

        Sobstacle.rotate(10);
        for (int i = 0; i < NumObstacles; i++)
        {
            Sobstacle.setPosition(obs[i].Column, obs[i].Row);
            window.draw(Sobstacle);
            // std::cout << obs[i].Column << " " << obs[i].row <<"\n";
        }

        if (!newgame)
        {
            window.draw(Sgameover);
        }

        window.display();
    }
    return 0;
}
