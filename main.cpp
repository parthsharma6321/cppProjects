#include<bits/stdc++.h>
using namespace std;

class TicTacToe{
    private:
        int boardSize, marked, all;
        vector<vector<int>> board;

    public:
        TicTacToe(int n){
            boardSize = n;
            marked = 0;
            all = n * n;
            board.resize(n);
            for(int i = 0; i < n; i++){
                board[i].resize(n);
            }
        }

        void printBoard(){
            cout << "\n";
            for(int i = 0; i < boardSize; i++){
                for(int j = 0; j < boardSize; j++){
                    cout << " " << board[i][j] << " ";
                }
                cout << "\n\n";
            }
        }

        bool invalidCoordinates(int row, int col){
            if(row >= 0 and row < boardSize and col >= 0 and col < boardSize and board[row][col] == 0){
                return false;
            }
            cout << "Invalid, Try Again\n";
            return true;
        }

        int updateBoard(int player, int row, int col){
            board[row][col] = 1 + (player == 2);
            bool foundRow = 1, foundCol = 1, foundDiag = 1, foundRevDiag = 1;
            for(int i = 0; i < boardSize; i++){
                if(board[row][i] != player){
                    foundRow = 0;
                }
                if(board[i][col] != player){
                    foundCol = 0;
                }
                if(board[i][i] != player){
                    foundDiag = 0;
                }
                if(board[i][boardSize - 1 - i] != player){
                    foundRevDiag = 0;
                }
            }
            if(foundRow || foundCol || foundDiag || foundRevDiag){
                return player;
            }
            return 0;
        }


        void play(int player = 1){
            cout << "Turn: Player " << player << "\n";
            unsigned int row, col;
            do{
                cout << "Enter Row: ";
                cin >> row;
                cout << "Enter Col: ";
                cin >> col;
            } while(invalidCoordinates(row, col) == true);

            if(updateBoard(player, row, col) == player){
                cout << "Player " << player << " Won\n";
            }
            else if(marked == all){
                cout << "Drawn\n";
            }
            else{
                marked++;
                cout << "Current Board\n";
                printBoard();
                play(player == 1 ? 2 : 1);
            }
        }

};

int main(){

    int boardSize = -1;
    /* Local Function to test legal board size*/
    auto illegal = [](int x) -> bool{
        if(x < 3 or x > 10){
            cout << "Illegal, Try again\n";
            return true;
        }
        return false;
    };
    do{
        cout << "Enter Board Size: (3 - 10): ";
        cin >> boardSize;
    } while(illegal(boardSize) == true);

    TicTacToe obj(boardSize);
    obj.printBoard();
    obj.play();

    return 0;
}