#include <iostream>
#define N 10

using namespace std;

int main(){
    int a[N] = {8, 5, 6, 7, 10, 5, 9, 6, 3, 8};
    float sum = 0.0;
    int minimum, maximum = a[0];
    cout << "Visu studentu pazymiai: " << endl;
    for (int i = 0; i < N; i++){
        cout << a[i] << " ";
        sum += a[i];
        if (minimum > a[i]) minimum = a[i];
        if (maximum < a[i]) maximum = a[i];
    };
    float vid = sum / N;
    cout << endl << "Suma: " << sum << endl;
    cout << "Vidurkis: " << vid << endl;
    cout << "Pazymiai didesni uz vidurki: " << endl;
    int counter = 0;
    for (int i = 0; i < N; i++){
        if (a[i] > vid){
            cout << a[i] << " ";
            counter++;
        }
    };
    cout << endl << "Pazymiu didesniu uz vidurki skaicius: " << counter << endl;
    cout << "Minimumas: " << minimum << endl;
    cout << "Maksimumas: " << maximum << endl;
    return 0;
}
