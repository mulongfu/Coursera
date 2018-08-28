#include <iostream>
using namespace std;

int main() {
	int n = 0, a[100] = { 0 };
	bool flag = false;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == i) {
			flag = true;
			cout << i << endl;
			break;
		}
	}
	if (!flag)
		cout << 'N' << endl;
	return 0;
}