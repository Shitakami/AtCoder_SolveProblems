#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    int ch = min(n, m);

    int c = max(n, m);

    for(int i = 0; i < c; ++i)
        cout << ch;

    cout << endl;
    return 0;

}