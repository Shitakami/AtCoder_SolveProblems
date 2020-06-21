#include <iostream>
using namespace std;

using ll = long long;

int main() {

    ll n, x;

    cin >> n >> x;

    ll count = 0;

    if(x % 2) {
        ll a = n / x;

        count = a * a * a;

    }
    else {

        ll a = n / x;

        count = a * a * a;

        ll b = x / 2;
        ll c;
       // cout << a * x << endl;
       // cout << n - a * x << endl;
        if(n - a * x < b)
            c = a;
        else
            c = a + 1;

       // cout << c << endl;
        count += c * c * c;

    }


    cout << count << endl;

    return 0;

}