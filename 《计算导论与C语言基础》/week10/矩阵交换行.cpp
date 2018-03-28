#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int ma[5][5] = { 0 }, m, n, temp[5] = { 0 };
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> ma[i][j];
	cin >> m >> n; 

	if (m < 0 || m > 4 || n < 0 || n > 4) {
		cout << "error" << endl;
		return 0;
	}

	for (int i = 0; i < 5; i++) {		
		temp[i] = ma[m][i];
	}

	for (int i = 0; i < 5; i++) {		
		ma[m][i] = ma[n][i];
	}

	for (int i = 0; i < 5; i++) {
		ma[n][i] = temp[i];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << setw(4) << ma[i][j];
		}
		cout << endl;
	}
	return 0;
}