#include <iostream>
#include <vector>
#include <queue>
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

    vector<int> done(n, -1);

    queue<int> q;

    q.push(0);

    done[0] = 1;

    while(!q.empty()) {

        int index = q.front(); q.pop();
        

        for(int i = 0; i < v[index].size(); ++i) {

            if(done[v[index][i]] == -1) {
                done[v[index][i]] = index + 1;
                q.push(v[index][i]);
            }

        }

    }


    bool isTrue = true;

    for(int i = 0; i < n; ++i) {
        if(done[i] == -1) {
            isTrue = false;
            break;
        }
    }

    if(isTrue) {
        cout << "Yes" << endl;
        for(int i = 1; i < n; ++i)
            cout << done[i] << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;

}