#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
private:
	int **ptr_array; // �ʺA�G���}�C
	int rowSize, colSize;
public:
	Array2(int _rowS = 0, int _colS = 0) : rowSize(_rowS), colSize(_colS) {
		if (rowSize == 0 && colSize == 0)
			ptr_array = NULL;
		else {

			ptr_array = new int*[colSize];
			for (int i = 0; i < colSize; i++) {
				ptr_array[i] = new int[rowSize];
			}
		}
	}
	Array2(Array2& copy) {
		if (!copy.ptr_array) {
			ptr_array = NULL;
			rowSize = 0;
			colSize = 0;
			return;
		}
		else {
			ptr_array = new int*[colSize];
			for (int i = 0; i < colSize; i++) {
				ptr_array[i] = new int[rowSize];
			}
			memcpy(copy.ptr_array[0], ptr_array[0], rowSize * colSize * sizeof(int));
		}
	}

	int* operator[](int i) {
		return ptr_array[i];
	}
	int operator()(int i, int j) {
		return ptr_array[i][j];
	}
};

int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;     b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}