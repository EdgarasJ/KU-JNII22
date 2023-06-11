/*
Author: Edgaras Jurevičius
Date: 2022-10-11
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int send, more, money;
    for (int s = 0; s < 10; s++){
        for (int y = 0; y < 10; y++){
            for (int d = 0; d < 10; d++){
                for (int r = 0; r < 10; r++){
                    for (int n = 0; n < 10; n++){
                        for (int m = 0; m < 10; m++){
                            for (int o = 0; o < 10; o++){
                                for (int e = 0; e < 10; e++){
                                    //tikriname ar skaitmenys nesikartoja
                                    if (s == e || s == n || s == d || s == m || s == o || s == r || s == y || s == 0) continue; //tikriname ar ne nulis nes priekyje nulis nerasomas
                                    if (e == n || e == d || e == m || e == o || e == r || e == y || e == 0) continue; //tikriname ar ne nulis nes D + E == Y
                                    if (n == d || n == m || n == o || n == r || n == y) continue;
                                    if (d == m || d == o || d == r || d == y || d == 0) continue; //tikriname ar ne nulis nes D + E == Y
                                    if (m == o || m == r || m == y || m == 0) continue; //tikriname ar ne nulis nes priekyje nulis nerasomas
                                    if (o == r || o == y) continue;
                                    if (r == y) continue;
                                    send = s * 1000 + e * 100 + n * 10 + d;
                                    more = m * 1000 + o * 100 + r * 10 + e;
                                    money = m * 10000 + o * 1000 + n * 100 + e * 10 + y;
                                    if (send + more == money && money != 0){
                                        // rezultato isvedimas
                                        cout << "S=" << s << "; E=" << e << "; N=" << n << "; D=" << d << "; M=" << m << "; O=" << o << "; R=" << r << "; Y=" << y << endl;
                                        cout << " SEND <=> " << setw(5) << right << send << endl;
                                        cout << "+" << endl;
                                        cout << " MORE <=> " << setw(5) << right << more << endl;
                                        cout << "-----     -----" << endl;
                                        cout << "MONEY <=> " << money << endl;
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

    return 0;
}
