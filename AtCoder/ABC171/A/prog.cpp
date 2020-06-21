#include <iostream>
using namespace std;

int main() {

    char ch;

    cin >> ch;

    if('a' <= ch && ch <= 'z')
        cout << "a" << endl;
    else
        cout << "A" << endl;

    return 0;
}