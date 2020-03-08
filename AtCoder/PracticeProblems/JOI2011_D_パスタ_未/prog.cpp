#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int TOMATO = 1;
const int CREAM = 2;
const int BASIL = 3;
const int mod = 1e+4;

const bool isDebug = 1;

int main() {

    int n, K;

    cin >> n >> K;

    vector<int> plans(n + 1, 0);

    for(int i = 1; i <= K; ++i) {
        int day, pasta;
        cin >> day >> pasta;
        plans[day] = pasta;
    }


    vector<vector<int>> dp(n + 3, vector<int>(3 + 1, 0));

    // 1日目
    if(plans[1] == 0)
        dp[1][1] = dp[1][2] = dp[1][3] = 1;
    else
        dp[1][plans[1]] = plans[1];
    

    // 2日目
    if(plans[2] == 0) {

        for(int i = 1; i <= 3; ++i) {

            dp[2][i] = dp[1][1] + dp[1][2] + dp[1][3];

        }

    }
    else {

        dp[2][plans[2]] = dp[1][1] + dp[1][2] + dp[1][3];

    }

    // 3日以降
    for(int i = 3; i <= n; ++i) {

        if(plans[i] == 0) {
            for(int j = 1; j <= 3; ++j) {
            
                if(plans[i - 1] == 0) {
                    dp[i][j] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] - dp[i - 2][j];
                    dp[i][j] %= mod;
                }
                else {

                    dp[i][j] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
                    dp[i][j] %= mod;

                }
    
            }
        }
        else {

            if(plans[i] == plans[i - 1]) {
                
                dp[i][plans[i]] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
                dp[i][plans[i]] %= mod;
            }
            else if(plans[i - 1] == 0) {

                dp[i][plans[i]] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] - dp[i - 2][plans[i]];

            }
            else {

                dp[i][plans[i]] = dp[i - 1][plans[i - 1]];

            }

        }


    }


    if(isDebug) {
        for(int i = 1; i <= n; ++i) {
            cout << plans[i] << ":";
            for(int j = 1; j <= 3; ++j) {
                cout << dp[i][j] << "\t";
            }
            cout << endl;

        }
    }

    cout << (dp[n][1] + dp[n][2] + dp[n][3]) % mod << endl;

    return 0;

}