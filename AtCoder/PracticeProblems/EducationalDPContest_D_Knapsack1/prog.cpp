#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

using ll = long long;

const int MAX = 1e+5 + 10;

ll dp[100 + 5][MAX];
pair<int, ll> w[100 + 5];

int main() {

    int n, max_w;

    cin >> n >> max_w;

    for(int i = 1; i <= n; ++i) {
        cin >> w[i].first >> w[i].second;
    }

    for(int i = 1; i <= n; ++i) {

        for(int j = 1; j <= max_w; ++j) {

            if(j < w[i].first) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j - w[i].first] + w[i].second, dp[i - 1][j]);
        }
    }

/*
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= max_w; ++j)
            printf("%3d ", dp[i][j]);
        cout << endl;
    }
*/

    cout << dp[n][max_w] << endl;

    return 0;

}