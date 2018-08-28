#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(vector<long long>& numbers) {
	auto it = max_element(std::begin(numbers), std::end(numbers));
	long long a = *it;
	numbers.erase(it);
	it = max_element(std::begin(numbers), std::end(numbers));
	long long b = *it;
	return a * b;
	//return result;
}

int main() {
	long long n;
	cin >> n;
	vector<long long> numbers(n);
	for (long long i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	long long result = MaxPairwiseProduct(numbers);
	cout << result << "\n";
	return 0;
}
