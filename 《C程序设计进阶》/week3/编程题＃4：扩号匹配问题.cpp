#include <iostream>
#include <utility>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	stack<pair<char, int>> s;
	char sign[101] = { '\0' };

	while (cin.getline(sign, 101)) {
		int i = 0;
		char fail[101];

		for (int i = 0; i < 101; i++)
			fail[i] = ' ';

		while (sign[i] != '\0') {
			if (sign[i] == '(') {
				s.push(make_pair(sign[i], i));
				i++;
			}
			else if (s.empty() && sign[i] == ')') {
				fail[i] = '?';
				i++;
			}
			else if (!s.empty() && sign[i] == ')') {
				s.pop();
				i++;
			}
			else {
				i++;
			}
		}
		//cout << fail;
		cout << sign << endl;
		while (!s.empty()) {
			pair<char, int> p = s.top();
			int temp = p.second;
			fail[temp] = '$';
			s.pop();
		}

		int good = strlen(sign);

		for (int i = 0; i < good; i++) {
			cout << fail[i];
		}
		cout << endl;
	}
	return 0;
}