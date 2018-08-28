#include <iostream>

using namespace std;

int main() {
	int n, cell[101][101], coun = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cell[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != 0 && i != n && j != 0 && j != n) {
				if (abs(cell[i][j] - cell[i - 1][j]) >= 50 &&
					abs(cell[i][j] - cell[i + 1][j]) >= 50 &&
					abs(cell[i][j] - cell[i][j - 1]) >= 50 &&
					abs(cell[i][j] - cell[i][j + 1]) >= 50)
					coun++;
			}
		}
	}
	cout << coun;
	return 0;
}