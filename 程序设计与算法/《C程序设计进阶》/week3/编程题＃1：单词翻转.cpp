#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void print(char s[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		cout << s[i];
	}
}

int main() {
	char in[500];
	cin.getline(in, 500);
	int i = 0;
	while (in[i] != '\0') {
		if (in[i] != ' ') {
			int k = 0;
			char temp[500] = { '\0' };
			while (in[i] != ' ' && in[i] != '\0') {
				temp[k] = in[i];
				i++;
				k++;
			}
			int size = strlen(temp);
			print(temp, size);
		}
		else {
			cout << ' ';
			i++;
		}
	}
	cout << endl;
	return 0;
}