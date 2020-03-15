#include <iostream>
using namespace std;

int main() {

    int h, a;

    cin >> h >> a;

    int d, m;
    d = h / a;
    m = h % a;

    if(m)
        d++;

    cout << d << endl;


}