#include <iostream>

using namespace std;

int main() {
	int m, n;
	int mat[100][100] = { 0 };
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < m + n - 1; i++) {
		int a, b;
		b = i > n - 1 ? n - 1 : i;
		a = i - b;
		while (a < m && b >= 0) {
			cout << mat[a][b] << endl;
			a++;
			b--;
		}
	}
	return 0;
}