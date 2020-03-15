#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    int a = 1;
    int comb[10][10];

    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
        comb[i][j] = 0;


    cin >> n;


    for(int i = 1; i <= n; ++i) {

        int under = i % 10;

        if(a * 10 <= i)
            a *= 10;

        int top = i / a;
        comb[top][under]++;


    }

    long long int sum = 0;
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            sum += comb[i][j] * comb[j][i];

        }
    }


    cout << sum << endl;

    return 0;


}