#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int[], int);
void selectionSort(int[], int);

int main(){
    int arr[] = {5, 2, 4, 6, 1, 3};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, sizeArr); // isvedama orginali masyvo busena
    selectionSort(arr, sizeArr);
    return 0;
}

// masyvo spausdinimas eiluteje
void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << setw(5) << right << arr[i] << " ";
    }
    cout << endl;
}

// rusiavimas isrinkimo metodu
void selectionSort(int arr[], int sizeArr){
    int index1, index2, value, minIndex;
    for (index1 = 0; index1 < sizeArr - 1; index1++){
        minIndex = index1;
        for (index2 = index1 + 1; index2 < sizeArr; index2++){
            if (arr[minIndex] > arr[index2]) minIndex = index2;
        }
        // sukeiciame elementus vietomis, jei maziausias elementas dar nera reikiamoje vietoje
        if (minIndex != index1){
            value = arr[index1];
            arr[index1] = arr[minIndex];
            arr[minIndex] = value;
        }
        printArray(arr, sizeArr); // masyvo elementu isvedimas i ekrana po vieno masyvo perejimo
    }
}
