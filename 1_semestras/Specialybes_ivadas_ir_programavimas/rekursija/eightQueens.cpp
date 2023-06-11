/*
Author: Edgaras Jurevicius
Date: 2022-10-18
*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Board {
private:
    char chessBoard[8][8];
    int solutionsCount;

    // pakeicia is juodo langelio i balta ir atvirksciai
    char changeChar(char c){
        char black = 0xFF;
        char white = 0xDB;
        if (c == black) return white;
        return black;
    }
public:
    // konstruktorius
    Board(){
        reformatBoard();
        solutionsCount = 0;
    }

    // lentos formatavimas, langeliai kur nera karalieniu
    void reformatBoard(){
        char cell = 0xFF;
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (chessBoard[i][j] != 'w') chessBoard[i][j] = cell;
                cell = changeChar(cell);
            }
            cell = changeChar(cell);
        }
    }

    // lentos spausdinimas
    void printBoard(){
        cout << endl;
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                cout << setfill(chessBoard[i][j]) << setw(2) << chessBoard[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    // langelio reiksmes grazinimas
    char getCell(int row, int col){
        return chessBoard[row][col];
    }


    // karalienes padejimas
    void putQueen(int row, int col){
        chessBoard[row][col] = 'w';
    }

    void removeQueen(int row, int col){
        char cell = 0xFF;
        chessBoard[row][col] = cell;
    }

    int getCount(){
        return solutionsCount;
    }

    void incCount(){
        solutionsCount++;
    }
};

bool canPlace(Board&, int, int);
bool solverEightQueens(Board&, int);

int main(){
    Board cBoard;
    solverEightQueens(cBoard, 0);
    cout << "Solutions Count: " << cBoard.getCount();
    return 0;
}

// tikrinama ar toje vietoje galima padeti karaliene
bool canPlace(Board& brd, int rowId, int colId){
    // patikrinti eulute ir stulpeli
    int constDiag1 = rowId + colId; // konstanta diagonalei
    int constDiag2 = rowId - colId + 7;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            // naudojama j nes vidinis ciklas tikrins 8 kartus ir 1 kart isorinis jei karaliene yra eileje ar stulpelyje
            if (brd.getCell(rowId, j) == 'w') return false; // ar kita karaliene yra padeta eileje
            if (brd.getCell(j, colId) == 'w') return false; // ar kita karaliene yra padeta stulpelyje
            // patikrina diagonales
            if (brd.getCell(i, j) == 'w' && (i - j + 7 == constDiag2 || i + j == constDiag1)) return false;
        }

    }
    return true; // jei praejo visas patikras
}

// ieskom sprendimo
bool solverEightQueens(Board& brd, int col){
    // sprendimas rastas
    if (col == 8){
        brd.incCount();
        cout << "Nr.: " << brd.getCount();
        brd.reformatBoard();
        brd.printBoard();
        return true;
    }
    bool solved = false;
    // ieskom ar galim padeti siame stulpelyje
    for (int i = 0; i < 8; i++){
        if(canPlace(brd, i, col)){
            brd.putQueen(i, col); // padedam karaliene
            solved = solverEightQueens(brd, col + 1) || solved; //ieskojimas kitam stulpeliui
            brd.removeQueen(i, col); // pasalinam karaliene (grizimas atgal)
        }
    }
    return solved;
}
