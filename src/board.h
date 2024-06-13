#include <array>

#define WIDTH 10
#define HEIGHT 10

class Board
{
    public:
        // Initilize board
        void Init();
        // Move a disk
        bool MoveDisk(int x, int y, int rate);
        // Judge the board state
        int Judge();

    private:
        // Measure all disks and return a result
        std::array<std::array<int, WIDTH+1>, HEIGHT+1> Measure();

    private:
        std::array<std::array<int, WIDTH+1>, HEIGHT+1> BoardState;

};