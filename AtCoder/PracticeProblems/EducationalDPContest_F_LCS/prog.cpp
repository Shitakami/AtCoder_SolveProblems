/*
 * 未だ解けていない
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    string s1;
    string s2;

    cin >> s1 >> s2;


    vector<vector<string>> dp(s1.length() + 10, vector<string>(s2.length() + 10, ""));

    for(int i = 1; i <= s1.length(); ++i) {
        for(int j = 1; j <= s2.length(); ++j) {

            int si = i - 1;
            int sj = j - 1;

            if(s1[si] == s2[sj] && dp[i - 1][j - 1].length() + 1 > dp[i - 1][j].length()) 
                dp[i][j] = dp[i - 1][j - 1] + s1[si];
            else {
                int aboveSize = dp[i - 1][j].length();
                int leftSize = dp[i][j - 1].length();


                if(aboveSize > leftSize)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
                         
            }
             
        }
    }

    /*
    for(int i = 1; i <= s1.length(); ++i) {

        for(int j = 1; j <= s2.length(); ++j) {
            cout << "\t" << dp[i][j];


        }
        cout << endl;
    }
*/

    cout << dp[s1.length()][s2.length()] << endl;

    return 0;

}