#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> p(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    double value = v[0];

    for(int i = 1; i < n; ++i) {
        value += v[i];
        value /= 2.0;
    }

    printf("%.10f\n", value);
    return 0;

}