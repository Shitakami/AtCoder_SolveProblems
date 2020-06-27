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