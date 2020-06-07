#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;

int main() {

    int n;
    ll k;
    bool has0 = false;


    cin >> n >> k;

    vector<ll> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        has0 |= v[i] == 0;
    }

    if(has0) {
        cout << n << endl;
        return 0;
    }

    ll answer = 0;

    ll right = 0;
    ll multi = -1;

    for(ll left = 0; left < n; ++left) {

        while(right < n && abs(multi) * v[right] <= k) {
            multi = abs(multi) * v[right];
            ++right;
        }

        answer = max(answer, right - left);        

        if(left == right) {
            multi = -1;
            right++;
        }
        else {
            if(v[left] != 0)
                multi /= v[left];

        }
            

    }

    cout << answer << endl;

}