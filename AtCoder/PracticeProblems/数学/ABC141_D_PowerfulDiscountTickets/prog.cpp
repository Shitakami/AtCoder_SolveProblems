#include <iostream>
#include <queue>
using namespace std;

int main() {

    int n, m;

    priority_queue<int> money;

    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        money.push(a);
    }

    for(int i = 0; i < m; ++i) {
        int v;
        v = money.top(); money.pop();
        v /= 2;
        money.push(v);
    }

    long long sum = 0;
    while(!money.empty()) {
        sum += money.top(); money.pop();
    }
    
    cout << sum << endl;

    return 0;

}