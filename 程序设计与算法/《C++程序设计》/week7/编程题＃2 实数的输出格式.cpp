#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double input;
	while(cin >> input){
		cout << fixed << setprecision(5) << input << endl;
		cout << fixed << setprecision(7) << scientific << input << endl;
	}
	return 0;
} 