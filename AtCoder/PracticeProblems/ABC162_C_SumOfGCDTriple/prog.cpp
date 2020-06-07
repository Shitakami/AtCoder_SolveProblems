#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {

    if(a < b)
        swap(a, b);

    int c = a % b;

    while(c != 0) {

        a = b;
        b = c;
        c = a % b;

    }

    return b;

}

int main() {

    int n;
    using ll = long long;

    cin >> n;

    ll sum = 0;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k) 
                sum += gcd(i, gcd(j, k));


    cout << sum << endl;

    return 0;

}