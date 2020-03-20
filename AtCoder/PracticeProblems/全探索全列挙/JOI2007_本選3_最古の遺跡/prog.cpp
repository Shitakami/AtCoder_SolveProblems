#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool map[5010][5010];

int main() {

    int n;

    cin >> n;

    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        map[v[i].first][v[i].second] = true;
    }

    int maxSquare = 0;
 //   cout << endl;

    for(int i = 0; i < n; ++i) {

        for(int j = 0; j < n; ++j) {

            if(i == j)
                continue;

            int diffX = v[j].first - v[i].first;
            int diffY = v[j].second - v[i].second;

            int point1X = v[i].first + diffY;
            int point1Y = v[i].second - diffX;

            if(point1X < 0 || 5000 < point1X ||
                point1Y < 0 || 5000 < point1X)
                continue;

            if(!map[point1X][point1Y])
                continue;

            int point2X = v[j].first + diffY;
            int point2Y = v[j].second - diffX;

            if(point2X < 0 || 5000 < point2X ||
                point2Y < 0 || 5000 < point2Y)
                continue;

            if(!map[point2X][point2Y])
                continue;

            int square = diffX*diffX + diffY*diffY;
            //cout << square << endl << endl;
            maxSquare = max(maxSquare, square);
        }
        
    }

    cout << maxSquare << endl;


    return 0;
}