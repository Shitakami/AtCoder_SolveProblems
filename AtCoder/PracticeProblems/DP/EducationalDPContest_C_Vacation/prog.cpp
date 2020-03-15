#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e+5 + 10;

int action[MAX][3];
int dp[MAX][3];

int main() {

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> action[i][0] >> action[i][1] >> action[i][2];

    }

    
    dp[0][0] = action[0][0];
    dp[0][1] = action[0][1];
    dp[0][2] = action[0][2];

    for(int i = 1; i < n; ++i) {

        dp[i][0] = max(dp[i - 1][1] + action[i][0], dp[i - 1][2] + action[i][0]);
        dp[i][1] = max(dp[i - 1][0] + action[i][1], dp[i - 1][2] + action[i][1]);
        dp[i][2] = max(dp[i - 1][0] + action[i][2], dp[i - 1][1] + action[i][2]);

    }

    int ans = max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));

    cout << ans << endl;

    return 0;

}