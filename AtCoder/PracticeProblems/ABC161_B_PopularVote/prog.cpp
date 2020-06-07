#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    vector<double> v(n);

    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int i;
    double d = 1.0 / (4 * m);
    for(i = 0; i < m; ++i) {
        if(v[i] / sum < d)
            break;   
    }

    if(i == m)
        cout << "Yes";
    else
        cout << "No";

    cout << endl;

    return 0;
}