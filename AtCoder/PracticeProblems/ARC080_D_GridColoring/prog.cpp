#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int h, w, n;

    cin >> h >> w;
    cin >> n;

    vector<int> colors(n);

    for(int i = 0; i < n; ++i)
        cin >> colors[i];

    queue<int> colorQ;

    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < colors[i]; ++j)
            colorQ.push(i + 1);
    

    int directionW = 1;
    int w_i = 0;
    int h_i = 0;
    vector<vector<int>> tileMap(h, vector<int>(w));

    while(!colorQ.empty()) {
        
        tileMap[h_i][w_i] = colorQ.front(); colorQ.pop();

        w_i += directionW;

        if(w_i == w) {
            h_i++;
            w_i = w - 1;
            directionW = -1;
        }
        else if(w_i == -1) {
            h_i++;
            w_i = 0;
            directionW = 1;
        }

    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(j)
                cout << " ";
            cout << tileMap[i][j];
        }
        cout << endl;
    }

    return 0;

}