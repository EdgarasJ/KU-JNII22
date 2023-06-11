#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int[], int);
void insertionSort(int[], int);

int main(){
    int arr[] = {5, 2, 4, 6, 1, 3};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, sizeArr);
    insertionSort(arr, sizeArr);
    return 0;
}

// masyvo spausdinimas eiluteje
void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << setw(5) << right << arr[i] << " ";
    }
    cout << endl;
}

// rusiavimas iterpimu
void insertionSort(int arr[], int sizeArr){
    int index1, index2, value;
    for (index1 = 1; index1 < sizeArr; index1++){
        index2 = index1 - 1;
        value = arr[index1];
        while (index2 >= 0 && arr[index2] > value){
            arr[index2 + 1] = arr[index2]; // elementu postumis i desine
            index2--;
        }
        arr[index2 + 1] = value; // elemento iterpimas i vieta
        printArray(arr, sizeArr); // masyvo elementu isvedimas i ekrana po vieno elemento iterpimo
    }
}
