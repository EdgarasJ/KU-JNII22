// OHOHO + AHAHA == AHAHAH
// URANUS + VENUS == EUROPA
// kto + kot == tok

//ND: SEND + MORE == MONEY

#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int kto, kot, tok;
    for (int k = 0; k < 10; k++){
        for (int t = 0; t < 10; t++){
            for (int o = 0; o < 10; o++){
                if (k == t || k == o) continue;
                if (t == 0) continue;
                kto = k*100+t*10+o;
                kot = k*100+o*10+t;
                tok = t*100+o*10+k;
                if (kto+kot == tok && tok != 0) {
                    cout << "K = " << k << "; T = " << t << "; O = " << o << endl;
                    cout << "KTO = " << kto << endl << "KOT = " << kot << endl << "TOK = " << tok << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
