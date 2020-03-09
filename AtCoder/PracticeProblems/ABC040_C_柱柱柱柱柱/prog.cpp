#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    vector<int> dp(n);
    
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);

    for(int i = 2; i < n; ++i) {

        int a = abs(v[i] - v[i - 2]) + dp[i - 2];
        int b = abs(v[i] - v[i - 1]) + dp[i - 1];

        dp[i] = min(a, b);
   //     cout << dp[i] << " ";
    }

 //   cout << endl;


    cout << dp[n - 1] << endl;

    return 0;

}