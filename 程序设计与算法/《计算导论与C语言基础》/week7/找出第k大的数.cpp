#include <iostream>
using namespace std;

int main() {
	int n, k, a[100], maxK, size = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] <= a[j])
				size++;
		}
		if (k == size)
			cout << a[i];
		size = 0;
	}
	return 0;
}