#include <iostream>
#include <iomanip> 
using namespace std;
/*
1
100.345 2006.008 2331.41592653498
*/
int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		/*
		output:
		0x64
		_______+2006.01
		2.331415927E+03
		*/
		//line 1
		cout << left << hex << showbase << nouppercase << (long long)A << endl;
		cout.copyfmt(std::ios(NULL));
		//line 2
		cout << setprecision(2) << setw(15) << dec << setfill('_') << noshowbase << showpos << right << fixed << B << endl;
		//line 3
		cout.copyfmt(std::ios(NULL));
		cout << scientific << setprecision(9) << uppercase << noshowpos << C;

	}
	return 0;

}