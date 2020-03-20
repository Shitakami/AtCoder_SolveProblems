#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {

    string s;
    
    cin >> s;

    auto isTrue = [&](int index) {
        switch(s[index]) {
            case 'A':
            case 'C':
            case 'G':
            case 'T':
                return true;
            defalut :
                return false;
        }
        return false;
    };


    int ans = 0;
    for(int i = 0; i < s.size(); ++i) {
        int count = 0;
        for(int j = i; j < s.size(); ++j) {
            
            if(isTrue(j)) {
                count++;
            }
            else {
                break;
            }

        }
        ans = max(count, ans);

    }

    cout << ans << endl;

    return 0;

}