#include <vector>
#include <iostream>
#include "game.h"
#include "playboard.h"
#include "snakeGenerator.h"
#include "fruitGenerator.h"

void GameOver(std::string message){
    backgroundClear();
    std::cout << message << std::endl;
    exit(1);
}

void play_game()
{
    char up = 'z';
    char down = 's';
    char right = 'd';
    char left = 'q';
    char exitKey = 'e';
    char key = right;
    char Wantedkey = right;
    Snake snake(89, 88, 87);
    int pos;
    int fruitPos = generate_Fruit(snake);

    while (true)
    {
        // on efface tout
        backgroundClear();
        reset_board();

        // on écrit le serpent dans le board
        add_snake_to_board(snake.body);
        add_fruit_to_board(fruitPos);

        // on dessine le board
        // qui contient donc le serpent
        draw_board();

        // on temporise un tour
        sleepOneLap(MS);
        //std::cout << key << std::endl;
        // si un caractère a été entré
        // on le lit sinon ça continue
        if (keyEvent())
        {
            std::cin >> Wantedkey;
            if(((Wantedkey == right || Wantedkey == left) && (key == down || key == up)) || ((Wantedkey == down || Wantedkey == up) && (key == left || key == right)) || Wantedkey == exitKey){
                key = Wantedkey;
            }
        }
        pos = snake.GetPos(0);
        int Oldi = (pos - pos%columns) / columns;
        int Oldj = pos%columns;
        // on traite les clés
        if (key == right)
        {
            pos +=1;
        }
        else if (key == up)
        {
            pos -=columns;
        }
        else if (key == left)
        {
            pos -=1;
        }
        else if (key == down)
        {
            pos +=columns;
        }
        else if (key == exitKey) // on veut quitter la partie
        {
            GameOver("see you soon little snake !");
        }
        if((Oldi == 0 && key == up) || (Oldi == rows-1 && key == down) || (Oldj == 0 && key == left) || (Oldj == columns-1 && key == right) || snake.CheckSnakeAt(pos)){
            GameOver("Game Over");
        }

        snake.AddHead(pos);
        if(snake.CheckSnakeAt(fruitPos)){
            fruitPos = generate_Fruit(snake);
        }
        else{
            snake.RemoveTail();
        }
        
    }
}