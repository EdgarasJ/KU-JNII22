// OHOHO + AHAHA == AHAHAH
// URANUS + VENUS == EUROPA
// kto + kot == tok

//ND: SEND + MORE == MONEY

#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int ohoho, ahaha, ahahah;
    for (int a = 0; a < 10; a++){
        for (int h = 0; h < 10; h++){
            for (int o = 0; o < 10; o++){
                ohoho = o*10000+h*1000+o*100+h*10+o;
                ahaha = a*10000+h*1000+a*100+h*10+a;
                ahahah = a*100000+h*10000+a*1000+h*100+a*10+h;
                if (ohoho+ahaha == ahahah && ahahah != 0) {
                    cout << "a = " << a << endl << "h = " << h << endl << "o = " << o << endl;
                    cout << " ohoho = " << setw(6) << right << ohoho << endl << " ahaha = " << setw(6) << right << ahaha << endl << "ahahah = " << ahahah << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
