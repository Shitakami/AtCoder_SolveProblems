#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

    int n;

    cin >> n;

    map<string, int> m;

    m["AC"] = 0;
    m["WA"] = 0;
    m["TLE"] = 0;
    m["RE"] = 0;

    for(int i = 0; i < n; ++i) {

        string s;
        cin >> s;


        m[s]++;

    }

    cout << "AC x " << m["AC"] << endl;
    cout << "WA x " << m["WA"] << endl;
    cout << "TLE x " << m["TLE"] << endl;
    cout << "RE x " << m["RE"] << endl;

    return 0;

}