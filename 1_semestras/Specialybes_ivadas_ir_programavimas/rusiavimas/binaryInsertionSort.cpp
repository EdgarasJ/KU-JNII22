#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int[], int);
void insertionSort(int[], int);
int binarySearch(int[], int, int, int);
void binaryInsert(int[], int);
void copyArray(int[], int[], int);

int main(){
    int arr[] = {5, 2, 1, 3, -34, -5, 130, -33, 0, 5, 123, 43, 5};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    int unsortedArr[sizeArr];
    copyArray(arr, unsortedArr, sizeArr);
    printArray(unsortedArr, sizeArr);
    cout << "inSort binSearch: " << endl;
    insertionSort(unsortedArr, sizeArr);

    cout << "binInsert: " << endl;
    binaryInsert(arr, sizeArr);
    return 0;
}

// masyvo kopijavimas
void copyArray(int sourceArr[], int destArr[], int sizeArr){
    for (int i = 0; i < sizeArr; i++){
        destArr[i] = sourceArr[i];
    }
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
    int index1, index2, value, newLoc;
    for (index1 = 1; index1 < sizeArr; index1++){
        index2 = index1 - 1;
        value = arr[index1];
        newLoc = binarySearch(arr, value, 0, index2); // ieskom kur reiketu ideti
        //cout << "Loc: " << newLoc << endl;
        //cout << "Val: " << value << endl;
        while (index2 >= newLoc){
            arr[index2 + 1] = arr[index2]; // elementu postumis i desine
            index2--;
        }
        arr[index2 + 1] = value; // elemento iterpimas i vieta
        printArray(arr, sizeArr); // masyvo elementu isvedimas i ekrana po vieno elemento iterpimo
    }
}

// binarine paieska
int binarySearch(int arr[], int value, int lowBoundary, int highBoundary) {
    if (highBoundary <= lowBoundary) {
        if (value > arr[lowBoundary]) return lowBoundary + 1;
        return lowBoundary;
    }
    // ieskome vidurinio tasko
    int middle = (lowBoundary + highBoundary) / 2;
    if (value == arr[middle]) return middle + 1; // dedam salia tokio pacio skaiciaus
    if (value > arr[middle]) return binarySearch(arr, value, middle + 1, highBoundary); // ieskom vel tarp vidurio tasko ir aukstesnio rezio
    return binarySearch(arr, value, lowBoundary, middle - 1);// ieskom vel tarp zemesnio rezio ir vidurio tasko
}


// binary insertion
void binaryInsert(int arr[], int sizeArr){
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
        printArray(arr, sizeArr);
    }
}
