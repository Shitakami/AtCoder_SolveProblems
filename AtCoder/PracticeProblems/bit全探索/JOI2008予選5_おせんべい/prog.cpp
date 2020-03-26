#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int r, c;

    cin >> r >> c;

    vector<vector<int>> crackerMap(r, vector<int>(c, false));

    for(int i = 0; i < r; ++i) {

        for(int j = 0; j < c; ++j)
            cin >> crackerMap[i][j];

    }

    int maxBit = 1 << r;
    int maxCount = 0;

    for(int bit = 0; bit < maxBit; ++bit) {

        int count = 0;
        for(int i = 0; i < c; ++i) {

            int trueCount = 0;            
            for(int j = 0; j < r; ++j) {
                if(1 << j & bit)
                    trueCount += !crackerMap[j][i];
                else
                    trueCount += crackerMap[j][i];
            }
            count += max(trueCount, r - trueCount);

        }

        maxCount = max(maxCount, count);
    }

    cout << maxCount << endl;

    return 0;
}