#include <iostream>
#include <vector>
using namespace std;
int main() {
	// Your code here!

	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 0; i <= n; ++i) {


		for (int j = 0; j <= m; ++j) {

			int count = (n - i) * j + i * m - j * i;

			if (count == k) {
				cout << "Yes" << endl;
				return 0;
			}


		}

	}

	cout << "No" << endl;

	return 0;

}
