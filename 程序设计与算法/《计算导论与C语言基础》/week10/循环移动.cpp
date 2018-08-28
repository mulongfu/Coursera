#include <iostream>

using namespace std;

int main() {
	int m, n, arr[100] = { 0 };
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	for (int i = m - 1; i >= 0; i--) {
		arr[i + n] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = arr[m + i];
	}

	for (int i = 0; i < m; i++)
		cout << arr[i] << " ";

	return 0;	
}