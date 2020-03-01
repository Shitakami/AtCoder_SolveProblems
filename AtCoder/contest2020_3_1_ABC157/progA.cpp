#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {

    int n;
    cin >> n;

    int ans = (n / 2) + (n % 2);
    cout << ans << endl;


    return 0;
}