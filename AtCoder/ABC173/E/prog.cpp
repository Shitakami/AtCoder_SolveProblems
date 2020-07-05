#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

using ll = long long;

const ll mod = 1e+9 + 7;

long long cmod(long long val) {
  long long res = val % mod;
  if (res < 0) res += mod;
  return res;
}

int main() {

    int n, k;

    cin >> n >> k;

    vector<ll> v(n);
    vector<pair<ll, bool>> nums(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        nums[i].first = abs(v[i]);
        nums[i].second = v[i] < 0;
    }


    sort(nums.begin(), nums.end(), [&](const pair<ll, bool> &a, const pair<ll, bool> &b) { return a.first > b.first; } );

    for(int i = 0; i < n; ++i) {
        cout << nums[i].first << " " << nums[i].second << endl;
    }

    int index = 0;
    ll ans1 = 1;
    for(int i = 0; i < k; ++i) {
        ans1 *= nums[i].first;
        if(nums[i].second)
            ans1 *= -1;
        ans1 = cmod(ans1);

    }

    cout << "1 " << ans1 << endl;

    ll ans2 = -LLONG_MAX;

        bool oneMinus = true;
        ll tempAns = 1;
        for(int i = k - 1; i >= 0; i--) {
            if(oneMinus && nums[i].second) {
                oneMinus = false;
                continue;
            }
            tempAns *= nums[i].first;
        }
        int x = k;
        for(; x < n; ++x) {
            if(nums[x].second)
                continue;
            tempAns *= nums[x].first;
            tempAns = cmod(tempAns);
            break;
        }

        if(x != n)
            ans2 = tempAns;
    
    cout << "2 " << ans2 << endl;


    ll ans3 = -LLONG_MAX;
    tempAns = 1;

    int minusCount = 0;
    for(int i = k - 1; i >= 0; --i) {
        if(minusCount != 2 && nums[i].second) {
            minusCount++;
            continue;
        }
        tempAns *= nums[i].first;
        tempAns = cmod(tempAns);
    }
    int plusCount = 0;
    x = k;
    for(; x < n; ++x) {
        if(nums[x].second)
            continue;
        tempAns *= nums[x].first;
        tempAns = cmod(tempAns);
        plusCount++;
        if(plusCount == 2)
            break;
    }


    ans3 = tempAns;

    cout << "3 " << ans3 << endl;

    ll ans4 = 1;
    for(int i = 0; i < k; ++i) {
        ans4 *= nums[n - i - 1].first;
        if(nums[n - i - 1].second)
            ans4 *= -1;
        ans4 = cmod(ans4);
    }

    cout << "4 " << ans4 << endl;

    cout << max(ans1, max(ans2, max(ans3, ans4))) << endl;

    return 0;


}