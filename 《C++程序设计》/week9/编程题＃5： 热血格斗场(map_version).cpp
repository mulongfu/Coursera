#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	map<int, int> strtoid;
	map<int, int>::iterator i, it;
	int n, id, str;
	cin >> n;
	strtoid.insert(make_pair(1000000000, 1));
	while (n-- > 0) {
		cin >> id >> str;
		i = strtoid.lower_bound(str);
		if (i == strtoid.begin()) { // 只有facer時
			cout << id << " " << i->second << endl;			
		}
		else { // >= 3
			it = i;
			it--;
			if (str - it->first <= i->first - str) {
				cout << id << " " << it->second << endl;
			}
			else {
				cout << id << " " << i->second << endl;
			}
		}
		strtoid.insert(make_pair(str, id));
	}	
	/*map<pair<int, int>>::iterator t = idtostr.begin();
	for (t; t != idtostr.end(); t++) {
	cout << t->first << " " << t->second << endl;
	}*/
	return 0;
}