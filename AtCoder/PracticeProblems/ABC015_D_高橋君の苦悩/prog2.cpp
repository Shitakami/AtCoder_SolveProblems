    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    const int MAX_W = 10000, MAX_N = 50;

    int dp[MAX_N + 1][MAX_N + 1][MAX_W + 1];

    int main() {

        int W, N, K;

        cin >> W;
        cin >> N >> K;

        vector<pair<int, int>> s(N + 1);

        for(int i = 1; i <= N; ++i) 
            cin >> s[i].first >> s[i].second;

        for(int i = 1; i <= N; ++i) {

            for(int j = 1; j <= K; ++j) {

                for(int k = 1; k <= W; ++k) {

                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j][k - 1]);

                    if(k >= s[i].first) {

                        dp[i][j][k] = max(dp[i - 1][j - 1][k - s[i].first] + s[i].second, dp[i][j][k]);

                    }


                }
            }
        }


        cout << dp[N][K][W] << endl;

        return 0;

    }