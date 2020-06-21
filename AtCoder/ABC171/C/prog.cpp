#include <iostream>
#include <string>
using namespace std;

using ull = unsigned long long;

int main() {

    ull n;

    cin >> n;

    ull ketaCount = 0;
    ull x, y;
    string ans = "";


    while(1) {

        y = n%26;
        x = n/26;

        if(y != 0)
            ans = (char)('a' + y - 1) + ans;
        else
            ans = 'z' + ans;

        if(y == 0)
            x--;

        n = x;

        if(n <= 0)
            break;
        
    }


    cout << ans << endl;

    return 0;


}