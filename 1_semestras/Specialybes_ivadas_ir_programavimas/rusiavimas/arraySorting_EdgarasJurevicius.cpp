/*
Author: Edgaras Jurevičius
Date: 2022-10-26
*/

#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int[], int);
void bubbleSort(int[], int, bool);
void sharedOutput(int[], int, void(int[], int, bool), bool);
void copyArray(int[], int[], int);
void insertionSort(int[], int, bool);
void selectionSort(int[], int, bool);
void numberingSort(int[], int, bool);

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
    sharedOutput(unsortedArr, sizeArr, &insertionSort, showSteps);
    copyArray(originalArr, unsortedArr, sizeArr);
    sharedOutput(unsortedArr, sizeArr, &selectionSort, showSteps);
    copyArray(originalArr, unsortedArr, sizeArr);
    sharedOutput(unsortedArr, sizeArr, &bubbleSort, showSteps);
    copyArray(originalArr, unsortedArr, sizeArr);
    sharedOutput(unsortedArr, sizeArr, &numberingSort, showSteps);

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

// rusiavimas burbulo metodu
void bubbleSort(int arr[], int sizeArr, bool showSteps){
    cout << "Bubble sort:" << endl;
    int index1, index2, value;
    bool sorted = false;
    int changeCount;
    while (!sorted) {
        changeCount = 0; // pakeitimo skaitliuko reset
        for (index1 = 1; index1 < sizeArr; index1++){
            index2 = index1 - 1;
            value = arr[index1];
            // sukeiciam vietomis jei pirmas didesnis uz antra
            if (value < arr[index2]) {
                arr[index1] = arr[index2];
                arr[index2] = value;
                changeCount++; // padidinam skaitliuka nes ivyko pakeitimas
            }
        }
        if (changeCount == 0) sorted = true; // jei pakeitimu skaitliukas lygus nuliui, tai rusiavimas baigtas
        if (showSteps) printArray(arr, sizeArr); // masyvo elementu isvedimas i ekrana po vieno masyvo perejimo
    }
}

// rusiavimas iterpimu
void insertionSort(int arr[], int sizeArr, bool showSteps){
    cout << "Insertion sort:" << endl;
    int index1, index2, value;
    for (index1 = 1; index1 < sizeArr; index1++){
        index2 = index1 - 1;
        value = arr[index1];
        while (index2 >= 0 && arr[index2] > value){
            arr[index2 + 1] = arr[index2]; // elementu postumis i desine
            index2--;
        }
        arr[index2 + 1] = value; // elemento iterpimas i vieta
        if (showSteps) printArray(arr, sizeArr); // masyvo elementu isvedimas i ekrana po vieno elemento iterpimo
    }
}

// rusiavimas isrinkimo metodu
void selectionSort(int arr[], int sizeArr, bool showSteps){
    cout << "Selection sort:" << endl;
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
        if (showSteps) printArray(arr, sizeArr); // masyvo elementu isvedimas i ekrana po vieno masyvo perejimo
    }
}

// rusiavimas numeravimo metodu
void numberingSort(int arr[], int sizeArr, bool showSteps){
    cout << "Numbering sort:" << endl;
    int sortedArr[sizeArr] = {0};
    int minCount, sameCount;
    for (int index1 = 0; index1 < sizeArr; index1++){
        minCount = 0;
        sameCount = 0;
        for (int index2 = 0; index2 < sizeArr; index2++){
            if (arr[index1] > arr[index2]) minCount++;
            if (arr[index1] == arr[index2]) sameCount++;
        }
        // idedame elementa i reikiama vieta naujame masyve
        for (int i = 0; i < sameCount; i++){
            sortedArr[minCount + i] = arr[index1];
        }
        if (showSteps) printArray(sortedArr, sizeArr); // masyvo elementu isvedimas i ekrana po vieno masyvo perejimo
    }
    copyArray(sortedArr, arr, sizeArr);
}
