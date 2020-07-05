#include <iostream>
using namespace std;

int main() {

    int n;

    cin >> n;

    int x = 0;
    while(x <= n)
        x += 1000;

    x -= n;

    cout << x % 1000 << endl;


    return 0;
}