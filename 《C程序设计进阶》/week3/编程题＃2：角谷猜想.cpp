#include <iostream>
using namespace std;

void cal(int num){
	if (num == 1)
		cout << "End";

	else if (num % 2 == 1) {
		cout << num << "*" << 3 << "+" << 1 << "=" << num * 3 + 1 << endl;
		num = num * 3 + 1;		
		cal(num);
	}
	else {
		cout << num << "/" << 2 << "=" << num / 2 << endl;
		num /= 2;
		cal(num);
	}
}

int main() {
	int n;
	cin >> n;
	cal(n);
	cout << endl;
	return 0;
}