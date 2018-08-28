#include <iostream>

using namespace std;

int main() {
	int n,per,ten,ind;
	cin >> n;
	per = n / 100;
	ten = (n - per * 100) / 10;
	ind = (n - per * 100) - (ten * 10);
	cout << per << endl << ten << endl << ind;
	return 0;
}