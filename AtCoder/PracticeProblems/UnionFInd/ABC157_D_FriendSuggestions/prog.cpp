#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class UnionFind {
    public:

    vector<int> v;

    UnionFind(int n) : v(vector<int>(n, -1)) {}

    int GetParent(int a) {
        
        if(v[a] < 0)
            return a;

        return v[a] = GetParent(v[a]); 

    }

    bool Unit(int a, int b) {

        int p_a = GetParent(a);
        int p_b = GetParent(b);

        if(p_a == p_b)
            return false;

        if(v[p_a] > v[p_b])
            swap(p_a, p_b);
        v[p_a] += v[p_b];
        v[p_b] = p_a;

        return true;

    }

    bool IsSame(int a, int b) {

        return GetParent(a) == GetParent(b);

    }

    int size(int a) {

        int p = GetParent(a);
        return -v[p];

    }

};

int main() {

    int N, M, K;

    cin >> N >> M >> K;

    UnionFind u(N);
    vector<set<int>> blocks(N);

    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        blocks[a].insert(b);
        blocks[b].insert(a);
        u.Unit(a, b);
    }

    for(int i = 0; i < K; ++i) {

        int a, b;
        cin >> a >> b;
        a--; b--;
        if(!u.IsSame(a, b))
            continue;
        blocks[a].insert(b);
        blocks[b].insert(a);
    }
    
    for(int i = 0; i < N; ++i) {

        int ans = u.size(i) - 1 - blocks[i].size();
        if(i)
            cout << " ";
        cout << ans;

    }

    cout << endl;

    return 0;
}