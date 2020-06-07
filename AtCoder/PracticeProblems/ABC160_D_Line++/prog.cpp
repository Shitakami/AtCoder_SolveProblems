#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int n, x, y;

    cin >> n >> x >> y;
    x--;
    y--;

    vector<int> distance(n, 0);

    for(int i = 0; i < n - 1; ++i) {

        for(int j = i + 1; j < n; ++j) {

            int d = min(j - i, min(abs(x - i) + 1 + abs(y - j), abs(y - i) + 1 + abs(x - j)));

           // cout << i << ":" << j << " = " << d << endl;

            
            distance[d]++;

        }

    }

    for(int i = 1; i < n; ++i)
        cout << distance[i] << endl;

    return 0;

}