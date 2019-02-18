#include <iostream>
#include <climits>
using namespace std;

int puzzle[16][17] = { 0 }, press[16][17] = { 0 };

int guess(const int _n) {	
	for (int r = 1; r < _n; r++) {
		for (int c = 1; c <= _n; c++) {
			press[r + 1][c] = (puzzle[r][c] + press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;
			//下一列要不要按取決於這一列、上一列、右行、左行是否按下與這一列的值
		}
	}
	
	for (int c = 1; c <= _n; c++) {
		if ((press[_n][c - 1] + press[_n][c] + press[_n][c + 1] + press[_n - 1][c]) % 2 != puzzle[_n][c]) {
			return INT_MAX;
		}
	}
	
	int steps = 0;
	for (int r = 1; r <= _n; r++) {
		for (int c = 1; c <= _n; c++) {
			if (press[r][c] == 1) {
				steps++;
			}
		}
	}
	return steps;
}

int enumerate(const int _n) {
	int minsteps = INT_MAX;
	int steps = 0;
	int c;
	while (press[1][_n + 1] < 1) {
		steps = guess(_n);
		if (steps < minsteps) {
			minsteps = steps;
		}
		press[1][1]++;
		c = 1;
		while (press[1][c] > 1) {
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}
	}
	return minsteps;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);	
	int cases, steps;
	char color; // 0 == y, 1 == w
	cin >> cases;
	while (cases--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> color;
				puzzle[i][j] = color == 'y' ? 0 : 1;
			}
		}
		steps = enumerate(n);
		if (steps == INT_MAX)
			cout << "inf" << endl;
		else
			cout << steps << endl;
	}
	return 0;
}