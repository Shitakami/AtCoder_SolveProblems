#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {

    ll a, b, n;

    cin >> a >> b >> n;

    ll x = min(b - 1, n);

    cout << (a * x) / b << endl;

    return 0;


}