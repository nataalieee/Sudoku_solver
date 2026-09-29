#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int board[9][9];

void printBoard() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------\n";
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}


bool isValid(int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) return false;
        if (board[i][col] == val) return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == val) {
                return false;
            }
        }
    }

    return true;
}

bool solve() {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }

    if (!isEmpty) {
        return true;
    }

    for (int val = 1; val <= 9; val++) {
        if (isValid(row, col, val)) {
            board[row][col] = val;

            if (solve()) {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

bool readGrid(ifstream &fin) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!(fin >> board[i][j])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ifstream fin("sudoku.txt");

    if (!fin.is_open()) {
        cout << "Eroare la deschiderea fisierului sudoku.txt!" << endl;
        return 1;
    }

    int nrSudoku;
    fin >> nrSudoku;

    for (int k = 1; k <= nrSudoku; k++) {
        if (!readGrid(fin)) {
            cout << "\nNu mai sunt suficiente puzzle-uri in fisier.\n";
            break;
        }

        cout << "\n--- Sudoku #" << k << " ---\n";
        cout << "Tabla initiala:\n";
        printBoard();

        if (solve()) {
            cout << "\nSolutie:\n";
            printBoard();
        } else {
            cout << "\nNu s-a putut gasi o solutie!\n";
        }
    }

    fin.close();
    return 0;
}