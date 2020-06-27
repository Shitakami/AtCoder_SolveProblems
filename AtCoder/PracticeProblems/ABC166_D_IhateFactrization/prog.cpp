#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll maxValue = 1e+9;

ll myPow(ll x, int n) {

    ll retValue = 1;

    while(n > 0) {

        if(n & 1) {
            retValue *= x;
            n--;
        }
        else {
            x *= x;
            n >>= 1;
        }

    }

    return retValue;
}

int main() {

    ll x;
    cin >> x;

    ll a, b;
    a = -1000;

    while(1) {

        ll left = -1000, right = 1000;
        ll a5 = myPow(a, 5);
        ll sum;
        ll mid;
        while(right - left > 1) {
            mid = (right + left) / 2;
            sum = a5 - myPow(mid, 5);

            if(x > sum)
                right = mid;
            else
                left = mid;

        }

        if(sum == x) {
            b = mid;
            break;
        }

        a++;

    }
    

   cout << a << " " << b << endl;

    return 0;
}