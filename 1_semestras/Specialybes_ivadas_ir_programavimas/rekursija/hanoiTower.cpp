/*
Author: Edgaras Jurevicius
Date: 2022-10-18
*/

#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

void hanoiTower(int[][3], int, int, int, int);
void buildPlane(int[][3]);
void printPlane(int[][3]);
void moveRing(int[][3], int, int, int);
int popRing(int[][3], int);
void pushRing(int[][3], int, int);
void clearScreen();

int MOVES = 0;
int ALLRINGS;

int main() {
    int numOfRings;
    cout << "Enter number of rings in Hanoi Tower: " << endl;
    cin >> numOfRings;
    ALLRINGS = numOfRings;
    int plane[numOfRings][3];
    buildPlane(plane);
    printPlane(plane);
    hanoiTower(plane, numOfRings, 0, 1, 2);
    cout << "Number of moves: " << MOVES;
    return 0;
}

// funkcija bokstu matricos inizilizacijai
void buildPlane(int plane[][3]){
    for (int i = 0; i < ALLRINGS; i++){
        plane[i][0] = i + 1;
        plane[i][1] = 0;
        plane[i][2] = 0;
    }
}

// funkcija ekrano isvalymui, kad atnaujinti bokstu matrica
void clearScreen()
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

// spausdinama bokstu matrica ir 0.5 secundes uzlaikomas rezultatas
// + matomas sprendimas vizualiai
// - uzlaikomi skaiciavimai, jauciasi su didesniais skaiciais
void printPlane(int plane[][3]){
    clearScreen();
    cout << endl << endl;
    for (int i = 0; i < ALLRINGS; i++){
        cout << " " << plane[i][0] << " " << plane[i][1] << " " << plane[i][2] << endl;
    }
    chrono::milliseconds dura(500);
    this_thread::sleep_for(dura);
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
