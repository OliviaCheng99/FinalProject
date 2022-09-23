//
//  Levels.cpp
//  FinalProject
//
//  Created by Ricardo Sanchez on 9/21/22.
//

#include "Levels.hpp"

void Levels(sf::RenderWindow& window, Gametable& Table, int& NumObstacles, bool& NewGame){
    
    Obstacle obs[NumObstacles*10];
    int InNumObstacles = NumObstacles;
    int row = 0, column = 0, MoveInColumn = 0, MoveInRow = 0, Level=1;
    float timer = 0, delay = 0.07;
    bool NextLevel;
    sf::Clock clock;
    
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
    

    while (window.isOpen())
    {
        NextLevel = CheckTable(Table);
        
        if(NextLevel)
        {
            RestartTable(Table);
            Startgame(Table);
            NumObstacles*=2;
            Level++;
            row = 0;
            column = 0;
            MoveInColumn = 0;
            MoveInRow = 0;
        }
        

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
                    NewGame = true;
                    Level =1;
                    NumObstacles = InNumObstacles;
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

        if (!NewGame)
            // std::cout << "Game end!" << std::endl;
            // exit(0);
            continue;
      
        
        // delay is the wait time between 2 keyboard inputs
        // if you press -> 2 times within the delay, it will only register as 1 input
        // delay is in term of rendering
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
            // below can be a check game state function
            // give table, row, colum -> boolean
            if (Table.get(row, column) == 2) //Checking if we crush with the cell where just passed (Body)
            {
                // std::cout << "Game end! Cut self" << std::endl;
                NewGame = false;
            }
            if (Table.get(row, column) == 0)//Assign as Body if is an empty cell.
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
            MoveInRow = 0;
            MoveInColumn = 0;

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
        //Checking if I crush with a Obstacle
        for (int i = 0; i < NumObstacles; i++)
        {
            int row = obs[i].Row / Table.Pixel();
            int column = obs[i].Column / Table.Pixel();
            if (Table.get(row, column) == 2)
            {
                NewGame = false;
            }
        }
        
        // RENDERING WINDOW
        
    
        
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
                if (Table.get(i, j) == 1) //Cheching if the cell have been filled
                {
                    Stile.setPosition(j * Table.Pixel(), i * Table.Pixel());
                    window.draw(Stile);
                }
                if (Table.get(i, j) == 2) // Checking if I aready passed from this cell to fill with body image.
                {
                    Sbody.setPosition(j * Table.Pixel(), i * Table.Pixel());
                    window.draw(Sbody);
                }
            }
        }
        //Checking my actual position to gill the cell with head image.
        Shead.setPosition(column * Table.Pixel(), row * Table.Pixel());
        window.draw(Shead);

            //Choosing the different type of rivals. one per each level
            if (Level == 1){
                Sobstacle1.rotate(20);
                for (int i = 0; i < NumObstacles; i++)
                {
                    Sobstacle1.setPosition(obs[i].Column, obs[i].Row);
                    window.draw(Sobstacle1);
                }
            }
            else if(Level ==2){
                Sobstacle2.rotate(20);
                for (int i = 0; i < NumObstacles; i++)
                {
                    Sobstacle2.setPosition(obs[i].Column, obs[i].Row);
                    window.draw(Sobstacle2);
                }
            }
            else if(Level ==3){
                Sobstacle3.rotate(20);
                for (int i = 0; i < NumObstacles; i++)
                {
                    Sobstacle3.setPosition(obs[i].Column, obs[i].Row);
                    window.draw(Sobstacle3);
                }
            }
            // std::cout << obs[i].Column << " " << obs[i].row <<"\n";
        
            if(Level > 3)
            {
                window.draw(Swinner);
            }
        
        if (!NewGame)
        {
            window.draw(Sgameover);
        }

        window.display();
    }
}
