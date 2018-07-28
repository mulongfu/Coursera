#include <iostream> 
#include <queue>
#include <cstdio>
#include <bitset>

using namespace std;
bitset<3200> tab;

int count(int k) {
	int num = 0;
	for (int j = 2; j < 3200 && j < k; j++) {
		if (tab[j] == 0 && k % j == 0) {
			while (k % j == 0)
				k /= j;
			num++;
			if (k == 1) break;
		}
	}
	if (k == 1)
		return num;
	else if (num == 0)
		return 0;
	else
		return num + 1;
}

class Compare_pl {
public:
	bool operator() (pair<int, int> a, pair<int, int> b) {		
		if (a.first < b.first)
			return true;
		else if (a.first == b.first)
			return a.second < b.second;
		else
			return false;
	}
};

class Compare_ph {
public:
	bool operator() (pair<int, int> a, pair<int, int> b) {	
		if (a.first > b.first)
			return true;
		else if (a.first == b.first)
			return a.second > b.second;
		else
			return false;
	}
};


int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	for (int i = 0; i < 3200; i++)
		tab[i] = 0;
	tab[0] = tab[1] = 1;
	for (int i = 2; i < 3200; i++) {
		if (!tab[i])
			for (int j = i + i; j < 3200; j += i)
				tab[j] = 1;
	}
	int num = 0;
	priority_queue<int, vector<pair<int, int> >, Compare_pl> pq1;
	priority_queue<int, vector<pair<int, int> >, Compare_ph> pq2;
	cin >> num;
	while (num--) {
		int tmp = 0;
		for (int t = 0; t < 10; t++) {
			cin >> tmp;
			pq1.push(make_pair(count(tmp), tmp));
			pq2.push(make_pair(count(tmp), tmp));
		}
		cout << pq1.top().second << " " << pq2.top().second << endl;
		pq1.pop();
		pq2.pop();
	}
	return 0;

}
