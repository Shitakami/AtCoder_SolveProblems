#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;


int main() {

    int h, w;
    pair<int, int> startPos;
    pair<int, int> endPos;
    cin >> h >> w;

    cin >> startPos.first >> startPos.second;
    cin >> endPos.first >> endPos.second;

    startPos.first--;
    startPos.second--;

    endPos.first--;
    endPos.second--;

    vector<vector<bool>> maze(h, vector<bool>(w));
    vector<vector<int>> distance(h, vector<int>(w, -1));

    distance[startPos.first][startPos.second] = 0;

    for(int i = 0; i < h; ++i) {

        for(int j = 0; j < w; ++j) {
            char ch;

            cin >> ch;

            if(ch == '#')
                maze[i][j] = false;
            else
                maze[i][j] = true;

        }
    }



    queue<pair<int, int>> q;
    q.push(startPos);

    
    const int dx[] = { 1, 0, -1,  0};
    const int dy[] = { 0, 1,  0, -1};
    int ans;

    while(!q.empty()) {

        auto pos = q.front(); q.pop();

        int count = distance[pos.first][pos.second];

        if(pos == endPos)
            break;


        for(int i = 0; i < 4; ++i) {
            int x = pos.second + dx[i];
            int y = pos.first + dy[i];

            if(maze[y][x] && distance[y][x] == -1) {
                q.push(make_pair(y, x));
                distance[y][x] = count + 1;

            }
        }

    }

    
    cout << distance[endPos.first][endPos.second] << endl;

    return 0;


}