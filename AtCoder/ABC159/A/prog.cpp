#include <iostream>
using namespace std;

int comb(int x) {

    int ret = 1;

    ret *= x * (x - 1);

    ret /= 2;

    return ret;

}

int main() {

    int x, y;

    cin >> x >> y;

    int ans = 0;

    if(x > 1)
        ans += comb(x);

    if(y > 1)
        ans += comb(y);

    cout << ans << endl;    

    return 0;
}