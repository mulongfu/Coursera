#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	multiset<int> m;
	map<int, bool> inttobool;
	map<int, bool>::iterator it;
	for (int i = 0; i < n; i++) {
		string s;
		int in;
		cin >> s >> in;
		if (s == "add") {
			m.insert(in);
			inttobool.insert(make_pair(in, 1));
			cout << m.count(in) << endl;
		}
		else if (s == "ask") {
			it = inttobool.find(in);
			if (it != inttobool.end()) {
				cout << 1 << " " << m.count(in) << endl;
			}
			else{
				cout << 0 << " " << 0 << endl;
			}
		}
		else if (s == "del") {
			cout << m.count(in) << endl;
			m.erase(in);
		}
	}
	return 0;
}