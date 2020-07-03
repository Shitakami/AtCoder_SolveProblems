#include <iostream>
using namespace std;

using ull = unsigned long long;

int main() {

    ull n;

    cin >> n;

    if(n == 1) {
        cout << 1 << " " << 1 << endl;

    }
    else {
        cout << n + 1 << " " << 2 << endl;

    }

    return 0;

}