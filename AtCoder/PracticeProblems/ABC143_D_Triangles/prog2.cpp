#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    int sum = 0;
    for(int i = 0; i < n - 2; ++i) {
        for(int j = i + 1; j < n - 1; ++j) {
            for(int k = j + 1; k < n; ++k) {
                if(v[k] < v[i] + v[j])
                    sum++;
            }
        }
    }

    cout << sum << endl;

    return 0;

}