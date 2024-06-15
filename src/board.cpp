#include "board.h"
#include "count.cpp"


void Board::Init()
{
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            BoardState[i][j] = NO_DISK;
        }
    }
}

bool Board::MoveDisk(int x, int y, int disk)
{
    if(x > WIDTH || y > HEIGHT){
        // Error: The square doesn't exist.
    }
    
    if(BoardState[x][y] != 0){
        // Error: The square is already occupied.
    }

    BoardState[x][y] = disk;
}

int Board::Judge()
{
    std::array<std::array<int, WIDTH>, HEIGHT> measuredBoard = Measure();
    std::vector<Sequence> sequenceList = countSequence(measuredBoard);

    int blackSequence;
    int whiteSequence;

    for(int i=0;i<sequenceList.size();i++){
        if(sequenceList[i].color == BLACK){
            blackSequence++;
        }
        else{
            whiteSequence++;
        }
    }

    if(blackSequence > whiteSequence){
        return WIN_BLACK;
    }
    else if(blackSequence < whiteSequence){
        return WIN_WHITE;
    }
    else{
        return CONTINUE;
    }
}

std::array<std::array<int, WIDTH>, HEIGHT> Board::Measure()
{
    std::array<std::array<int, WIDTH>, HEIGHT> measuredBoard;
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            measuredBoard[i][j] = MeasureDisk(BoardState[i][j]);
        }
    }

    return measuredBoard;
}

int MeasureDisk(int disk)
{
    switch(disk){
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