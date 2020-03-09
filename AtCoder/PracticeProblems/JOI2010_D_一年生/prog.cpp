#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

int main() {


    int n;
    cin >> n;

    vector<int> numbers(n + 1);

    for(int i = 1; i <= n; ++i)
        cin >> numbers[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(20 + 1, 0));

    dp[1][numbers[1]] = 1;

    for(int i = 2; i < n; ++i) {

        for(int j = 0; j <= 20; ++j) {

            if(dp[i - 1][j] == 0)
                continue;

            int minusIndex = j - numbers[i];
            int plusIndex = j + numbers[i];

            if(0 <= minusIndex && minusIndex <= 20) {
                dp[i][minusIndex] = dp[i - 1][j] + dp[i][minusIndex];
            }

            if(0 <= plusIndex && plusIndex <= 20) {
                dp[i][plusIndex] = dp[i - 1][j] + dp[i][plusIndex];
            }


        }
        
    }


    cout << dp[n - 1][numbers[n]] << endl;

    return 0;
}