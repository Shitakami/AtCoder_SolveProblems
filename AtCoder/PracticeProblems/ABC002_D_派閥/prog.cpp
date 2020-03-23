#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
using ll = long long;


int main() {

    int n, k;

    cin >> n >> k;

    vector<ll> v(n);

    for(int i = 0; i < k; ++i) {

        ll x, y;
        cin >> x >> y;

        x--;
        y--;

        v[y] |= 1 << x;
        v[x] |= 1 << y;

    }


    for(int i = 0; i < n; ++i)
        v[i] |= 1 << i;


    int maxTranslation = 1;
    
    for(int i = 0; i < n; ++i) {
    
        ll p = v[i];

        for(int j = 0; j < n; ++j) {

            if(i == j)
                continue;

            ll bit = 1 << j;

            if(p & bit) {
                p &= v[j];
            }

        }

        int count = bitset<32>(p).count();
        maxTranslation = max(maxTranslation, count);

    }

    cout << maxTranslation << endl;

    return 0;

}