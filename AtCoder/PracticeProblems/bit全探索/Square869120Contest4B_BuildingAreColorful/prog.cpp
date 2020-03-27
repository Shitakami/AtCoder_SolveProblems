#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

using ll = long long;

int n, k;
ll minValue = LLONG_MAX;

vector<ll> b;

void Calc(int index, int kCount, ll prevHeight, ll value) {

    if(kCount == k) {
        minValue = min(value, minValue);
        return;
        
    }

    ll maxHeight = -1;

    for(int i = index; i >= 0; --i)
        maxHeight = max(maxHeight, b[i]);

    if(maxHeight > prevHeight)
        prevHeight = maxHeight;

    for(int i = index + 1; i < n; ++i) {

        if(b[i] > prevHeight) {
            Calc(i, kCount + 1, b[i], value);
        }
        else {
            Calc(i, kCount + 1, prevHeight + 1, value + prevHeight - b[i] + 1);
        }
    }
}


int main() {

    cin >> n >> k;

    b.resize(n);

    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    Calc(0, 1, b[0], 0);
    cout << minValue << endl;
    return 0;
}