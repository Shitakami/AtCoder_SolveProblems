#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> a;
    int sameCount = 0;


    for(int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }

    sort(a.begin(), a.end());

    for(int i = 1; i < 3; ++i) {
        if(a[i] == a[i - 1])
            sameCount++;

    }

    if(sameCount == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}