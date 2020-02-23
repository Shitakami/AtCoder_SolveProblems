#include <iostream>
using namespace std;

const int mod = 1e+9 + 7;
const int MAX = 2 * 1e+5;

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

    long long n, a, b;

    cin >> n >> a >> b;

    long long ans = 1;

    for(int i = 0; i < n; ++i)
        ans = (ans * 2) % mod;

    ans--;
    cout << "endCalc" << endl;
    COMinit();
    long long a_c = COM(n, a);
    long long b_c = COM(n, b);
    ans -= a_c;
    ans -= b_c;

    cout << ans << endl;

}