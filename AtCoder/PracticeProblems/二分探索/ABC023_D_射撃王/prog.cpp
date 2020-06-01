#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
 
using ll = long long;
 
int main() {
 
    int n;
 
    cin >> n;
 
    vector<pair<ll, ll>> v(n);
 
    auto func = [&](const pair<int, ll> &a, const pair<int, ll> &b) { return a.second < b.second; };
 
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, decltype(func)> q(func);
 
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        auto newP = make_pair(i, v[i].first + v[i].second * (n - 1));
        q.push(newP);
    }
 
 
    int time = 0;
    ll maxP = 0;
 
    while(time != n) {
        
        auto x = q.top(); q.pop();
       // cout << x.second << endl;
        int index = x.first;
        ll p = v[index].first + time * v[index].second;
 
 
        maxP = max(maxP, p);
 
        time++;
    }
 
    cout << maxP << endl;
 
    return 0;
 
}