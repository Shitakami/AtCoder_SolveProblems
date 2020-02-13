/*
 * 未だ解けていない
 */

#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b) {

    if(a < b) {
        swap(a, b);
    }

    int c = a % b;
    int d = b;
    while(c != 0) {
        a = b;
        b = c;
        c = a % b;
    }

    return b;

}

int main() {

    int n, m;
    vector<int> numbers;

    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        int num;

        cin >> num;
        numbers.push_back(num);


    }

    cout << GCD(numbers[0], numbers[1]) << endl;

}