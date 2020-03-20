#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

int main() {

    int n;

    cin >> n;

    vector<ll> monsters(n + 1);

    for(int i = 0; i < n + 1; ++i)
        cin >> monsters[i];

    vector<ll> heros(n);

    for(int i = 0; i < n; ++i)
        cin >> heros[i];


    ll sum = 0;
    for(int i = 0; i < n; ++i) {

        sum += min(heros[i], monsters[i]);

        heros[i] = heros[i] - monsters[i];
        
        if(heros[i] > 0) {
            ll nextM = max(monsters[i + 1] - heros[i], 0ll);
            sum += monsters[i + 1] - nextM;
            monsters[i + 1] = nextM;
        }


    }


    cout << sum << endl;

    return 0;


}