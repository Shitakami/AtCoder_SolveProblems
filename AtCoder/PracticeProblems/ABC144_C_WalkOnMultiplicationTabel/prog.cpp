#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

using ll = long long;


int main() {
    ll n;

    cin >> n;

    ll minSum = LLONG_MAX;
    pair<ll, ll> comb;

    for(ll i = 1; i * i <= n; ++i) {
        
        if(n % i != 0)
            continue;
        
        ll div = n / i;
        ll sum = i + div;
        if(sum < minSum) {
            minSum = sum;
            comb = make_pair(i, div);
        }

    }
    
    cout << comb.first + comb.second - 2 << endl;

    return 0;

}