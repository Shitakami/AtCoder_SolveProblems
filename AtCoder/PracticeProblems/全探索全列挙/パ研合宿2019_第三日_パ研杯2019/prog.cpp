#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


using ll = long long;

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<ll>> s(n, vector<ll>(m));


    for(int i = 0; i < n; ++i) {

        for(int j = 0; j < m; ++j) {
            cin >> s[i][j];
        }

    }

    ll ans = 0;

    for(int i = 0; i < m - 1; ++i) {

        for(int j = i + 1; j < m; ++j) {

            ll sum = 0;
            for(int s_i = 0; s_i < n; ++s_i) {

                sum += max(s[s_i][i], s[s_i][j]);

            }


            ans = max(ans, sum);

        }


    }

    cout << ans << endl;

    return 0;

}