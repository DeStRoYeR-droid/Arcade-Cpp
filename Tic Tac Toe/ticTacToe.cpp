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
        char winner() const;
        bool winState() const;
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
char TicTacToe::winner() const{
    // Short circuit
    if (this->moves < 5) return ' ';

    // Checking the rows
    for (int i = 0; i < 3; i++){
        if (this->board[i][0] == ' ') continue;
        if (this->board[i][0] ==  this->board[i][1] && this->board[i][1] ==  this->board[i][2]) return this->board[i][0];
    }
    // cout << "Win did not happen via row" << endl;

    // Checking the columns
    for (int i = 0; i < 3; i++){
        if (this->board[0][i] == ' ') continue;
        if (this->board[0][i] ==  this->board[1][i] && this->board[1][i] ==  this->board[2][i]) return this->board[0][i];
    }
    // cout << "Win did not happen via column" << endl;

    // Checking the diagonals
    if (this->board[1][1] != ' '){
        if (this->board[0][0] == this->board[1][1] && this->board[2][2] == this->board[1][1]) return this->board[1][1];
        // cout << "Win did not happen via positive diagonal" << endl;

        if (this->board[2][0] == this->board[1][1] && this->board[2][0] == this->board[1][1]) return this->board[1][1];
        // cout << "Win did not happen via negative diagonal" << endl;    
    }

    return ' ';
}
bool TicTacToe::winState() const{
    char winningChar = this->winner();

    if (winningChar == ' ') return false;
    return true;
}

int main(){
    TicTacToe board;

    return 0;
}