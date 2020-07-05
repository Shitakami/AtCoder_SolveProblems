#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {

    int n;
    cin >> n;

    vector<ll> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<ll>());

    ll sum = v[0];

    int even = 0;
    int index = 1;
    
    for(int i = 1; i < n - 1; ++i) {

        sum += v[index];
        even++;
        if(even % 2 == 0) {
            even = 0;
            index++;
        }

    }


    cout << sum << endl;

    return 0;


}