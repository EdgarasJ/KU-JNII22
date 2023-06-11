#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int[], int);
void bubbleSort(int[], int);

int main(){
    int arr[] = {5, 2, 4, 6, 1, 3};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, sizeArr); // isvedama orginali masyvo busena
    bubbleSort(arr, sizeArr);
    return 0;
}

// masyvo spausdinimas eiluteje
void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << setw(5) << right << arr[i] << " ";
    }
    cout << endl;
}

// rusiavimas burbulo metodu
void bubbleSort(int arr[], int sizeArr){
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
        printArray(arr, sizeArr); // masyvo elementu isvedimas i ekrana po vieno masyvo perejimo
    }
}
