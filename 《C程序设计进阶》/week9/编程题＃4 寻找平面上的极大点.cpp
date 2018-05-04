#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int x;
	int y;
	bool cover;
}p[100];


bool sorting(point a, point b) {
	//return a.x < b.x;
	if (a.x < b.x)
		return 1;
	else if (a.x == b.x && a.y < b.y)
		return 1;
	return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
		
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n; j++) {
			if (i != j && p[j].x >= p[i].x && p[j].y >= p[i].y) {
				p[i].cover = true;	
				break;
			}
		}
		
	}
	sort(p, p + n, sorting);
	
	bool first = true;

	for (int i = 0; i < n; i++) {
		
		if (p[i].cover == false && first) {
			cout << '(' << p[i].x << ',' << p[i].y << ')';
			first = false;
		}
		else if (p[i].cover == false && !first)
			cout << ',' << '(' << p[i].x << ',' << p[i].y << ')';			
	}
	cout << endl;
	//cout << '(' << p[i].x << ',' << p[i].y << ')' << ',';
		
	return 0;
}