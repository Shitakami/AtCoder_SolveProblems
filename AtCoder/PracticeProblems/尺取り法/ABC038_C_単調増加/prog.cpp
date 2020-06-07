#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {

    int n;

    cin >> n;

    vector<ll> v(n + 1, 0);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    ll count = 0;
    ll right = 0;

    for(ll left = 0; left < n; ++left) {

        while(v[right] < v[right + 1]) {
            right++;
        }

        count += right - left + 1;

        if(left == right)
            right++;


    }

    cout << count << endl;

    return 0;

}