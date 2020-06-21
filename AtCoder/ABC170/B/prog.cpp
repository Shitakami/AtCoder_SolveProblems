#include <iostream>
using namespace std;

int main() {

    int n, count;

    cin >> n >> count;

    int i;
    bool isTrue = false;
    for(i = 0; i <= n; ++i) {

        int k = i * 4;
        int t = (n - i) * 2;

        if(k + t == count)
            isTrue = true;

        if(isTrue)
            break;

    }

    if(isTrue) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;

}