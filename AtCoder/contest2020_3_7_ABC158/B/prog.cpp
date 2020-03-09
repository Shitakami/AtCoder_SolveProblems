#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {

    ll n, b, r;

    cin >> n >> b >> r;


    ll br = b + r;

    ll answer = (n / br) * b;
    answer += min(n % br, b);

    cout << answer << endl;

    return 0;



}