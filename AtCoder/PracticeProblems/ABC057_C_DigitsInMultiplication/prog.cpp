#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;

ll a(ll x) {

    ll count = 0;

    while(x > 0) {
        count++;
        x /= 10;
    }

    return count;
}

int main() {

    ll n;

    cin >> n;

    ll ans = LLONG_MAX;

    for(ll i = 1; i * i <= n; ++i) {

        if(n % i)
            continue;

        ans = min(ans, max(a(i), a(n / i)));

    }

    cout << ans << endl;

    return 0;
}