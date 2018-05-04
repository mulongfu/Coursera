#include <iostream>

using namespace std;

int main() {
	int k, m, n;
	int mat[100][100] = { 0 };
	cin >> k;
	for (int i = 0; i < k; i++) {
		int sum = 0;
		bool flag = false;
		cin >> m >> n;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> mat[j][k];
			}
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				//non corner
				if (j == 0) {
					sum += mat[j][k];
				}
				else if (j == m - 1)
					sum += mat[j][k];
				else if (k == 0)
					sum += mat[j][k];
				else if (k == n - 1)
					sum += mat[j][k];
				else
					continue;
			}
		}
		cout << sum << endl;
	}
}