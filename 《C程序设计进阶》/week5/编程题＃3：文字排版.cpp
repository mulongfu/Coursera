#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int num;
	char text[1000][41];
	cin >> num;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 41; j++) {
			text[i][j] = ' ';
		}
	}

	for (int i = 0; i < num; i++) {
		cin >> text[i];
	}

	int j = 0, counter = 0;

	while (*text[j] != ' ') {
		counter = counter + strlen(text[j]);
		if (j + 1 == num && counter > 80) { //如果是最後一個,要換行
			cout << endl;
			cout << text[j];
			cout << endl;
			return 0;
		}

		else if (j + 1 == num && counter == 80) {//如果是最後一個,且不用換行
			cout << text[j];
			cout << endl;
			return 0;
		}

		else if (j + 1 == num && counter < 80) {//如果是最後一個,且不用換行
			cout << text[j];
			cout << endl;
			return 0;
		}

		else if (counter > 80) {
			cout << endl;
			cout << text[j] << ' ';
			counter = strlen(text[j]);
		}

		else if (counter + strlen(text[j + 1]) + 1 == 80) {	//如果是該行最後一個
			cout << text[j] << ' ';
			//counter = 0;
		}

		else if (counter + strlen(text[j + 1]) + 1 > 80) {
			cout << text[j];
			cout << endl;
			counter = 0;
		}

		else {
			cout << text[j] << ' ';
			counter++;
		}
		j++;
	}

}