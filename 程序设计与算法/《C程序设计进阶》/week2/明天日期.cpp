#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	bool odd = false;
	int year, month, day;

	char dash = '-';
	
	cin >> year >> dash >> month >> dash >> day;
	
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		odd = true;
	if (month == 1 && day == 31)
		cout << year << dash << setfill('0') << setw(2) << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 2 && odd == true && day == 28)
		cout << year << dash << setfill('0') << setw(2) << month << dash << 29 << endl;

	else if (month == 2 && odd == true && day == 29)
		cout << year << dash << setfill('0') << setw(2) << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 2 && day == 28)
		cout << year << dash << setfill('0') << setw(2) << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 3 && day == 31)
		cout << year << dash << setfill('0') << setw(2) << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 4 && day == 30)
		cout << year << dash << setfill('0') << setw(2) << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 5 && day == 31)
		cout << year << dash << setfill('0') << setw(2) << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 6 && day == 30)
		cout << year << dash << setfill('0') << setw(2) << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 7 && day == 31)
		cout << year << dash << setfill('0') << setw(2) << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 8 && day == 31)
		cout << year << dash << setfill('0') << setw(2) << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 9 && day == 30)
		cout << year << dash << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 10 && day == 31)
		cout << year << dash << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 11 && day == 30)
		cout << year << dash << month + 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if (month == 12 && day == 31)
		cout << year + 1 << dash << setfill('0') << setw(2) << 1 << dash << setfill('0') << setw(2) << 1 << endl;

	else if ((month == 10 || month == 11 || month == 12)) {
			if((day == 1) || (day == 2) || (day == 3) || (day == 4) || (day == 5) || (day == 6) || (day == 7) || (day == 8))
				cout << year << dash << month << dash << setfill('0') << setw(2) << day + 1 << endl;
			else
				cout << year << dash << month << dash << day + 1 << endl;
		}
	else
		if ((day == 1) || (day == 2) || (day == 3) || (day == 4) || (day == 5) || (day == 6) || (day == 7) || (day == 8))
			cout << year << dash << setfill('0') << setw(2) << month << dash << setfill('0') << setw(2) << day + 1 << endl;
		else
			cout << year << dash << setfill('0') << setw(2) << month << dash << day + 1 << endl;
	return 0;
}