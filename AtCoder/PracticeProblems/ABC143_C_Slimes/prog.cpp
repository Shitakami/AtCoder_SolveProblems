#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {


    int n;
    string s;

    cin >> n;
    cin >> s;

    int count = 1;
    
    for(int i = 1; i < n; ++i) {

        if(s[i] == s[i - 1])
            continue;

        count++;
    }


    cout << count << endl;

    return 0;

}