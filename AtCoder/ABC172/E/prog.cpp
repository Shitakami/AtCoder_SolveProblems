#include <iostream>
using namespace std;

using ll = long long;

const ll mod = 1e+9 + 7;

int main() {

    ll n, m;

    cin >> n >> m;

    ll answer = 1;
    for(int i = m; i >= n; --i)
        answer = (answer * i) % mod;

    answer = (answer * (m - 1)) % mod;

    cout << answer << endl;

    return 0;


}