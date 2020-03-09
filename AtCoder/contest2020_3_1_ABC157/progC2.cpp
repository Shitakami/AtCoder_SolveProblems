#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main() {

    int n, m;

    cin >> n >> m;

    if(n == 0)
        n = 1;

    vector<set<int>> number(n);

    for(int i = 0; i < m; ++i) {

        int k, num;
        cin >> k >> num;
        k--;

        number[k].insert(num);

    }

    for(int i = 0; i < n; ++i) {
        if(number[i].size() > 1) {
            cout << -1 << endl;
            return 0;
        }
    }


    auto get = [&](int k) {
        if(number[k].size() == 0)
            return -1;
        
        for(int i = 0; i < 9; ++i) {
            if(number[k].find(i) != number[k].end())
                return i;
        }

        return -1;
    };

    if(get(0) == 0) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < n; ++i) {
        int g = get(i);
        if(i == 0 && g == -1) {
            cout << 1;
            continue;
        }

        
        if(g == -1) {
            cout << 0;
        }
        else
            cout << g;
    }

    cout << endl;

    return 0;

}