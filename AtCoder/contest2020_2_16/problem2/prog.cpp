#include <iostream>
using namespace std;

int main() {

    int n;

    bool isTrue = true;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if(num % 2 != 0)
            continue;

        if(num % 3 != 0 && num % 5 != 0)
            isTrue = false;

    }

    if(isTrue)
        cout << "APPROVED" << endl;
    else
        cout << "DENIED" << endl;
    
    return 0;

}