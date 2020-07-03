#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using ll = long long;

const ll mod = 1e+9 + 7;

int main() {

    int n;

    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> q;

    for(int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        q.push(x);
    }

    int d = 1;

    if(n % 2) {

        ll value = q.top(); q.pop();
        if(value != 0) {
            cout << 0 << endl;
            return 0;
        }

        d = 2;

    }

    ll answer = 1;

    while(!q.empty()) {

        ll x1 = q.top(); q.pop();
        ll x2 = q.top(); q.pop();

        if(x1 != x2 || x1 != d) {
            cout << 0 << endl;
            return 0;
        }

        answer *= 2;
        answer %= mod;
        d += 2;
    }

    cout << answer << endl;
    return 0;

    return 0;

}