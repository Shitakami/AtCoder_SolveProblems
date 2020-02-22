#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;

 
const int mod = 1000000007;

 
const int MAX = 1000000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}


int main() {

    long long x, y;
    cin >> x >> y;

    if((x + y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long count = (x + y) / 3;

    x -= count;
    y -= count;


    if(x < 0 || y < 0) {
        cout << 0 << endl;
        return 0;
    }


    /*
    Init();

    cout << nCr(sum, minCount) << endl;
    */

    COMinit();
    cout << COM(x + y, x) << endl;

    return 0;


}