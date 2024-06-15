#include <iostream>
#include <vector>
#include <array>
#include "board.h"
#include "count.cpp"

// ANSIエスケープシーケンスの定義
const std::string ANSI_RESET = "\033[0m";
const std::string ANSI_GREEN_BG = "\033[42m";

const std::string ANSI_WHITE = "\033[97m";
const std::string ANSI_LIGHT_GRAY = "\033[37m";
const std::string ANSI_DARK_GRAY = "\033[90m";
const std::string ANSI_BLACK = "\033[30m";


// 盤面を表示する関数
void displayBoard(std::array<std::array<int, WIDTH>, HEIGHT> board)
{
    // 列番号の表示
    std::cout << "  ";
    for (int i = 0; i < WIDTH; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 行番号と盤面の表示
    for (int i = 0; i < WIDTH; i++) {
        std::cout << i << " ";
        for (int j = 0; j < HEIGHT; j++) {
            std::cout << ANSI_GREEN_BG;
            if (board[i][j] == BLACK10_WHITE90) {
                std::cout << ANSI_WHITE << "10" << ANSI_RESET << ANSI_GREEN_BG << " ";
            } else if (board[i][j] == BLACK30_WHITE70) {
                std::cout << ANSI_LIGHT_GRAY << "30" << ANSI_RESET << ANSI_GREEN_BG << " ";
            } else if (board[i][j] == BLACK70_WHITE30) {
                std::cout << ANSI_DARK_GRAY << "70" << ANSI_RESET << ANSI_GREEN_BG << " ";
            } else if (board[i][j] == BLACK90_WHITE10) {
                std::cout << ANSI_BLACK << "90" << ANSI_RESET << ANSI_GREEN_BG << " ";
            } else {
                std::cout << "  ";
            }
            std::cout << ANSI_RESET;
        }
        std::cout << std::endl;
    }
}

int main()
{
    Board board;
    board.Init();


    // プレイヤーの設定
    std::string players[2] = {"BLACK", "WHITE"};
    int currentPlayer = 0;
    int currentStone = 0;
    int currentState = CONTINUE;

    while (currentState == CONTINUE) {
        // 盤面の表示
        displayBoard(board.BoardState);

        // プレイヤーの入力
        std::string Cmd;
        std::cout << "Player " << (currentPlayer + 1) << " (" << players[currentPlayer] << "), enter command Move or Judge: ";
        std::cin >> Cmd;
        if(Cmd == "Move"){
            bool isMoved = false;
            while(isMoved == false){
                int row, col;
                std::cout << "Player " << (currentPlayer + 1) << " (" << players[currentPlayer] << "), enter row and column: ";
                std::cin >> row >> col;

                // 石を置く
                if (board.MoveDisk(row, col, currentStone)) {
                    // 次のプレイヤーに交代
                    currentPlayer = 1 - currentPlayer;
                    isMoved = true;
                } else {
                    std::cout << "Invalid move. Try again." << std::endl;
                }
            }
        }
        else if(Cmd == "Judge"){
            currentState = board.Judge();
            
            currentPlayer = 1 - currentPlayer;
        }
        else{
            std::cout << "Invalid command. Try again." << std::endl;
        }
    }

    return 0;
}