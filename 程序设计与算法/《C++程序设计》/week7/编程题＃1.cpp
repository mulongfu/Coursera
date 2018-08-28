#include <iostream>
using namespace std;

template <class T>
class CArray2D{
	T **array2d;
	CArray2D(int a, int b){
		array2d = new T *[a];
		for(int i = 0; i < a; i++)
			array2d[i] = new T[b];
	}
	T* operator[] (int i){
		return array2d[i];
	}
}; 

template <class T>
class CArray3D{
	public:
		T ***array3d;
		CArray3D(int a, int b, int c){
			array3d = new T **[a];
			for(int i = 0; i < a; i++){
				array3d[i] = new T *[b];
				for(int j = 0; j < b; j++){
					array3d[i][j] = new T[c];
				}
			}
		}
		T** operator[] (int i){
			return array3d[i];
		}
};


int main(){
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
