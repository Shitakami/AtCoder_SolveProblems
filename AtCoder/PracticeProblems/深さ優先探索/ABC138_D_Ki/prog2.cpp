#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

    int n, q;

    cin >> n >> q;
    vector<vector<int>> tree(n);

    for(int i = 1; i < n; ++i) {

        int from, to;
        cin >> from >> to;

        from--;
        to--;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    vector<int> values(n, 0);

    for(int i = 0; i < q; ++i) {
        int node, value;
        cin >> node >> value;

        values[node - 1] += value;
    }

    stack<pair<int, int>> s;
    vector<int> answers(n);
    vector<bool> visited(n, false);

    s.push(make_pair(0, 0));


    while(!s.empty()) {

        auto node = s.top(); s.pop();
        int index = node.first;

        if(visited[index])
            continue;
        visited[index] = true;

        int sum = node.second + values[index];
        answers[index] = sum;

        for(int i = 0; i < tree[index].size(); ++i) {

            s.push(make_pair(tree[index][i], sum));

        }

    }

    for(int i = 0; i < n; ++i) {
        if(i)
            cout << " ";
        cout << answers[i];
    }

    cout << endl;

    return 0;

}