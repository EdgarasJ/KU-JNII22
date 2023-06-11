/*
Author: Edgaras Jurevicius
Date: 2022-11-08
*/

#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int[], int);
void sharedOutput(int[], int, void(int[], int, bool), bool);
void copyArray(int[], int[], int);
void binaryInsertionSort(int[], int, bool);
void shakerSort(int[], int, bool);
void swapElements(int[], int, int);

int main(){
    int originalArr[] = {5, 2, 4, 6, 1, 3, -34, 0, -5, 130, -33, 0, 5, 70, 34, -93, 123, 4, 85, 5};
    int sizeArr = sizeof(originalArr) / sizeof(originalArr[0]);
    bool selected = false;
    bool showSteps = false;
    char selection;
    // menu ciklas
    while (!selected){
        cout << "Do you want to see sorting steps?(Y/N)" << endl;
        cin >> selection;
        switch (selection){
            case 'y': case 'Y':
                selected = true;
                showSteps = true;
                break;
            case 'n': case 'N':
                selected = true;
                showSteps = false;
                break;
            default:
                cout << "Error: unknown command '" << selection << "'." << endl;
        }
    }
    // naujas masyvas, kad nusugadinti orginalaus masyvo duomenu
    int unsortedArr[sizeArr];
    copyArray(originalArr, unsortedArr, sizeArr);
    sharedOutput(unsortedArr, sizeArr, &binaryInsertionSort, showSteps);
    copyArray(originalArr, unsortedArr, sizeArr);
    sharedOutput(unsortedArr, sizeArr, &shakerSort, showSteps);

    return 0;
}

//bendras isvedimas
void sharedOutput(int arr[], int sizeArr, void (*func)(int[], int, bool), bool showSteps){
    cout << "Unsorted array: " << endl;
    printArray(arr, sizeArr);
    func(arr, sizeArr, showSteps);
    cout << endl << "Sorted array: " << endl;
    printArray(arr, sizeArr);
    cout << endl;
}

// masyvo spausdinimas eiluteje
void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << setw(5) << right << arr[i] << " ";
    }
    cout << endl;
}

// masyvo kopijavimas
void copyArray(int sourceArr[], int destArr[], int sizeArr){
    for (int i = 0; i < sizeArr; i++){
        destArr[i] = sourceArr[i];
    }
}

// binarinis iterpimas
void binaryInsertionSort(int arr[], int sizeArr, bool showSteps){
    cout << "Binary insertion Sort: " << endl;
    int middle, low, high, val;
    for (int i = 1; i < sizeArr; i++){
        val = arr[i];
        low = 0;
        high = i;
        while (low < high){
            middle = (low + high) / 2;
            if (arr[middle] <= val) {
                low = middle + 1;
            } else {
                high = middle;
            }
        }
        for (int j = i; j > high; j--){
            arr[j] = arr[j-1];
        }
        arr[high] = val;
        if (showSteps) printArray(arr, sizeArr);
    }
}

//elementu sukeitimas vietomis
void swapElements(int arr[], int index1, int index2){
    int value = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = value;
}

// rusiavimas patobulintu burbulo metodu (shaker sort)
void shakerSort(int arr[], int sizeArr, bool showSteps){
    cout << "Shaker sort: " << endl;
    bool swapped;
    int value;
    int low = 0;
    int high = sizeArr;
    while (true) {
        //perejimas i viena puse
        swapped = false;
        for (int i = low; i < high - 1; i++){
            if (arr[i] > arr[i + 1]){
              swapElements(arr, i, i + 1);
              swapped = true;
            }
        }
        if (showSteps) printArray(arr, sizeArr);
        if (!swapped) break; // isejimas is pagrindinio while loop
        //perejimas i kita puse
        swapped = false;
        for (int i = high - 2; i >= low; i--){
            if (arr[i] > arr[i + 1]){
              swapElements(arr, i, i + 1);
              swapped = true;
            }
        }
        //reziu sutraukimas nes maziausias ir didziausias elementas jau yra nusede krastuose
        low++;
        high--;
        if (showSteps) printArray(arr, sizeArr);
        if (!swapped) break; // isejimas is pagrindinio while loop
    }
}
