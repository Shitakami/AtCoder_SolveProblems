#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main() {

    int n;

    while(1) {

        cin >> n;

        if(n == 0)
            break;

        vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = dp[0] + dp[1];

        for(int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

       //  cout << dp[n] << endl;

        int count = 0;
        while(dp[n] > 0) {
            dp[n] -= 3650;
            count++;

        }
        cout << count << endl;
    }

    return 0;
}