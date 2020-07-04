#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main() {

    int n;
    cin >> n;

    string s;

    cin >> s;

    int leftCount = 0;
    int rightCount = 0;

    int count = 0;

    for(int i = 0; i < n; ++i) {

        if(count == 0 && s[i] == ')')
            leftCount++;
        else if(s[i] == '(') {
            count++;
        }
        else if(s[i] == ')') {
            count--;
        }

    }

    rightCount = count;

    for(int i = 0; i < leftCount; ++i)
        cout << "(";
    cout << s;
    for(int i = 0; i < rightCount; ++i)
        cout << ")";
    
    cout << endl;

    return 0;
}