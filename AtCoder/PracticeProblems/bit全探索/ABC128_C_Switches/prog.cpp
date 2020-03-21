#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {

    int n, m;

    cin >> n >> m;
    
    vector<vector<int>> switches(m, vector<int>());

    for(int i = 0; i < m; ++i) {
        int k;
        cin >> k;

        for(int j = 0; j < k; ++j) {
            int num;
            cin >> num;
            switches[i].push_back(num - 1);
        }
    }

    vector<int> lights(m);
    for(int i = 0; i < m; ++i) {

        cin >> lights[i];
    }

    int ans = 0;

    int maxN = 1 << n;

    for(int bit = 0; bit < maxN; ++bit) {

        int i;
        for(i = 0; i < m; ++i) {
            int count = 0;
            for(int j = 0; j < switches[i].size(); ++j) {

                int b = 1 << switches[i][j];
                if(bit & b)
                    count++;
            }

            if(count % 2 != lights[i])
                break;
        }

        if(i == m)
            ans++;

    }


    cout << ans << endl;
    return 0;

}