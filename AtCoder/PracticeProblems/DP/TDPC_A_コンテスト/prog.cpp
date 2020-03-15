#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cin >> n;

    int sum = 0;
    vector<int> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    dp[0][0] = true;

    for(int i = 0; i < n; ++i) {
        
        int dp_i = i + 1;
        for(int j = 0; j <= sum; ++j) {
            
            if(v[i] <= j)
                dp[dp_i][j] = dp[dp_i - 1][j - v[i]] || dp[dp_i - 1][j];
            else
                dp[dp_i][j] = dp[dp_i - 1][j];

        }
        
    }


    int count = 0;
    for(int i = 0; i <= sum; ++i)
        if(dp[n][i])
            count++;

    cout << count << endl;

    return 0;

}