#include <iostream>
#include <string>
using namespace std;

int main() {

    string s, t;

    cin >> s >> t;

    string answer;
    bool isTrue = false;

    for(int i = s.size() - t.size() + 1; i >= 0 ; --i) {

        if(s[i] != '?' && s[i] != t[0])
            continue;

        int j = 1;
        while(j < t.size()) {
            if(s[i + j] != '?' && s[i + j] != t[j])
                break;

            j++;
        }

        if(j == t.size()) {
            for(int j = 0; j < t.size(); ++j)
                s[i + j] = t[j];

            
            isTrue = true;
            break;
        }

    }

    if(isTrue == false) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '?')
            cout << 'a';
        else
            cout << s[i];
    }

    cout << endl;

    return 0;

}