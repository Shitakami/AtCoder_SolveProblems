#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    int n;

    cin >> n;

    vector<int> v(n);
    vector<int> ans;

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    int count = 0;

    for(int i = 0; i < n; ++i) {

        
        int j;
        for(j = 0; j < ans.size(); ++j) {

            if(v[i] % ans[j] == 0 || v[i] / ans[j] < 1)
                break;

        }

        if(j == ans.size()) {
            ans.push_back(v[i]);
            count++;
            if(i + 1 < n && v[i] == v[i + 1])
                count--;
        }

    }

    cout << count << endl;

    return 0;

}