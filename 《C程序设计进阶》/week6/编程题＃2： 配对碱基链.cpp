#include <iostream>
#include <string>
using namespace std;

int main() {
	int n = 0;
	string rece;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rece;
		for (int i = 0; i < rece.length(); i++) {
			switch (rece[i]) {
			case'A':
				rece[i] = 'T';
				break;
			case'T':
				rece[i] = 'A';
				break;
			case'G':
				rece[i] = 'C';
				break;
			case'C':
				rece[i] = 'G';
				break;
			default:
				break;
			}
		}
		cout << rece << endl;
	}
	return 0;
}