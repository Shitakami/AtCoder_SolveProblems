#include <iostream>
using namespace std;

int main() {

    int n;
    using ll = long long;

    cin >> n;

    ll sum = 0;

    for(int i = 1; i <= n; ++i) {

        if(i % 3 == 0 || i % 5 == 0)
            continue;
        
        sum += i;

    }

    cout << sum << endl;

    return 0;


}