#include <iostream>
using namespace std;

int main() {

    int day, n;

    cin >> day >> n;

    for(int i = 0; i < n; ++i) {
        int task;
        cin >> task;
        day -= task;
    }

    if(day < 0)
        day = -1;

    cout << day << endl;

    return 0;


}