#include <iostream>
#include <vector>
using namespace std;

using ull = unsigned long long;

const ull mod = 1000000007;

int main() {

    int n;

    cin >> n;

    const int maxV = 1000 + 10;
    vector<ull> count(maxV, 0);

    for(int i = 2; i <= n; ++i) {

        ull num = i;

        for(int j = 2; j * j <= num; ++j) {

            while(num % j == 0) {
                num /= j;
                count[j]++;
            }

        }

        if(num != 1)
            count[num]++;

    }

    ull ans = 1;

    for(int i = 2; i <= n; ++i) {
        if(count[i] == 0)
            continue;

        ans = ans * (count[i] + 1);
        ans %= mod;

    }

    cout << ans << endl;

    return 0;
}