#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

using ll = long long;

const ll mod = 1e+9 + 7;

int main() {

    int n, k;

    cin >> n >> k;

    set<int> dangerStep;

    vector<ll> stepCount(n + 10, 0);

    for(int i = 0; i < k; ++i) {
        int step;
        cin >> step;
        stepCount[step] = -1;

    }

    stepCount[0] = 1;

    if(stepCount[1] != -1)
        stepCount[1] = 1;

    for(int i = 2; i <= n; ++i) {

        if(stepCount[i] == -1)
            continue;

        if(stepCount[i - 1] != -1)
            stepCount[i] = (stepCount[i] + stepCount[i - 1]) % mod;
        if(stepCount[i - 2] != -1)
            stepCount[i] = (stepCount[i] + stepCount[i - 2]) % mod;

    }

    cout << stepCount[n] << endl;

    return 0;
}