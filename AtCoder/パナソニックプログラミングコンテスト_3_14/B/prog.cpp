#include <iostream>
#include <vector>
using namespace std;

int main() {

    long long H, W;

    cin >> H >> W;

    long long ans;

    if(W == 1 || H == 1) {
        cout << 1 << endl;
        return 0;
    }

    if(H % 2 == 0) {
        ans = H * W;
        ans /= 2;
    }
    else {
        ans = W * (H / 2);
        ans += W / 2 + W % 2;

    }

    cout << ans << endl;

    return 0;

}