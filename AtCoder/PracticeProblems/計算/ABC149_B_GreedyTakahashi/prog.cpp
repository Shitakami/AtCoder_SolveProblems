#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {

    ll A, B, K;

    cin >> A >> B >> K;

    ll a = max(A - K, (ll)0);
    ll b;

    K = max(K - A, (ll)0);
    b = max(B - K, (ll)0);

    cout << a << " " << b << endl;
    return 0;
}