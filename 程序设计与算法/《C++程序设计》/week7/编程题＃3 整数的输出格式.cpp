#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int input;
	while(cin >> input){
		cout << hex << input << endl;
		cout << dec << setw(10) << setfill('0') << input << endl;
	}
	return 0;
} 