/*
 * いくつかのテストケースでWA
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct S {


    int count;
    int length;

    S() : count(0), length(0) {}

    bool operator > (const S &a) {

        if(length == a.length)
            return count < a.count;
        
        return length > a.length;

    }


};

S dp[50 + 10][10000 + 10];

int main() {

    int w;
    int n, k;

    cin >> w;
    cin >> n >> k;

    vector<pair<int, int>> s(n + 1);

    for(int i = 1; i <= n; ++i)
        cin >> s[i].first >> s[i].second;

    // vector<vector<S>> dp(n + 1, vector<S>(w + 1));

    for(int i = 1; i <= n; ++i) {

        for(int j = 1; j <= w; ++j) {

            if(j >= s[i].first && dp[i - 1][j - s[i].first].count != k) {

                auto a = dp[i - 1][j - s[i].first];
                a.length += s[i].second;
                a.count++;
                auto b = dp[i - 1][j];
                
                dp[i][j] = a > b ? a : b;

                

            }
            else {

               dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];

            }
            // cout << dp[i][j].length << "," << dp[i][j].count << "\t";
        }

         // cout << endl;

    }

    cout << dp[n][w].length << endl;

    return 0;

}