#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {

    int n;
    cin >> n;

    vector<ll> a(n), b(n), c(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    for(int i = 0; i < n; ++i)
        cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll sum = 0;

    for(int i = 0; i < n; ++i) {

        auto a_itr = lower_bound(a.begin(), a.end(), b[i]);
        auto c_itr = upper_bound(c.begin(), c.end(), b[i]);

        ll aCount = a_itr - a.begin();
        ll cCount = c.end() - c_itr;

        sum += aCount * cCount;

    }

    cout << sum << endl;

    return 0;

}