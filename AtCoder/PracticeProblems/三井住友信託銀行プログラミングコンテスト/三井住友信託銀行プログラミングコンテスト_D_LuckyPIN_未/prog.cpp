/*
 * 未だ解けていない
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> numbers(n);

    for(int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        numbers[i] = (int)(ch - '0');
    }
    vector<vector<int>> dp(3, vector<int>(n));

    for(int i = 0; i < 3; ++i) {

        set<int> s;
        for(int j = i; j < n - (3 - i); ++j) {
            s.insert(numbers[j]);
            if(i == 0) {
                dp[i][j] = s.size();
                continue;
            }

            dp[i][j] = dp[i - 1][j - 1] * s.size();
        }
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < n; ++j)
            cout << dp[i][j];
        cout << endl;
    }

    cout << dp[n - 1][n - 1] << endl;
    return 0;

}