/*
 * 不正解
 * TLE
 */
#include <iostream>
using namespace std;

int x;
bool isTrue;

const int v[] = {100, 101, 102, 103, 104, 105};

void calc(int sum) {

    if(sum > x)
        return;

    if(sum == x) {
        isTrue = true;
        return;
    }

    for(int i = 0; i < 6 && isTrue == false; i++) {
        sum += v[i];
        calc(sum);
        sum -= v[i];
    }

}

int main() {

    cin >> x;

    isTrue = false;

    calc(0);

    cout << (int)isTrue << endl;
    return 0;

}