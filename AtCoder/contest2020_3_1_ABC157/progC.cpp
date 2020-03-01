#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    int n, m;

    cin >> n >> m;

    vector<int> v(n, -1);
    bool isTrue = true;

    for(int i = 0; i < m; ++i) {

        int k, num;
        cin >> k >> num;
        k--;

        if(v[k] != num && v[k] != -1)
            isTrue = false;
        

        v[k] = num;

        if(v[0] == 0 && n != 1)
            isTrue = false;

    }

    if(isTrue == false) {
        cout << "-1" << endl;
        return 0;
    }

    if(n == 1 && m == 0)
        v[0] = 0;

    for(int i = 0; i < n; ++i) {
        if(i == 0 && v[i] == -1) {
            cout << 1;
            continue;
        }

        if(v[i] == -1)
            cout << 0;
        else
            cout << v[i];
    
    }

    return 0;
}