#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int main() {

    int h, w, k;

    cin >> h >> w >> k;

    vector<vector<bool>> tile(h, vector<bool>(w));

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            char ch;
            cin >> ch;

            tile[i][j] = ch == '#' ? true : false;

        }
    }


    int hEnd = 1 << h;
    int wEnd = 1 << w;

    int answer = 0;


    for(int hbit = 0; hbit < hEnd; ++hbit) {


        for(int wbit = 0; wbit < wEnd; ++wbit) {
            vector<vector<bool>> t = tile;

            for(int i = 0; i < h; ++i) {
                if(hbit & (1 << i)) {
                    for(int wi = 0; wi < w; ++wi)
                        t[i][wi] = false;

                }
            }

            for(int j = 0; j < w; ++j) {
                if(wbit & (1 << j)) {
                    for(int hi = 0; hi < h; ++hi)
                        t[hi][j] = false;
                }
            }

            int count = 0;
            for(int i = 0; i < h; ++i)
                for(int j = 0; j < w; ++j)
                    if(t[i][j])
                        count++;

            if(count == k)
                answer++;
        }
    }

    cout << answer << endl;

    return 0;

}