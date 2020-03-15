/*
 * WA
 * ある地点から一番遠い地点を見つけて
 * そこから一番遠い地点までの距離を求める
 */

#include <iostream>
#include <queue>
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

    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            if(mapData[i][j] == '#')
                continue;
            firstI = i;
            firstJ = j;

        } 

        if(firstI != 0)
            break;
    }

    queue<Map> que;
    que.push(Map(firstI, firstJ, 0));
    doneRoot.emplace(firstI, firstJ);
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
        

        cout << i << " " << j << " " << d << endl;
        if(nowPos.distance > lastPos.distance) {
            lastPos = nowPos;
        }

    }

    cout << endl << endl;
    for(int i = 0; i <= h + 1; i++) {
        for(int j = 0; j <= w + 1; j++) {

            if(lastPos.i == i && lastPos.j == j)
                cout << "*";
            else
            {
                cout << mapData[i][j];
            }

        }
        
            cout << endl;

    }

    que.push(Map(lastPos.i, lastPos.j, 0));
    doneRoot.clear();
    doneRoot.emplace(lastPos.i, lastPos.j);
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
        

        cout << i << " " << j << " " << d << endl;
        if(nowPos.distance > lastPos.distance) {
            lastPos = nowPos;
        }

    }

    cout << lastPos.distance << endl;

    return 0;

}