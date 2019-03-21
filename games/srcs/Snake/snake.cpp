/*
** EPITECH PROJECT, 2018
** Test
** File description:
** testcpp.cpp
*/

#include "snake.hpp"

snakebody::snakebody(int col, int row)
{
    x = col;
    y = row;
}

snakebody::snakebody()
{
    x = 0;
    y = 0;
}

snakeclass::snakeclass()
{
    initscr();
    nodelay(stdscr, true); //Getch dont wait a key
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    getmaxyx(stdscr, maxheight, maxwidth);

    snakepart = 'o';
    term = (char) 219;
    wall = '|';
    foo = '*';
    locFood.x = 0;
    locFood.y = 0;
    for(int i = 0; i < 5; i++)
        snake.push_back(snakebody(40 + i, 10));
    points = 0;
    delay = 110000;
    food = 0;
    direction = 'l';
    srand(time(0));
    createFood();
    for(int i = 0; i < maxwidth - 1; i++)
        {
                move(0,i);
                addch(term);
        }
        for(int i = 0; i < maxheight - 1 ;i++)
        {
                move(i,0);
                addch(term);
        }
        for(int i = 0; i < maxwidth - 1 ;i++)
        {
                move(maxheight-2,i);
                addch(term);
        }
        for(int i = 0; i < maxheight - 1 ;i++)
        {
                move(i,maxwidth - 2);
                addch(term);
        }
        for(int i = 10; i < maxheight - 10 ;i++)
        {
                move(i,maxwidth - 30);
                addch(wall);
        }
        for(int i = 10; i < maxheight - 10 ;i++)
        {
                move(i,maxwidth - 80);
                addch(wall);
        }
    for(int i = 0; i < snake.size(); i++) {
        move(snake[i].y, snake[i].x);
        addch(snakepart);
    }
    move(maxheight - 1, 0);
    printw("%d", points);
    move(locFood.y, locFood.x);
    addch(foo);
    refresh();
}

snakeclass::~snakeclass() 
{
    nodelay(stdscr, false);
    getch();
    endwin();
}

void snakeclass::createFood() 
{
    while(1){
        int tmpx = rand() % maxwidth + 2;
        int tmpy = rand() % maxheight + 2;
        for(int i = 0; i < snake.size(); i++)
            if (snake[i].x == tmpx && snake[i].y == tmpy)
                continue;
        if(tmpx >= maxwidth - 2 || tmpy >= maxheight - 3)
            continue;
        locFood.x = tmpx;
        locFood.y = tmpy;
        break;
    }
        move(locFood.y, locFood.x);
        addch(foo);
        refresh();
}

bool snakeclass::collision()
{
    if(snake[0].x == 0 || snake[0].x == maxwidth - 1 || snake[0].y == 0 
    || snake[0].y == maxheight - 2)
        return (true);
    for(int i = 2; i < snake.size(); i++)
        if(snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return (true);
    if(snake[0].x == locFood.x && snake[0].y == locFood.y) {
        food = true;
        createFood();
        points += 50;
        move(maxheight - 1, 0);
        printw("%d", points);
        if((points % 100) == 0)
            delay -= 10000;
    }else
        food = false;
    return (false);
}

void snakeclass::movesnake()
{
        int tmp = getch();
        switch(tmp)
        {
                case KEY_LEFT:
                        if(direction != 'r')
                                direction = 'l';
                        break;
                case KEY_UP:
                        if(direction != 'd')
                                direction = 'u';
                        break;
                case KEY_DOWN:
                        if(direction != 'u')
                                direction = 'd';
                        break;
                case KEY_RIGHT:
                        if(direction != 'l')
                                direction = 'r';
                        break;
                case KEY_BACKSPACE:
                        direction = 'q';
                        break;
        }
        if(!food)
        {
                move(snake[snake.size() - 1].y, snake[snake.size() - 1].x);
                printw(" ");
                refresh();
                snake.pop_back();
        }
        if(direction=='l')
        {
                snake.insert(snake.begin(),snakebody(snake[0].x - 1, snake[0].y));
        }else if(direction=='r'){
                snake.insert(snake.begin(),snakebody(snake[0].x + 1, snake[0].y));
        }else if(direction=='u'){
                snake.insert(snake.begin(),snakebody(snake[0].x, snake[0].y - 1));
        }else if(direction=='d'){
                snake.insert(snake.begin(),snakebody(snake[0].x, snake[0].y + 1));
        }
            move(snake[0].y, snake[0].x);
            addch(snakepart);
        refresh();
}

void snakeclass::start()
{
    while(1) {
        if(collision()) {
            move(12, 36);
            printw("Game Over");
            break;
    }
    movesnake();
    if(direction == 'q')
        break;
    usleep(delay);
    }
}