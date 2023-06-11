#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int[], int);
void shakerSort(int[], int);
void swapElements(int[], int, int);

int main(){
    int arr[] = {5, 2, 4, 6, 1, 3};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, sizeArr); // isvedama orginali masyvo busena
    shakerSort(arr, sizeArr);
    return 0;
}

// masyvo spausdinimas eiluteje
void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << setw(5) << right << arr[i] << " ";
    }
    cout << endl;
}

//elementu sukeitimas vietomis
void swapElements(int arr[], int index1, int index2){
    int value = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = value;
}

// rusiavimas patobulintu burbulo metodu (shaker sort)
void shakerSort(int arr[], int sizeArr){
    bool swapped;
    int value;
    while (true) {
        //perejimas i viena puse
        swapped = false;
        for (int i = 0; i < sizeArr - 1; i++){
            if (arr[i] > arr[i + 1]){
              swapElements(arr, i, i + 1);
              swapped = true;
            }
        }
        printArray(arr, sizeArr);
        if (!swapped) break; // isejimas is pagrindinio while loop
        //perejimas i kita puse
        swapped = false;
        for (int i = sizeArr - 2; i >= 0; i--){
            if (arr[i] > arr[i + 1]){
              swapElements(arr, i, i + 1);
              swapped = true;
            }
        }
        printArray(arr, sizeArr);
        if (!swapped) break; // isejimas is pagrindinio while loop
    }
}
