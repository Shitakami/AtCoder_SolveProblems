#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

int main() {

    int n;

    cin >> n;

    vector<ull> v(n);

    ull sum = 0;

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        sum ^= v[i];
    }

    for(int i = 0; i < n; ++i) {

        if(i)
            cout << " ";
        cout << (v[i] ^ sum);

    }
    cout << endl;

    return 0;
}