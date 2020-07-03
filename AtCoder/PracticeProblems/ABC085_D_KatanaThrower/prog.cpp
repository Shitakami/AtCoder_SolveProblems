#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {

    ll n, h;

    cin >> n >> h;

    vector<ll> attack(n);
    vector<ll> throwing(n);

    for(int i = 0; i < n; ++i)
        cin >> attack[i] >> throwing[i];

    ll maxAttack = 0;
    ll sumThrowing = 0;
    ll throwingCount = 0;

    for(int i = 0; i < n; ++i)
        maxAttack = max(maxAttack, attack[i]);
    
    sort(throwing.begin(), throwing.end(), greater<ll>());

    for(int i = 0; i < n; ++i) {
        if(maxAttack < throwing[i]) {
            sumThrowing += throwing[i];
            throwingCount++;
            if(sumThrowing >= h)
                break;
        }
    }

    
    h -= sumThrowing;
    if(h < 0)
        h = 0;

    ll ansCount = (h / maxAttack) + throwingCount;
    if(h % maxAttack)
        ansCount++;

    cout << ansCount << endl;

    return 0;

}