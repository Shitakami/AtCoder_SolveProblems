#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

int main() {

    int n;
    ull k;

    cin >> n >> k;

    vector<int> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i]--;
    }

    vector<int> root;
    vector<int> done(n, -1);

    int index = 0;
    ull count = 0;
    while(done[index] == -1) {
        done[index] = count++;
        root.push_back(index);
        index = v[index];

    }

    ull loopCount = count - done[index];
    /*
    cout << "count = " << count << endl;
    cout << "loopCount = " << loopCount << endl;
    cout << k - index << endl;
    cout << index + (k - index) % loopCount;
    */
    if(k < count)
        cout << root[k] + 1 << endl;
    else {
        ull a = count - loopCount;
        cout << root[a + (k - a)%loopCount] + 1 << endl;
    }
    return 0;


}