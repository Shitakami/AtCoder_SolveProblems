#include <iostream>
#include <string>
using namespace std;

int main() {
 
    string s1, s2;
    cin >> s1 >> s2;
  
    int i;

    for(i = 0; i < s1.size(); ++i)
        if(s1[i] != s2[i])
            break;

    if(i == s1.size())
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;
  
}