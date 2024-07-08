#include <iostream>
#include <vector>
#include <array>
#include "board.cpp"

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
        std::cout << i << "  ";
    }
    std::cout << std::endl;

    // 行番号と盤面の表示
    for (int i = 0; i < WIDTH; i++) {
        std::cout << i << " ";
        for (int j = 0; j < HEIGHT; j++) {
            //std::cout << ANSI_GREEN_BG;
            if (board[i][j] == BLACK10_WHITE90) {
                //std::cout << ANSI_WHITE << "10" << ANSI_RESET << ANSI_GREEN_BG << " ";
                std::cout << "10 ";
            } else if (board[i][j] == BLACK30_WHITE70) {
                //std::cout << ANSI_LIGHT_GRAY << "30" << ANSI_RESET << ANSI_GREEN_BG << " ";
                std::cout << "30 ";
            } else if (board[i][j] == BLACK70_WHITE30) {
                //std::cout << ANSI_DARK_GRAY << "70" << ANSI_RESET << ANSI_GREEN_BG << " ";
                std::cout << "70 ";
            } else if (board[i][j] == BLACK90_WHITE10) {
                //std::cout << ANSI_BLACK << "90" << ANSI_RESET << ANSI_GREEN_BG << " ";
                std::cout << "90 ";
            } else {
                std::cout << "○  ";
            }
            //std::cout << ANSI_RESET;
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    Board board;
    board.Init();


    // プレイヤーの設定
    std::string players[3] = {"NONE", "BLACK", "WHITE"};
    std::string stones[5] = {"NO_DISK", "BLACK10_WHITE90", "BLACK30_WHITE70", "BLACK70_WHITE30", "BLACK90_WHITE10"};
    int currentPlayer = BLACK;
    int currentStone[3] = {NONE, BLACK90_WHITE10, BLACK10_WHITE90};
    int currentState = CONTINUE;

    while (currentState == CONTINUE) {
        // 盤面の表示
        displayBoard(board.BoardState);

        // プレイヤーの入力
        std::string Cmd;
        std::cout << "Player " << currentPlayer << " (" << players[currentPlayer] << "), enter command Move " << stones[currentStone[currentPlayer]] << " or Judge: ";
        std::cin >> Cmd;
        if(Cmd == "Move"){
            bool isMoved = false;
            while(isMoved == false){
                int row, col;
                std::cout << "Player " << currentPlayer << " (" << players[currentPlayer] << "), enter row and column: ";
                
                while(true){
                    try{
                        std::cin >> row >> col;
                    }
                    catch(...){
                        std::cout << "Invalid Input. Try again." << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                        continue;
                    }

                    break;
                }

                // 石を置く
                if (board.MoveDisk(row, col, currentStone[currentPlayer])) {
                    // 次のプレイヤーに交代
                    if(currentPlayer == BLACK){
                        if(currentStone[currentPlayer] == BLACK90_WHITE10){
                            currentStone[currentPlayer] = BLACK70_WHITE30;
                        }
                        else{
                            currentStone[currentPlayer] = BLACK90_WHITE10;
                        }
                        currentPlayer = WHITE;
                    }
                    else{
                        if(currentStone[currentPlayer] == BLACK10_WHITE90){
                            currentStone[currentPlayer] = BLACK30_WHITE70;
                        }
                        else{
                            currentStone[currentPlayer] = BLACK10_WHITE90;
                        }
                        currentPlayer = BLACK;
                    }
                    isMoved = true;
                } else {
                    std::cout << "Invalid move. Try again." << std::endl;
                }
            }

        }
        else if(Cmd == "Judge"){
            currentState = board.Judge();

            if(currentPlayer == BLACK){
                currentPlayer = WHITE;
            }
            else{
                currentPlayer = BLACK;
            }
        }
        else{
            std::cout << "Invalid command. Try again." << std::endl;
        }
    }
    std::cout << "Player " << currentState << " (" << players[currentState] << ") WIN" << std::endl;
    return 0;
}