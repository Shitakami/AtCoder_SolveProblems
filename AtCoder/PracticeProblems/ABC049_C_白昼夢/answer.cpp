#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    string s;
    cin >> s;

    reverse(s.begin(), s.end());    

    string dream = "maerd", dreamer = "remaerd", erase = "esare", eraser = "resare";

    int index = 0;

    while(index != s.size()) {
        string sub = s.substr(index, 5);

        if(sub == dream || sub == erase) {
            index += 5;
            continue;
        }

        sub = s.substr(index, 6);
        
        if(sub == eraser) {
            index += 6;
            continue;
        }

        sub = s.substr(index, 7);

        if(sub == dreamer) {
            index += 7;
            continue;
        }

        cout << "NO" << endl;
        return 0;

    }

    cout << "YES" << endl;

    return 0;


}