#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n);

    for(int i = 0; i < m; ++i) {
        int a, b;

        cin >> a >> b;
        a--;
        b--;

        v[a].push_back(b);
        v[b].push_back(a);

    }

    for(int i = 0; i < n; ++i) {

        set<int> fri;
        set<int> ffri;
        queue<int> q;

        fri.insert(i);

        for(int j = 0; j < v[i].size(); j++) {
            fri.insert(v[i][j]);
            q.push(v[i][j]);
        }

        while(!q.empty()) {

            int index = q.front(); q.pop();

            for(int j = 0; j < v[index].size(); ++j) {
                if(fri.find(v[index][j]) == fri.end())
                    ffri.insert(v[index][j]);
            }

        }

        cout << ffri.size() << endl;

    }

    return 0;

}