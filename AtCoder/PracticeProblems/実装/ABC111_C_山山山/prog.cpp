#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    vector<map<int, int>> vCount(2);

    int vMax[2] = {0, 0};
    int vMaxNum[2] = {-1, -1};

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        
        int x = i % 2;
        if(vCount[x].find(v[i]) == vCount[x].end()) {

            vCount[x].emplace(v[i], 1);

            if(vMax[x] < vCount[x][v[i]]) {
                vMax[x] = vCount[x][v[i]];
                vMaxNum[x] = v[i];
            }

        } else {

            vCount[x][v[i]]++;
            
            if(vMax[x] < vCount[x][v[i]]) {
                vMax[x] = vCount[x][v[i]];
                vMaxNum[x] = v[i];
            }
        }
    }

    int count = 0;

    if(vMaxNum[0] != vMaxNum[1]) {
        count += n / 2 - vMax[0];
        count += n / 2 - vMax[1];
    }
    else {
       
        int count1 = 0;
        
        count1 += n / 2 - vMax[0];

        int nextMax = 0;
        for(const auto &vc : vCount[1]) {
            if(vc.first == vMaxNum[1])
                continue;
            nextMax = max(nextMax, vc.second);
        }

        count1 += n / 2 - nextMax;


        int count2 = 0;
        count2 += n / 2 - vMax[1];
        nextMax = 0;
        for(const auto &vc : vCount[0]) {
            if(vc.first == vMaxNum[0])
                continue;
            nextMax = max(nextMax, vc.second);
        }

        count2 += n / 2 - nextMax;
        
        count = min(count1, count2);
     //   cout << count1 << " " << count2 << endl;
    }

    cout << count << endl;

    return 0;

}