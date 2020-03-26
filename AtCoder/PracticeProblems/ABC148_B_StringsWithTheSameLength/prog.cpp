#include <iostream>
#include <string>
using namespace std;


int main() {

    string s1, s2;
    int n;

    cin >> n;


    cin >> s1 >> s2;

    for(int i = 0; i < n; ++i)
        cout << s1[i] << s2[i];

    cout << endl;

    return 0;


}