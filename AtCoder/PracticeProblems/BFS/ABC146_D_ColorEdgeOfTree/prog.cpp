#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

    int n;
    int maxColor = 0;

    cin >> n;
    vector<vector<pair<int, int>>> edges(n + 1);
    vector<int> edgesColor(n);

    for(int i = 1; i <= n - 1; ++i) {
        int v, e;
        cin >> v >> e;
        edges[v].emplace_back(e, i);

    }

    queue<pair<int, int>> q;
    vector<pair<int, int>> answerEdges;
    q.push(make_pair(1, 0));


    while(!q.empty()) {

        auto vertex = q.front(); q.pop();
        int v = vertex.first;
        int color = vertex.second != 1 ? 1 : 2;
        
        for(int i = 0; i < edges[v].size(); ++i) {
            
            q.push(make_pair(edges[v][i].first, color));
            answerEdges.emplace_back(edges[v][i].second, color);
            
            maxColor = max(maxColor, color);

            color++;
            if(color == vertex.second)
                color++;
        }

    }

    cout << maxColor << endl;

    sort(answerEdges.begin(), answerEdges.end(), [](auto const &l, auto const &r) { return l.first < r.first; });
    for(int i = 0; i < answerEdges.size(); ++i) {
        cout << answerEdges[i].second << endl;
    }

    return 0;

}