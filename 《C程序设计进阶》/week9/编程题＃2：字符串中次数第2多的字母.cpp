#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct alphabet {
	char alpha;
	int times = 0;
	int index = 0;
	bool first = true;
} ab[26];

int main() {

	string in;
	cin >> in;
	transform(in.begin(), in.end(), in.begin(), ::toupper);

	for (int i = 0; i < in.length(); i++) {

		if (in[i] >= 'A' && in[i] <= 'Z') {
			ab[in[i] - 'A'].times = ab[in[i] - 'A'].times + 1;
			ab[in[i] - 'A'].alpha = in[i];

			if (ab[in[i] - 'A'].first) {
				ab[in[i] - 'A'].index = i;
				ab[in[i] - 'A'].first = false;
			}
		}
	}

	/*for (int i = 0; i < 26; i++) {
		cout << ab[i].times;
	}
	cout << endl;
	for (int i = 0; i < 26; i++) {
		cout << ab[i].index;
	}*/

	int max = 0, sec_max = 0;

	for (int i = 0; i < 26; i++) {
		if (ab[i].times > max)
			max = ab[i].times;
	}

	for (int i = 0; i < 26; i++) {
		if (ab[i].times == max)
			ab[i].times = 0;
	}

	for (int i = 0; i < 26; i++) {
		if (ab[i].times > sec_max) {
			sec_max = ab[i].times;
		}
	}
	int index = 999999;
	for (int i = 0; i < 26; i++) {

		if (ab[i].times == sec_max && ab[i].index < index)
			index = ab[i].index;
	}

	//cout << index;
	cout << (char)toupper(in[index]) << '+' << (char)tolower(in[index]) << ':' << sec_max << endl;

	return 0;
}