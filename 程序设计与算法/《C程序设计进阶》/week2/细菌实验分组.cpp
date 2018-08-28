#include <iostream>
#include <algorithm>
using namespace std;

struct cell {
	int id, before, after;
	double rate;
};

bool comp(cell a, cell b) {
	return a.rate < b.rate;
}

int main() {
	int n = 0, typea = 0, typeb = 0;
	cin >> n;
	cell exp[101];
	for (int i = 0; i < n; i++) {		
		cin >> exp[i].id >> exp[i].before >> exp[i].after;			
		exp[i].rate = (double)exp[i].after / (double)exp[i].before;
	}
	//Sort all rate min -> max
	sort(exp, exp + n, comp);

	/*
	for (int i = 0; i < n; i++) {
		cout << exp[i].rate << endl;
	}
	*/

	double temp = 0;
	int index = 0;

	for (int i = 0; i < n-1; i++) {		
		if (temp < (exp[i + 1].rate - exp[i].rate)) {
			temp = exp[i + 1].rate - exp[i].rate;
			index = i + 1;
		}
	}
	
	cout << n - index << endl;
	for (int i = index; i < n; i++)
		cout << exp[i].id << endl;

	cout << n - (n - index) << endl;
	for (int i = 0; i < index; i++)
		cout << exp[i].id << endl;
	
	return 0;
}