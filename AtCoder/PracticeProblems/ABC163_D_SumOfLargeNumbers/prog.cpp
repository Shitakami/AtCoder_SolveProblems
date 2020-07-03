#include <iostream>
using namespace std;

using ll = long long;

const ll mod = 1e+9 + 7;

int main() {

    ll n, k;

    cin >> n >> k;

    ll answer = 0;

    for(ll i = k; i <= n + 1; ++i) {

        ll a = i * (i - 1) / 2;
        ll b = i * (2 * n - i + 1) / 2;

        answer += (b - a) + 1;
        answer %= mod;

    }

    cout << answer << endl;

    return 0;


}