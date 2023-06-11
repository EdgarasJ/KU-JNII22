/*
Author: Edgaras Jurevicius
Date: 2022-10-18
*/

#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
#include <vector>

using namespace std;

// klase naudojama eightQueens;
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


void findFactorial();
long int factorial(int);
void findPower();
double Power(double, int);
long int binomialCoeffC(int, int);
void findBinomial();
unsigned int fibonacci(unsigned int);
void findFibonacci();
double sumTotal();
void findSum();
void hanoiTower(int[][3], int, int, int, int);
void buildPlane(int[][3]);
void printPlane(int[][3]);
void moveRing(int[][3], int, int, int);
int popRing(int[][3], int);
void pushRing(int[][3], int, int);
void startHanoi();
bool canPlace(Board&, int, int);
bool solverEightQueens(Board&, int);
void startQueens();

// naudojama Hanoi Tower galvosukyje
int MOVES = 0;
int ALLRINGS;

int main () {
    cout << "Please choose operation:" << endl;
    cout << "Any Other Number to Exit Program" << endl;
    cout << "1 Find number factorial" << endl;
    cout << "2 Find Power of number" << endl;
    cout << "3 Find Binomial" << endl;
    cout << "4 Find Fibonacci member" << endl;
    cout << "5 Sum of positive numbers" << endl;
    cout << "6 Hanoi Tower puzzle simulation" << endl;
    cout << "7 Eight Queens puzzle" << endl;
    cout << "Operation number: " << endl;
    int choice;
    cin >> choice;
    switch (choice){
        case 1:
            findFactorial();
            break;
        case 2:
            findPower();
            break;
        case 3:
            findBinomial();
            break;
        case 4:
            findFibonacci();
            break;
        case 5:
            findSum();
            break;
        case 6:
            startHanoi();
            break;
        case 7:
            startQueens();
            break;
    }
    return 0;
}

// Faktorialo skaiciavimo pasirinkimo vykdymas
void findFactorial(){
    int num;
    cout << "Input number: ";
    cin >> num;
    cout << "Factorial (" << num << "): " << factorial(num);
}

// Skaiciuojamas skaiciaus faktorialas
long int factorial(int num) {
    if (num == 0) return 1; // graziname vieneta jei skaiciuojam nulio faktoriala.
    return num * factorial(num - 1);
}

// pasirinkimo power vykdymas
void findPower() {
    double number;
    int power;
    cout << "Input a base: ";
    cin >> number;
    cout << "Input a power to raise to: ";
    cin >> power;
    cout << "The number " << number << " raised by power of " << power << " is: " << Power(number, power);
}

// skaiciaus kelimas laipsniu
double Power(double number, int power) {
    if (power == 0) return 1; // skaicius pakeltas nuliniu laipsniu yra vienetas
    if (power < 0) return 1.0 / Power(number, abs(power)); // jei keliama neigiamu laipsniu
    return number * Power(number, power - 1); // kelimas teigiamu laipsniu
}

// vykdomas binomial pasirinkimas
void findBinomial() {
    int n, m;
    cout << "Input number of elements in a set (n): ";
    cin >> n;
    cout << "Input how much you want to choose from a set (m): ";
    cin >> m;
    if (m > n) {
        cout << "Error. You can't choose more elements than number of elements existing in set.";
        return;
    }
    cout << "Binomial coefficient C(m,n) equals to: " << binomialCoeffC(m, n);
}

// Skaiciuojamas niutono binomas
long int binomialCoeffC(int m, int n) {
    if (m == 0 || m == n) return 1; // graziname 1 jei imam 0 arba visus elementus is aibes.
    if (m > 0 && m < n) return binomialCoeffC(m, n - 1) + binomialCoeffC(m - 1, n - 1);
}

// fibonacio sekos nario pasirinkimo vydymas
void findFibonacci() {
    unsigned int place;
    cout << "Input a place of number in Fibonacci sequance: ";
    cin >> place;
    cout << "Number in Fibonacci sequence at a place: " << place << " equals to: " << fibonacci(place);
}

// fibonachio sekos numerio nurodytame indekse radimas
unsigned int fibonacci(unsigned int index) {
    if (index == 1 || index == 2) return 1; // pirmos dvi vietos vienetai
    if (index > 2) return fibonacci(index - 1) + fibonacci(index - 2);
    return 0;
}

// sumos pasirinkimo vykdymas
void findSum() {
    cout << "Ivedinekite skaicius is eiles. Neigiamas skaicius - ivedimo pabaiga." << endl;
    double sum = sumTotal(); // tarpinis kintamasis, kad parametru ivedimas neisiterptu i atsakymo isvedima
    cout << "Teigiamu skaiciu suma: " << sum << endl;
}

//skaiciuojama ivestu teigiamu skaicu suma.
double sumTotal() {
    double num;
    cin >> num;
    if (num < 0) return 0; // skaicius neigiamas todel i suma neieina ir nutraukia rekursini funkcijos kvietima.
    return num + sumTotal();
}

// hanoi Tower pasirinkimo vykdymas
void startHanoi() {
    int numOfRings;
    cout << "Enter number of rings in Hanoi Tower (use small numbers as big numbers will take a lot of time): " << endl;
    cin >> numOfRings;
    ALLRINGS = numOfRings;
    int plane[numOfRings][3];
    buildPlane(plane);
    printPlane(plane);
    hanoiTower(plane, numOfRings, 0, 1, 2);
    cout << "Number of moves: " << MOVES;
}

// funkcija bokstu matricos inizilizacijai
void buildPlane(int plane[][3]){
    for (int i = 0; i < ALLRINGS; i++){
        plane[i][0] = i + 1;
        plane[i][1] = 0;
        plane[i][2] = 0;
    }
}

// spausdinama bokstu matrica
void printPlane(int plane[][3]){
    cout << endl << endl;
    for (int i = 0; i < ALLRINGS; i++){
        cout << " " << plane[i][0] << " " << plane[i][1] << " " << plane[i][2] << endl << endl;
    }
}

// funkcija ziedo perkelimui (realiai galima jos turini perkelti i hanoiTower funkcija, bet liko nes pradzioje buvo kita realizacija)
void moveRing(int plane[][3], int sourceTowerIndex, int targetTowerIndex){
    pushRing(plane, targetTowerIndex, popRing(plane, sourceTowerIndex));
}

// grazina boksto virsutini zieda
int popRing(int plane[][3], int towerIndex){
    int value = 0;
    for (int i = 0; i < ALLRINGS; i++){
        if (plane[i][towerIndex] != 0){
            value = plane[i][towerIndex];
            plane[i][towerIndex] = 0;
            break;
        }
    }
    return value;
}

// ideda zieda i boksto virsu
void pushRing(int plane[][3], int towerIndex, int value){
    for (int i = ALLRINGS - 1; i >= 0; i--){
        if (plane[i][towerIndex] == 0){
            plane[i][towerIndex] = value;
            break;
        }
    }
}

// rekursivi funkcija hanoi tower skaiciavimui
void hanoiTower(int plane[][3], int numOfRings, int sourceTowerIndex, int helpTowerIndex, int targetTowerIndex){
    if (numOfRings > 0) { // vykdom jei yra bent vienas ziedas kuri reikia pajudinti
        hanoiTower(plane, numOfRings - 1, sourceTowerIndex, targetTowerIndex, helpTowerIndex);
        moveRing(plane, sourceTowerIndex, targetTowerIndex);
        MOVES++;
        printPlane(plane);
        hanoiTower(plane, numOfRings - 1, helpTowerIndex, sourceTowerIndex, targetTowerIndex);
    }
}

// eight queens pasirinkimo vykdymas
void startQueens(){
    Board cBoard;
    solverEightQueens(cBoard, 0);
    cout << "Solutions Count: " << cBoard.getCount();
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
