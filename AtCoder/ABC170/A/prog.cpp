#include <iostream>

using namespace std;


int main() {

    int index = 0;

    for(int i = 0; i < 5; ++i) {
        int num;
        cin >> num;

        if(num == 0)
            index = i + 1;


    }

    cout << index << endl;

    return 0;
}