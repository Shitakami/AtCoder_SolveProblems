#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int n;

    cin >> n;

    if(n < 105) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1; // 105

    for(int i = 107; i <= n; i += 2) {

        int sum = 0;
        // cout << i << " : ";
        for(int j = 1; j * j <= i; ++j) {

            if(i % j != 0)
                continue;

         //   cout << j << " ";

            sum++;
            if(j * j != i)
                sum++;

        }

       // cout << endl;

        if(sum == 8)
            ans++;

    }



    cout << ans << endl;

    return 0;

}