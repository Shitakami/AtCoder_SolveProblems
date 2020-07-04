#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

const vector<int> calcV(string s) {

    int n = s.size();
    map<char, int> usedMap;
    vector<int> retV(n);
    int count = 0;

    for(int i = 0; i < n; ++i) {

        if(usedMap.find(s[i]) == usedMap.end()) {
            usedMap[s[i]] = count++;
        }
        retV[i] = usedMap[s[i]];

    }

    return retV;

}

int main() {

    string s, t;

    cin >> s;
    cin >> t;


    if(calcV(s) == calcV(t))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;

}