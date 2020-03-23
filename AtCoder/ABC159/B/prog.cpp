#include <iostream>
#include <string>

using namespace std;


int main() {

    string s;

    cin >> s;

    int index = 0;
    while(index < s.size() / 2) {

        if(s[index] != s[s.size() - index - 1])
            break;
        index++;

    }

    if(index != s.size() / 2) {
        cout << "No" << endl;
        return 0;
    }

    int endI = s.size() / 2 - 1;
    index = 0;
    while(index < endI) {

        if(s[index] != s[endI])
            break;

        index++;
        endI--;

    }

    if(index < endI) {
        cout << "No" << endl;
        return 0;
    }

    endI = s.size() - 1;
    index = s.size() + 1;

    while(index < endI) {

        if(s[index] != s[endI])
            break;

        index++;
        endI--;
        
    }

    if(index < endI) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;

}