#include <iostream>

using namespace std;

int main() {
	unsigned int svoris;
	cout << "Iveskite siuntinio svori gramais: ";
	cin >> svoris;
	unsigned int pz10, pz4, pz1;
	pz10 = pz4 = pz1 = 0;
	unsigned int kaina = svoris / 50 + 1; //kaina = 10 + (svoris - 1) / 50 * 5
	if (svoris % 50 != 0) {
		kaina++;
	}
	kaina *= 5;
	cout << "Siuntinio kaina: " << kaina << endl;
	pz10 = kaina / 10;
	kaina = kaina % 10;
	pz4 = kaina / 4;
	pz1 = kaina % 4;
	cout << "Jums reikes: " << pz10 << " 10 cnt, " << pz4 << " 4 cnt ir " << pz1 << " 1 cnt nominalo pasto zenklu." << endl;
	system("pause");
	return 0;
}
