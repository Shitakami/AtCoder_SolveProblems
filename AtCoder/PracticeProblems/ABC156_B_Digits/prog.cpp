#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;


int main() {

    int n, k;
    cin >> n >> k;

    int d = 1;
    int count = 0;

    while(d <= n) {

        d *= k;
        count++;

    }

    cout << count << endl;

    return 0;

}