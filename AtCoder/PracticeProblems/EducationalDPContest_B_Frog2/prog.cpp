#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> step(n);
    for(int i = 0; i < n; ++i)
        cin >> step[i];

    vector<int> dp(n, INF);

    dp[0] = 0;
    dp[1] = abs(step[0] - step[1]);


    for(int i = 2; i < n; ++i) {

        for(int j = 1; j <= k; ++j) {

            if(j > i)
                break;

            int a = dp[i - j] + abs(step[i] - step[i - j]);
            dp[i] = min(dp[i], a);


        }
    }
    
    cout << dp[n - 1] << endl;

    return 0;

}