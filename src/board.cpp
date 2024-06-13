#include <stdlib.h> 
#include "board.h"

#define NO_DISK 0
#define BLACK10_WHITE90 1
#define BLACK30_WHITE70 2
#define BLACK70_WHITE30 3
#define BLACK90_WHITE10 4

#define NONE 0
#define BLACK 1
#define WHITE 2

#define CONTINUE 0
#define WIN_BLACK 1
#define WIN_WHITE 2


void Board::Init()
{
    for(int i=0;i<WIDTH+1;i++){
        for(int j=0;j<HEIGHT+1;j++){
            BoardState[i][j] = NO_DISK;
        }
    }
}

bool Board::MoveDisk(int x, int y, int rate)
{
    if(x >= WIDTH || y >= HEIGHT){
        // Error: The square doesn't exist.
    }
    
    if(BoardState[x][y] != 0){
        // Error: The square is already occupied.
    }

    BoardState[x][y] = rate;
}

int Board::Judge()
{
    std::array<std::array<int, WIDTH+1>, HEIGHT+1> result = Measure();
    // ToDo: Judgement Logic
}

std::array<std::array<int, WIDTH+1>, HEIGHT+1> Board::Measure()
{
    std::array<std::array<int, WIDTH+1>, HEIGHT+1> result;
    for(int i=0;i<WIDTH+1;i++){
        for(int j=0;j<HEIGHT+1;j++){
            result[i][j] = MeasureDisk(BoardState[i][j]);
        }
    }

    return result;
}

int MeasureDisk(int rate)
{
    switch(rate){
        case NO_DISK:
            return NONE;

        case BLACK10_WHITE90:
            return getColorByRate(10, 90);

        case BLACK30_WHITE70:
            return getColorByRate(30, 70); 

        case BLACK70_WHITE30:
            return getColorByRate(70, 30); 

        case BLACK90_WHITE10:
            return getColorByRate(90, 10); 

        default:
            // Error: Undefined Rate
    }
}

int getColorByRate(int blackRate, int whiteRate)
{
    int randomNumber = rand() % (blackRate + whiteRate);

    if(randomNumber < blackRate){
        return BLACK;
    }
    else{
        return WHITE;
    }
}