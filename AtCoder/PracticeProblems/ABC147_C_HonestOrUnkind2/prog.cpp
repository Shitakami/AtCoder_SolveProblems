#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> members(n);

    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a;
        members[i].resize(a);
        for(int j = 0; j < a; ++j) {
            cin >> members[i][j].first >> members[i][j].second;
            members[i][j].first--;
        }


    }

    decltype(auto) IsCorrect = [&](int bit) {

        for(int i = 0; i < n; ++i) {

            if( !(bit & (1 << i)) )
                continue;
            for(auto member : members[i]) {

                if( (bit & (1 << member.first)) && member.second == 0) return false;
                
                if( !(bit & (1 << member.first)) && member.second == 1) return false;

       
            }
            
        }

    return true;
        
    };

    int maxBit = 1 << n;
    int maxCount = 0;
    for(int bit = 1; bit < maxBit; ++bit) {
        

        if(IsCorrect(bit)) {
            // cout << "Correct " << bitset<8>(bit) << endl;

            int count = 0;
            for(int i = 0; i < n; ++i) {
                if(bit & (1 << i))
                    count++;
            }   

            maxCount = max(maxCount, count);

        }

    }

    cout << maxCount << endl;

    return 0;

}