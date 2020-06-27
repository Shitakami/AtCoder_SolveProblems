#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> answers;

void dfs(const vector<vector<int>> &tree, const vector<int> &values, int node, int sum) {

    sum += values[node];
    answers[node] = sum;
    for(int i = 0; i < tree[node].size(); ++i) {
        dfs(tree, values, tree[node][i], sum);
    }

}

int main() {

    int n, q;
    cin >> n >> q;

    vector<vector<int>> tree(n);
    answers.resize(n);

    for(int i = 1; i < n; ++i) {
        int from, to;

        cin >> from >> to;

        from--;
        to--;
        
        tree[from].push_back(to);        

    }

    vector<int> values(n, 0);

    for(int i = 0; i < q; ++i) {

        int node, x;
        cin >> node >> x;

        values[node - 1] += x;

    }

    dfs(tree, values, 0, 0);

    for(int i = 0; i < n; ++i) {
        if(i)
            cout << " ";
        cout << answers[i];
    }

    cout << endl;

    return 0;


}