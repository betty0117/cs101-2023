#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    TicTacToe() : board(9, " ") {}

    void run() {
        cout << "-- Tic Tac Toe --CSIE@CGU "<<endl;
        cout<<"Player 1 (X) - Player 2 (O)"<<endl;
        cout<<endl;
        printBoard();
        while (!checkWin() && !checkDraw()) {
            int move = getPlayerMove();
            makeMove(move);
            printBoard();
            switchPlayer();
        }
        if (checkWin()) {
        	cout<<endl;
            cout << "==> Player " << currentPlayer << " win " << endl;
        } else {
            cout<<endl;
            cout << "==> Game draw" << endl;
        }
        
        

    }

private:
    vector<string> board;
    int currentPlayer = 1;

    void printBoard() const {
        cout << " " << board[0] << " █ " << board[1] << " █ " << board[2] << " " << endl;
        
        cout << "███████████" << endl;
        
        cout << " " << board[3] << " █ " << board[4] << " █ " << board[5] << " " << endl;
        
        cout << "███████████" << endl;
        
        cout << " " << board[6] << " █ " << board[7] << " █ " << board[8] << " " << endl;
    }

    int getPlayerMove() const {
        int move;
        do {
            cout << "Player " << currentPlayer << ", 請輸入(1-9)的數字 : ";
            cin >> move;
        } while (move < 1 || move > 9 || board[move - 1] != " ");
        return move - 1;
    }

    void makeMove(int move) {
        board[move] = (currentPlayer == 1) ? " X" : " O";
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    bool checkWin() const {
        for (int i = 0; i < 3; i++) {
            if (board[i] != " " && board[i] == board[i+3] && board[i] == board[i+6]) {
                return true; // vertical win
            }
            if (board[3*i] != " " && board[3*i] == board[3*i+1] && board[3*i] == board[3*i+2]) {
                return true; // horizontal win
            }
        }
        if (board[0] != " " && board[0] == board[4] && board[0] == board[8]) {
            return true; // diagonal win
        }
        if (board[2] != " " && board[2] == board[4] && board[2] == board[6]) {
            return true; // diagonal win
        }
        return false;
    }

    bool checkDraw() const {
        for (const auto& cell : board) {
            if (cell == " ") {
                return false; // board not full
            }
        }
        return true; // board full and no winner
    }
};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}
