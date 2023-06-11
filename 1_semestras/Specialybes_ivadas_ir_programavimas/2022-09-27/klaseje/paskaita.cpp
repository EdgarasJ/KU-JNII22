#include <iostream>

using namespace std;

int max2(int x, int y) {

	if (x > y) return x;
	else return y;

}

int main() {
	int a, b, c, d;
	cout << "Iveskite pirma pazymi: " << endl; cin >> a;
	cout << "Iveskite antra pazimi: " << endl; cin >> b;
	cout << "Iveskite trecia pazimi: " << endl; cin >> c;
	cout << "Iveskite ketvirta pazimi: " << endl; cin >> d;

	cout << "Disziausias pazimys: " << max2(max2(a,b), max2(c,d)) << endl;
	return 0;
}
