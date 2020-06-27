#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {

    ll n;

    cin >> n;

    vector<ll> v(n + 1, 2);

    v[1] = 1;

    for(ll i = 2; i * 2 <= n; ++i) {

        for(ll j = 2; i * j <= n; ++j)
            v[i * j]++;

    }

    ll answer = 0;
    for(int i = 1; i <= n; ++i) {
        answer += v[i] * i;
    }

    cout << answer << endl;



}