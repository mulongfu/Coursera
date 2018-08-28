#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int i = 0;
	char result;
	string s, v;
	cin >> s >> v;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	transform(v.begin(), v.end(), v.begin(), ::toupper);
	while (s[i] != '\0' && (s[i] == v[i])) {
		i++;
	}
	if (s[i] > v[i]) {
		result = '>';
	}
	else if (s[i] < v[i]) {
		result = '<';
	}
	else {
		result = '=';
	}
	cout << result;
	return 0;
}