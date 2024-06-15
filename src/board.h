#include <array>

#define WIDTH 10
#define HEIGHT 10

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

class Board
{
    public:
        // Initilize board
        void Init();
        // Move a disk
        bool MoveDisk(int x, int y, int rate);
        // Judge the board state
        int Judge();

    public:
        std::array<std::array<int, WIDTH>, HEIGHT> BoardState;

    private:
        // Measure all disks and return a result
        std::array<std::array<int, WIDTH>, HEIGHT> Measure();

};