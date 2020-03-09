#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 100000;

int main() {

    int n;

    cin >> n;

    int x6 = 1;
    int x9 = 1;

    vector<int> dp(n + 1);

    dp[1] = 1;

    for(int i = 2; i <= n; ++i) {

        if(x6 * 6 == i)
            x6 *= 6;
        if(x9 * 9 == i)
            x9 *= 9;

        int a = 1 + dp[i - 1];
        int b = 1 + dp[i - x6];
        int c = 1 + dp[i - x9];

        dp[i] = min(a, min(b, c));
    }

    cout << dp[n] << endl;

    return 0;

}