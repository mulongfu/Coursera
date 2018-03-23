#include <iostream>
#include <climits>

using namespace std;

int main() {
	int array[6], maxO = 0, minE = INT_MAX;
	
	for (int i = 0; i < 6; i++) {
		cin >> array[i];
		if (array[i] % 2 != 0) {	//奇數
			if (array[i] > maxO)
				maxO = array[i];
		}
		else{						//偶數
			if (array[i] < minE)
				minE = array[i];
		}
	}
	cout << abs(maxO - minE);
}