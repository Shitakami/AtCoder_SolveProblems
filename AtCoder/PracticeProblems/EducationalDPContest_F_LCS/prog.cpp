/*
 * 未だ解けていない
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


const int MAX = 3000 + 10;

int dp[MAX][MAX];


int main() {

    string s1;
    string s2;

    cin >> s1 >> s2;


    // vector<vector<int>> dp(s1.length() + 10, vector<int>(s2.length() + 10, 0));


    for(int i = 1; i <= s1.length(); ++i) {
        for(int j = 1; j <= s2.length(); ++j) {

            int si = i - 1;
            int sj = j - 1;

            if(s1[si] == s2[sj] && dp[i - 1][j - 1] + 1 > dp[i - 1][j]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else {
                int aboveSize = dp[i - 1][j];
                int leftSize = dp[i][j - 1];


                if(aboveSize > leftSize)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
                         
            }
             
        }
    }

    /*
    for(int i = 0; i <= s1.length(); ++i) {
        
        if(i != 0)
            cout << s1[i - 1];

        for(int j = 0; j <= s2.length(); ++j) {

            if(i == 0) {
                if(j == 0)
                    cout << "\t";
                else
                    cout << s2[j - 1] << "\t";
            }

            else {
                if(j == 0)
                    cout << "";
                else
                    cout << "\t" << dp[i][j];

            }
        }
        cout << endl;
    }
*/
    string s;
    int i = s1.length(), j = s2.length();
    while(i != 0 && j != 0) {

        while(j != 0 && dp[i][j - 1] == dp[i][j])
            j--;
        while(i != 0 && dp[i - 1][j] == dp[i][j])
            i--;

        if(j == 0)
            break;
        s = s2[j - 1] + s;
      //  cout << s2[j - 1] << endl;
        i--;
        j--;
    }

    cout << s << endl;
    //cout << dp[s1.length()][s2.length()] << endl;

    return 0;

}