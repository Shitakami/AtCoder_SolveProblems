#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    while(n != 0) {

        int x = n % 10;
        if(x == 7)
            break;

        n /= 10;

    }

    if(n != 0) 
        cout << "Yes";
    else
        cout << "No";

    cout << endl;

}