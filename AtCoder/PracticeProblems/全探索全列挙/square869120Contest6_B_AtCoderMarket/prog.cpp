#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

using ll = long long;

int main() {

    int n;

    cin >> n;

    vector<ll> startPos(n);
    vector<ll> endPos(n);

    for(int i = 0; i < n; ++i) {
        cin >> startPos[i] >> endPos[i];
    }

    ll ans = LLONG_MAX;

    for(int i = 0; i < n; ++i) {

        for(int j = 0; j < n; ++j) {

            ll second = 0;
            for(int k = 0; k < n; ++k) {

                second += abs(startPos[i] - startPos[k]);

                second += endPos[k] - startPos[k];

                second += abs(endPos[k] - endPos[j]);

            }
            ans = min(second, ans);

        }

    }

    cout << ans << endl;

    return 0;

}