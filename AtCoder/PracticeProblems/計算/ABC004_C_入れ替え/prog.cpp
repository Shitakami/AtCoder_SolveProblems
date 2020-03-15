#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	// Your code here!

	int v[] = { 1, 2, 3, 4, 5, 6 };

	int n;

	cin >> n;

	n %= 6 * 5;

	for (int i = 0; i < n; ++i) {
		int index = i % 5;
		swap(v[index], v[index + 1]);

	}

	for (int i = 0; i < 6; ++i)
		cout << v[i];
	cout << endl;

}
