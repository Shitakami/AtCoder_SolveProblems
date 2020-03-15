#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll MAX = 1e+12;

ll GCD(ll a, ll b) {

    if(b > a)
        swap(a, b);

    ll c = a % b;
    while(c != 0) {

        a = b;
        b = c;
        c = a % b;
        
    }

    return b;

}

int main() {

    ll a, b;
    vector<ll> num;
    ll n;

    cin >> a >> b;

    n = GCD(a, b);

    for(ll i = 2; i * i <= n; ++i) {
        if(n % i != 0)
            continue;

        num.push_back(i);
        while(n % i == 0) {
            n /= i;

        }

    }
    if(n != 1)
        num.push_back(n);


    cout << num.size() + 1 << endl;

    return 0;



}