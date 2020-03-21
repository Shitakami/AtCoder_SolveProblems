#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> sign(n);

    for(int i = 0; i < n; ++i) {

        cin >> sign[i].first >> sign[i].second;

    }

    int m;
    cin >> m;
    vector<pair<int, int>> stars(m);
    set<pair<int, int>> starsMap;

    for(int i = 0; i < m; ++i) {
        
        cin >> stars[i].first >> stars[i].second;

        starsMap.insert(stars[i]);

    }

    int ansX = 0;
    int ansY = 0;

    for(int i = 0; i < m; ++i) {

        int diffX = stars[i].first - sign[0].first;
        int diffY = stars[i].second - sign[0].second;

        int j;
        for(j = 1; j < n; ++j) {

            int x = sign[j].first + diffX;
            int y = sign[j].second + diffY;

            if(starsMap.find(make_pair(x, y)) == starsMap.end())
                break;

        }

        if(j == n) {
            ansX = diffX;
            ansY = diffY;
            break;
        }

    }


    cout << ansX << " " << ansY << endl;

    return 0;

}