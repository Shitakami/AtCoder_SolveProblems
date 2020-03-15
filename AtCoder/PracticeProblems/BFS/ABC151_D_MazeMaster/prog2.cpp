#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

struct Map {
public:
    int i, j;
    int distance;
    
    Map(int i, int j, int distance) : i(i), j(j), distance(distance) {}

};

int main() {

    int h, w;
    char mapData[30][30];
    set<pair<int, int>> doneRoot;

    int firstI = 0;
    int firstJ = 0;

    cin >> h >> w;

    for(int i = 1; i <= h; ++i) {
        mapData[i][0] = '#';
        mapData[i][w + 1] = '#';
        for(int j = 1; j <= w; ++j) {

            cin >> mapData[i][j];

        }
    }

    for(int i = 0; i <= w + 1; ++i) {
        mapData[0][i] = '#';
        mapData[h + 1][i] = '#';
    }


    int maxDistance = 0;
    for(int a = 1; a <= h; a++) {

        for(int b = 1; b <= w; b++) {
            if(mapData[a][b] == '#')
                continue;

    
      queue<Map> que;
      que.push(Map(a, b, 0));
      doneRoot.emplace(make_pair(a, b));
      auto lastPos = que.front();

      while(!que.empty()) {

          auto nowPos = que.front();
          que.pop();

          int i = nowPos.i;
          int j = nowPos.j;
          int d = nowPos.distance;

          if(mapData[i - 1][j] != '#' && doneRoot.find(pair<int, int>(i - 1, j)) == doneRoot.end()) {
              que.push(Map(i - 1, j, d + 1));
              doneRoot.emplace(make_pair(i - 1, j));
          }

          if(mapData[i + 1][j] != '#' && doneRoot.find(pair<int ,int>(i + 1, j)) == doneRoot.end()) {
              que.push(Map(i + 1, j, d + 1));
              doneRoot.emplace(make_pair(i + 1, j));

          }

          if(mapData[i][j - 1] != '#' && doneRoot.find(pair<int ,int>(i, j - 1)) == doneRoot.end()) {
              que.push(Map(i, j - 1, d + 1));
              doneRoot.emplace(make_pair(i, j - 1));
          }

          if(mapData[i][j + 1] != '#' && doneRoot.find(pair<int ,int>(i, j + 1)) == doneRoot.end()) {
              que.push(Map(i, j + 1, d + 1));
              doneRoot.emplace(make_pair(i, j + 1));
          }


          // cout << i << " " << j << " " << d << endl;

          lastPos = nowPos;

      }

        doneRoot.clear();
        if(lastPos.distance > maxDistance) 
            cout << lastPos.i << " " << lastPos.j << endl;

        maxDistance = max(lastPos.distance, maxDistance);
        }
    }


    cout << maxDistance << endl;

    return 0;

}