#include <iostream>
#include <vector>
using namespace std;

const int m[] = {100, 101, 102, 103, 104, 105 };

int main() {

    int x;
    vector<bool> v(100000 + 300, false);

    cin >> x;

    for(int i = 0; i < 6; ++i) {
        v[m[i]] = true;
    }

    for(int i = 100; i <= 100000; ++i) {

        if(v[i] == true) {
            for(int j = 0; j < 6; ++j) {
                v[i + m[j]] = true;
            }


        }

    }

    cout << (int)v[x] << endl;
    return 0;

}