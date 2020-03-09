#include <iostream>
/*
 未だ解けていない
 */

#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int R = -1;
const int L = 1;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> row(n);

    for(int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        if(ch == 'L')
            row[i] = L;
        else
            row[i] = R;

    }


