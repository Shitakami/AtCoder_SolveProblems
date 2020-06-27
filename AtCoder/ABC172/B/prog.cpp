#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1, s2;

    cin >> s1 >> s2;


    int sum = 0;
    for(int i = 0; i < s1.size(); ++i)
        if(s1[i] != s2[i])
            sum++;

    cout << sum << endl;

    return 0;

}