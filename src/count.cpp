#include <vector>
#include <array>
#include "board.h"

#define EAST 0
#define SOUTH_EAST 1
#define SOUTH 2

struct Sequence
{
    int color;
    int x;
    int y;
    int direction;
};


std::vector<Sequence> countSequence(std::array<std::array<int, WIDTH>, HEIGHT> measuredBoard)
{
    std::vector<Sequence> sequenceList;
    
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){

            // check east direction sequences
            if(j < HEIGHT-4){
                if(measuredBoard[i][j] == measuredBoard[i][j+1]
                    && measuredBoard[i][j+1] == measuredBoard[i][j+2]
                    && measuredBoard[i][j+2] == measuredBoard[i][j+3]
                    && measuredBoard[i][j+3] == measuredBoard[i][j+4]){
                    
                    if(measuredBoard[i][j] == BLACK){
                        sequenceList.push_back({BLACK, i, j, EAST});
                    }
                    else if(measuredBoard[i][j] == WHITE){
                        sequenceList.push_back({WHITE, i, j, EAST});
                    }

                }
            }

            // check south-east direction sequences
            if(i < WIDTH-4 && j < HEIGHT-4){
                if(measuredBoard[i][j] == measuredBoard[i+1][j+1]
                    && measuredBoard[i+1][j+1] == measuredBoard[i+2][j+2]
                    && measuredBoard[i+2][j+2] == measuredBoard[i+3][j+3]
                    && measuredBoard[i+3][j+3] == measuredBoard[i+4][j+4]){
                    
                    if(measuredBoard[i][j] == BLACK){
                        sequenceList.push_back({BLACK, i, j, SOUTH_EAST});
                    }
                    else if(measuredBoard[i][j] == WHITE){
                        sequenceList.push_back({WHITE, i, j, SOUTH_EAST});
                    }

                }
            }

            // check south direction sequences
            if(i < WIDTH-4){
                if(measuredBoard[i][j] == measuredBoard[i+1][j]
                    && measuredBoard[i+1][j] == measuredBoard[i+2][j]
                    && measuredBoard[i+2][j] == measuredBoard[i+3][j]
                    && measuredBoard[i+3][j] == measuredBoard[i+4][j]){
                    
                    if(measuredBoard[i][j] == BLACK){
                        sequenceList.push_back({BLACK, i, j, SOUTH});
                    }
                    else if(measuredBoard[i][j] == WHITE){
                        sequenceList.push_back({WHITE, i, j, SOUTH});
                    }

                }
            }
        }
    }

    return sequenceList;
}