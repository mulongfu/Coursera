#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--) {
		int n, i, j;
		cin >> n >> i >> j;
		bitset<30> in(n);		
		bitset<30> b;
		b[i] = in[i];
		if (in[j] == 1)
			b[j] = 0;
		else
			b[j] = 1;
		//cout << b;
		for (int l = i + 1; l < j; l++) {
			b[l] = 1;
		}
		cout << hex << b.to_ulong() << endl;
	}
	return 0;
}