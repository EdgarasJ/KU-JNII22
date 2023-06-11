#include <iostream>
#include <iomanip>

using namespace std;

int main (){
    int tableSize;
    cout << "Input a number: ";
    cin >> tableSize;

    for (int i = 1; i <= tableSize; i++) {
        for (int k = 1; k <= tableSize; k++) {
            cout << setfill(' ') << setw(6) << i * k;
        }
        cout << endl;
    }

    return 0;
}
