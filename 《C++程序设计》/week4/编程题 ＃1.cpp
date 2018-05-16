#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	Complex(int _r = 0, int _i = 0) : r(_r), i(_i) {};
	Complex& operator = (char *input) {
		r = *input - '0';
		input += 2;
		i = *input - '0';
		return *this;
	}
};
int main() {
	Complex a;
	a = "3+4i"; a.Print();
	a = "5+6i"; a.Print();
	return 0;
}