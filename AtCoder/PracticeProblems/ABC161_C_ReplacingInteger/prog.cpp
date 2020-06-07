#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    using ll = long long;

    ll n, k;

    cin >> n >> k;

    ll mod = n % k;

    cout << min(mod, k - mod) << endl;

    return 0;

}