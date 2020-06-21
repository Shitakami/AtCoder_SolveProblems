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
    int maxV = v[n - 1];

    vector<bool> used(maxV + 1, false);
    int count = 0;

    for(int i = 0; i < n; ++i) {

        if(used[v[i]])
            continue;

        for(int j = 1; j * v[i] <= maxV; j++) {
            used[v[i] * j] = true;
        }

        if(i + 1 < n && v[i] == v[i + 1])
            continue;

        count++;

    }

    cout << count << endl;

    return 0;


}