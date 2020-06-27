#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {

    ll n1, n2, time;

    cin >> n1 >> n2 >> time;

    vector<ll> v1(n1 + 1);
    vector<ll> v2(n2 + 1);

    v1[0] = 0;
    v2[0] = 0;

    for(int i = 1; i <= n1; ++i) {
        ll num;
        cin >> num;

        v1[i] += num + v1[i - 1];

    }


    for(int i = 1; i <= n2; ++i) {
        ll num;

        cin >> num;


        v2[i] += num + v2[i - 1];
    }


    ll answer = 0;
    for(int i = 0; i <= n1; ++i) {

        if(v1[i] > time)
            break;

        ll left = 0;
        ll right = n2 + 1;

        while((right - left) > 1) {

            ll mid = (right + left) / 2;

            if(v1[i] + v2[mid] > time)
                right = mid;
            else
                left = mid;

        }

        answer = max(answer, i + left);

    }

    cout << answer << endl;

    return 0;

}