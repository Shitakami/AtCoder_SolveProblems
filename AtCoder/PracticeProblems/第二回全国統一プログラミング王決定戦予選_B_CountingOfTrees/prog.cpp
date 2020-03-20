#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

using ll = long long;

ll mod = 998244353;

ll mypow(ll m, ll x) {

    if(x == 0)
        return 1;

    if(x % 2 == 0)
        return mypow((m * m) % mod, x / 2);
    else
        return (m * mypow(m, x - 1) ) % mod;


}


int main() {

    int n;

    cin >> n;

    vector<ll> distanceCount(n, 0);
    ll maxDistance = 0;

    bool flag = true;

    for(ll i = 0; i < n; ++i) {
        ll num;
        cin >> num;

        if(!i && num != 0)
            flag = false;

        distanceCount[num]++;

        maxDistance = max(maxDistance, num);

    }

    if(distanceCount[0] != 1 || !flag) {
        cout << 0 << endl;
        return 0;
    }


    ll answer = distanceCount[0];
    for(ll i = 1; i <= maxDistance; ++i) {
      //  cout << i << " " << distanceCount[i] << endl;
        answer = (answer * mypow(distanceCount[i - 1], distanceCount[i])) % mod;
    }

    cout << answer << endl;

    return 0;

}