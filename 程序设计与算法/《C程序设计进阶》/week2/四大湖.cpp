#include <iostream>
using namespace std;

int main() {
	int py, dt, ti, hz;
	for (py = 1; py <= 4; py++) {
		for (dt = 1; dt <= 4; dt++) {
			for (ti = 1; ti <= 4; ti++) {
				for (hz = 1; hz <= 4; hz++) {
					if ((py != dt && py != ti && py != hz && dt != ti && dt != hz && ti != hz) &&
						((py == 3) + (dt == 1) + (hz == 4) == 1) &&
						((hz == 1) + (dt == 4) + (py == 2) + (ti == 3) == 1) &&
						((hz == 4) + (dt == 3) == 1) &&
						((py == 1) + (ti == 4) + (hz == 2) + (dt == 3) == 1)
						&& ((py + dt + ti + hz) == 10)) {
						cout << py << endl << dt << endl << ti << endl << hz << endl;						
						}
				}
			}
		}			
	}
	return 0;
}