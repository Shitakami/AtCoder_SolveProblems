#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int h, w;

    cin >> h >> w;

    vector<string> tile(h);

    for(int i = 0; i < h; ++i)
        cin >> tile[i];


    vector<vector<int>> up(h, vector<int>(w, 0));
    vector<vector<int>> down(h, vector<int>(w, 0));
    vector<vector<int>> left(h, vector<int>(w, 0));
    vector<vector<int>> right(h, vector<int>(w, 0));

    int count = 0;

    for(int i = 0; i < h; ++i) {
        count = 0;
        for(int j = 0; j < w; ++j) {
            if(tile[i][j] == '#')
                count = 0;
            else
                count++;
            
            left[i][j] = count;
        }
    }

    for(int i = 0; i < h; ++i) {
        count = 0;
        for(int j = w - 1; j >= 0; --j) {
            if(tile[i][j] == '#')
                count = 0;
            else 
                count++;

            right[i][j] = count;
        }
    }



    for(int j = 0; j < w; ++j) {
        count = 0;
        for(int i = 0; i < h; ++i) {
            if(tile[i][j] == '#')
                count = 0;
            else 
                count++;
            up[i][j] = count;
        }


    }

    for(int j = 0; j < w; ++j) {
        count = 0;
        for(int i = h - 1; i >= 0; --i) {
            if(tile[i][j] == '#')
                count = 0;
            else 
                count++;
            down[i][j] = count;
        }

    }


    int answer = 0;

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(tile[i][j] == '#')
                continue;
            int sum = left[i][j] + right[i][j] + up[i][j] + down[i][j] - 3;
            answer = max(answer, sum);
        }

    }


    cout << answer << endl;

    return 0;

}