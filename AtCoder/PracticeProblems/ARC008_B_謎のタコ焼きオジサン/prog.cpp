#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {

    int n, m;

    vector<int> name(26, 0);
    vector<int> kit(26, 0);

    cin >> n >> m;

    string s;
    cin >> s;

    for(int i = 0; i < n; ++i)
        name[s[i] - 'A']++;

    cin >> s;

    for(int i = 0; i < m; ++i)
        kit[s[i] - 'A']++;

    
    int count = 1;

    for(int i = 0; i < 26; ++i) {

        if(kit[i] == 0 && name[i] > 0) {
            cout << -1 << endl;
            return 0;
        }

        while(kit[i] * count < name[i])
            count++;

    }

    cout << count << endl;

    return 0;


}