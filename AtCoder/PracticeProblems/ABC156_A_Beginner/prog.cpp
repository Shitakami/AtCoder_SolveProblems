#include <iostream>
using namespace std;

int main() {

    int n, k;

    cin >> k >> n;

    if(k < 10) {

        cout << n + 100 * (10 - k) << endl;

    }

    else 
        cout << n << endl;

    return 0;
}