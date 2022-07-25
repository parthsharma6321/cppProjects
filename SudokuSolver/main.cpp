#include <bits/stdc++.h>
using namespace std;

class SudokuSolver{
    static const int N = 9;
    int board[N][N];
public:
    SudokuSolver(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                board[i][j] = 0;
            }
        }
    }

    bool allowed(int row, int col, int k){
        bool okRow = 1, okCol = 1, okBox = 1;
        for(int c = 0; c < N; c++){
            if(board[row][c] == k){
                okRow = 0;
            }
        }
        for(int r = 0; r < N; r++){
            if(board[r][col] == k){
                okCol = 0;
            }
        }

        int boxRow = row - row % 3, boxCol = col - col % 3;
        for(int i = boxRow; i < boxRow + 3; i++){
            for(int j = boxCol; j < boxCol + 3; j++){
                if(board[i][j] == k){
                    okBox = 0;
                }
            }
        }

        return okBox and okRow and okCol;
    }

    bool solvable(int row = 0, int col = 0){
        if(row == N){
            return true;
        }
        if(board[row][col]){
            return solvable(row + (col == N - 1), (col + 1) % N);
        }
        for(int k = 1; k <= 9; k++){
            if(allowed(row, col, k)){
                board[row][col] = k;
                if(solvable(row + (col == N - 1), (col + 1) % N)) return true;
                board[row][col] = 0;
            }
        }
        return false;
    }

    void printBoard(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void Run(){
        inputBoard();
        if(solvable()){
            cout << "\nSolution Found\n\n";
            printBoard();
        }
        else{
            cout << "No Solution Exists\n";
        }
    }

    void inputBoard(){
        cout << "Enter Board Row Wise:\n";
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> board[i][j];
            }
        }
    }

};

int main(){
    bool more = 1;
    do{

        SudokuSolver currentInstance;
        currentInstance.Run();
        cout << "Continue ?(0 / 1) ";
        int choice;
        cin >> choice;
        more = choice;

    }while(more);
    return 0;
}