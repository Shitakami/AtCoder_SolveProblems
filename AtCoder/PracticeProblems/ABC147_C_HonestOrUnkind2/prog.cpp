#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {

    const int none = -1;
    const int True = 1;
    const int False = 0;


    int n;
    cin >> n;

    vector<vector<pair<int, int>>> members(n);

    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        members[i] = vector<pair<int, int>>(num);
        for(int j = 0; j < num; ++j) {
            int x, y;
            cin >> x >> y;
            members[i][j].first = x;
            members[i][j].second = y;

        }
    }

    decltype(auto) CorrectNetwork = [&]() {

        bool isTrue = true;
        vector<int> isHonest(n, none);
        set<int> doneConfirm;
        queue<int> q;

        doneConfirm.emplace(0);
        q.push(0);

        while(!q.empty()) {

            int member = q.front; q.pop();
            for(const auto &m : members[member]) {

                if(isHonest[m.first] == none) {
                    isHonest[m.first] = m.second;
                    q.push(m.first);
                    continue;
                }
                
                if(isHonest[m.first] != m.second)
                    return false;
            }

        }

        return true;

    };



    return 0;

}