#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

int main() {

    ll a, b, c;

    cin >> a >> b >> c;

    ll aa = a * a;
    ll bb = b * b;
    ll cc = c * c;

    ll left = a + b - c;

    if(left >= 0) {
        cout << "No";
        return 0;
    }

    ll x = aa + bb + cc + 2*a*b - 2*b*c - 2*c*a;


    if(x > 4*a*b)
        cout << "Yes";
    else
        cout << "No";
    
    cout << endl;

    return 0;


}