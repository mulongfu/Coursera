#include <iostream>

using namespace std;

int main() {
	int m, n;
	int mat[21][21];
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			mat[i][j] = -1;
		}
	}

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if ((mat[i][j] >= mat[i][j - 1]) && (mat[i][j] >= mat[i][j + 1]) &&
				(mat[i][j] >= mat[i - 1][j]) && (mat[i][j] >= mat[i + 1][j]))
				cout << i-1 << ' ' << j-1 << endl;
		}
	}
	return 0;
}