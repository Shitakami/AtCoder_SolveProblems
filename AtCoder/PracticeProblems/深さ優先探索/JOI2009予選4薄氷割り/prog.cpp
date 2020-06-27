#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

void dfs(vector<vector<bool>> &map, int i, int j, int distance) {

    answer = max(answer, distance);
    map[i][j] = false;

    for(int k = 0; k < 4; ++k) {
        
        if(map[i + di[k]][j + dj[k]])
            dfs(map, i + di[k], j + dj[k], distance + 1);


    }

    map[i][j] = true;

}


int main() {

    int n, m;

    cin >> m;
    cin >> n;

    vector<vector<bool>> map(n + 2, vector<bool>(m + 2, false));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {

            int num;
            cin >> num;
            if(num == 0)
                map[i][j] = false;
            else
                map[i][j] = true;

        }
    }


    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {

            if(map[i][j])
                dfs(map, i, j, 1);


        }
    }

    cout << answer << endl;

    return 0;

}