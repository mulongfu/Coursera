#include <iostream>
#include <utility>
#include <stack>
using namespace std;

int main() {
	stack<pair<char, int>> s;
	char sign[100], left = ' ', right = ' ';
	int i = 0;
	cin.getline(sign, 100);
	left = sign[i];

	while (sign[i] == left) {
		i++;
	}
	sign[i] = right;
	i = 0;
	while (sign[i] != '\0') {
		if (sign[i] == left) {
			s.push(make_pair(left, i));
			i++;
		}
		else {
			pair <char, int> p = s.top();
			s.pop();
			cout << p.second << ' ' << i << endl;
			i++;
		}
	}

}