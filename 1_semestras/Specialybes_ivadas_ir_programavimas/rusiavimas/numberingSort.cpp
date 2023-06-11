#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int[], int);
void numberingSort(int[], int[], int);

int main(){
    int arr[] = {5, 2, 4, 6, 1, 3};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    int sortedArr[sizeArr] = {}; // naujas masyvas uzpildytas nuliais skirtas surusiuotoms reiksmems talpinti
    printArray(arr, sizeArr); // isvedama orginali masyvo busena
    numberingSort(arr, sortedArr, sizeArr);
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
void numberingSort(int arr[], int sortedArr[], int sizeArr){
    int index1, index2, minCount;
    for (index1 = 0; index1 < sizeArr; index1++){
        minCount = 0;
        for (index2 = 0; index2 < sizeArr; index2++){
            if (arr[index1] > arr[index2]) minCount++;
        }
        // idedame elementa i reikiama vieta naujame masyve
        sortedArr[minCount] = arr[index1];
        printArray(sortedArr, sizeArr); // masyvo elementu isvedimas i ekrana po vieno masyvo perejimo
    }
}
