#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

const int MAX = 1e+5 + 10;
const int INF = INT_MAX;
using ll = long long;
ll dp[100 + 10][MAX];

int main() {

    int n, max_w;

    cin >> n >> max_w;

    vector<pair<int, int>> w(n + 1);

    int sum = 0;

    for(int i = 1; i <= n; ++i) {

        cin >> w[i].first >> w[i].second;
        sum += w[i].second;
    }


    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= sum; ++j) {
            if(j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
        }

    }

    for(int i = 1; i <= n; ++i) {

        for(int j = 1; j <= sum; ++j) {

            if(j < w[i].second) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
                
            
            
            dp[i][j] = min(dp[i - 1][j - w[i].second] + w[i].first, dp[i - 1][j]);
            

        }


    }

    /*
    for(int i = 0; i <= sum; ++i)
        printf("%3d ", i);
    cout << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= sum; ++j) {
            if(dp[i][j] == INF) 
                cout << "INF";
            else
                printf("%3d", dp[i][j]);
            cout << " ";

        }
        cout << endl;
    }
*/

    for(int i = sum; i >= 0; --i) {
        if(dp[n][i] <= max_w) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}