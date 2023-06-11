// OHOHO + AHAHA == AHAHAH
// URANUS + VENUS == EUROPA
// kto + kot == tok

//ND: SEND + MORE == MONEY

#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int uranus, venus, europa;
    for (int v = 0; v < 10; v++){
        for (int o = 0; o < 10; o++){
            for (int p = 0; p < 10; p++){
                for (int n = 0; n < 10; n++){
                    for (int s = 0; s < 10; s++){
                        for (int e = 0; e < 10; e++){
                            for (int r = 0; r < 10; r++) {
                                for (int a = 0; a < 10; a++){
                                    for (int u = 0; u < 10; u++){
                                        if (u == r || u == a || u == n || u == s || u == v || u == e || u == o || u == p) continue;
                                        if (r == a || r == n || r == s || r == v || r == e || r == o || r == p) continue;
                                        if (a == n || a == s || a == v || a == e || a == o || a == p) continue;
                                        if (n == s || n == v || n == e || n == o || n == p) continue;
                                        if (s == v || s == e || s == o || s == p) continue;
                                        if (v == e || v == o || v == p) continue;
                                        if (e == o || e == p) continue;
                                        if (o == p) continue;
                                        uranus = u * 100000 + r * 10000 + a * 1000 + n * 100 + u * 10 + s;
                                        venus = v * 10000 + e * 1000 + n * 100 + u * 10 + s;
                                        europa = e* 100000 + u * 10000 + r * 1000 + o * 100 + p * 10 + a;
                                        if (uranus + venus == europa && europa != 0) {
                                            cout << "U=" << u << "; R=" << r << "; A=" << a << "; N=" << n << "; S=" << s << "; V=" << v << "; E=" << e << "; O=" << o << "; P=" << p << endl;
                                            cout << "URANUS = " << uranus << endl;
                                            cout << " VENUS = " << setw(6) << right << venus << endl;
                                            cout << "EUROPA = " << europa << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
