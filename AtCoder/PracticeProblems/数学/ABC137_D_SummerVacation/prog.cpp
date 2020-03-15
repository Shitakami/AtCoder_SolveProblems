#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {

    int n, m;

    cin >> n >> m;
    auto pf = [&](const pair<int, int> &a, const pair<int, int> &b) { return a.first > b.first; };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(pf)> works(pf);


    for(int i = 0; i < n; ++i) {
        pair<int, int> w;
        cin >> w.first >> w.second;
        works.push(w);
    }


    auto ps = [&](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(ps)> works_Value(ps);

    int day = 1;
    int sum = 0;

    while(day <= m) {
     
        while(!works.empty() && works.top().first <= day) {
            works_Value.push(works.top());
            works.pop();
        }

        if(!works_Value.empty()) {
            sum += works_Value.top().second;
            works_Value.pop();
        }
        day++;

    }

    cout << sum << endl;
    return 0;

}