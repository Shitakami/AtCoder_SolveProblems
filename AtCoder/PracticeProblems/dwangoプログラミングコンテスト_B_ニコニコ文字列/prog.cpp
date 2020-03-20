#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;

    cin >> s;

    int i = 0;
    char s_25[] = {'2', '5'};

    long long ans = 0;
    while(i < s.size()) {

        if(s[i] != '2') {
            i++;
            continue;
        }
        
        int sum = 0;
        int isOdd = 1;

        while(1) {
            i++;

            if(i == s.size() || s[i] != s_25[isOdd])
                break;

            if(isOdd == 1)
                sum++;

            isOdd = (isOdd + 1) % 2;

        }

        for(int x = 1; x <= sum; ++x)
            ans += x;

    }

    cout << ans << endl;

    return 0;

}