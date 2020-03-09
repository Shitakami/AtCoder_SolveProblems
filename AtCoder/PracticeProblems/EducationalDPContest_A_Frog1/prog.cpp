#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> step(n);

    for(int i = 0; i < n; ++i)
        cin >> step[i];

    vector<int> dp(n, 0);

    dp[0] = 0;
    dp[1] = abs(step[0] - step[1]);

    for(int i = 2; i < n; ++i) {

        int a = dp[i - 2] + abs(step[i] - step[i - 2]);
        int b = dp[i - 1] + abs(step[i] - step[i - 1]);

        dp[i] = min(a, b);

    }

    cout << dp[n - 1] << endl;

    return 0;
}