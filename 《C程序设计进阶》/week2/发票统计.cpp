#include <iostream>
#include <iomanip>
using namespace std;

struct ticket {
	char type;
	float amount;
}tk;

int main() {
	float ticketA = 0, ticketB = 0, ticketC = 0, total1 = 0, total2 = 0, total3 = 0;
	int id = 0, number = 0;
	for (int i = 0; i < 3; i++) {
		cin >> id;
		switch (id) {
		case 1:
			cin >> number;
			for (int i = 0; i < number; i++) {
				cin >> tk.type;
				if (tk.type == 'A') {
					cin >> tk.amount;
					ticketA += tk.amount;
					total1 += tk.amount;
				}
				else if (tk.type == 'B') {
					cin >> tk.amount;
					ticketB += tk.amount;
					total1 += tk.amount;
				}
				else {
					cin >> tk.amount;
					ticketC += tk.amount;
					total1 += tk.amount;
				}
			}
			break;
		case 2:
			cin >> number;
			for (int i = 0; i < number; i++) {
				cin >> tk.type;
				if (tk.type == 'A') {
					cin >> tk.amount;
					ticketA += tk.amount;
					total2 += tk.amount;
				}
				else if (tk.type == 'B') {
					cin >> tk.amount;
					ticketB += tk.amount;
					total2 += tk.amount;
				}
				else {
					cin >> tk.amount;
					ticketC += tk.amount;
					total2 += tk.amount;
				}
			}
			break;
		case 3:
			cin >> number;
			for (int i = 0; i < number; i++) {
				cin >> tk.type;
				if (tk.type == 'A') {
					cin >> tk.amount;
					ticketA += tk.amount;
					total3 += tk.amount;
				}
				else if (tk.type == 'B') {
					cin >> tk.amount;
					ticketB += tk.amount;
					total3 += tk.amount;
				}
				else {
					cin >> tk.amount;
					ticketC += tk.amount;
					total3 += tk.amount;
				}
			}
			break;
		}
	}	
	cout << 1 << " " << setprecision(2) << fixed << total1 << endl;
	cout << 2 << " " << setprecision(2) << fixed << total2 << endl;
	cout << 3 << " " << setprecision(2) << fixed << total3 << endl;
	cout << 'A' << " " << setprecision(2) << fixed << ticketA << endl;
	cout << 'B' << " " << setprecision(2) << fixed << ticketB << endl;
	cout << 'C' << " " << setprecision(2) << fixed << ticketC << endl;
	return 0;
}