#include <iostream>

using namespace std;

int main() {
	int m = 0, k = 0, countTHREE = 0, orig = 0;
	cin >> m >> k;
	orig = m;
	while (m != 0) {
		if (m % 10 == 3) {
			countTHREE++;
		}
		m /= 10;
	}
	if (orig % 19 == 0 && countTHREE == k)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}