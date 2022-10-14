#include <iostream>
#include <exception>

using namespace std;

class InvalidMoveError : public runtime_error{
    public:
        InvalidMoveError(const string& what = "Move already played on that position") : runtime_error(what){}
};

class TicTacToe{
    private:
        char** board;
        char* validMoves;
        int moves;
    
    public:
        TicTacToe(char playerOne = 'O', char playerTwo = 'X'){
            this->board = new char*[3];
            for (int i = 0; i < 3; i++){
                board[i] = new char[3];
                board[i][0] = board[i][1] = board[i][2] = ' ';
            }

            this->validMoves = new char[2];
            this->validMoves[0] = playerOne;
            this->validMoves[1] = playerTwo;

            this->moves = 0;
        }

        void print_board() const;
        void makeMove(const int& position);
};

void TicTacToe::print_board() const{
    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){
            if (j == 2){
                cout << board[i][j] << endl;
            }
            else{
                cout << board[i][j] << " |";
            }
        }

        if (i != 2){
            cout << "---------" << endl;
        }
    }
}
void TicTacToe::makeMove(const int& position){
    int x = position / 3;
    int y = position % 3;

    if (board[x][y] != ' ') throw InvalidMoveError();
    else { 
        board[x][y] = this->validMoves[this->moves % 2];
        this->moves++;    
    }
}

int main(){
    TicTacToe board;
    board.print_board();
    board.makeMove(0);
    board.makeMove(2);
    board.print_board();

    return 0;
}