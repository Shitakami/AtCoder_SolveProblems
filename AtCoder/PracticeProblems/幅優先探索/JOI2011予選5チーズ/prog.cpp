#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {

    int H, W, n;

    cin >> H >> W >> n;

    const int wall = -1;
    const int load = 0;

    vector<vector<int>> map(H + 2, vector<int>(W + 2, wall));

    int starti;
    int startj;

    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            char ch;
            cin >> ch;
            if(ch == '.')
                map[i][j] = load;
            else if(ch == 'X')
                map[i][j] = wall;
            else if(ch == 'S') {
                map[i][j] = load;
                starti = i;
                startj = j;
            }
            else
                map[i][j] = (int)(ch - '0');


        }
    }

    /*    
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j)
            cout << map[i][j];
        cout << endl;
    }
    */
   
    struct Pos {
        int i;
        int j;
        int distance;
        Pos(int i, int j, int distance) : i(i), j(j), distance(distance) {}
    };

    int sum = 0;

    for(int goal = 1; goal <= n; ++goal) {

        queue<Pos> q;
        set<pair<int, int>> visited;
        q.push(Pos(starti, startj, 0));

        while(!q.empty()) {

            auto pos = q.front(); q.pop();
            if(map[pos.i][pos.j] == goal) {
                sum += pos.distance;
                starti = pos.i;
                startj = pos.j;
                break;
            }

            for(int i = 0; i < 4; ++i) {
                pair<int, int> n_pos = make_pair(pos.i, pos.j);
                n_pos.first += dx[i];
                n_pos.second += dy[i];
                if(map[n_pos.first][n_pos.second] != -1 && visited.find(n_pos) == visited.end()) {
                    q.push(Pos(n_pos.first, n_pos.second, pos.distance + 1));
                    visited.emplace(n_pos);
                }

            }

        }
    }

    cout << sum << endl;

    return 0;


}