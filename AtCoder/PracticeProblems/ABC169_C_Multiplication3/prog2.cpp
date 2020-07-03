#include <iostream>
using namespace std;
using ll = long long;

int main() {

    long double b;
    ll a;
    cin >> a >> b;

    ll ans = a * (ll)((b + 0.0001) * 100);

    cout << ans / 100 << endl;

    return 0;


}