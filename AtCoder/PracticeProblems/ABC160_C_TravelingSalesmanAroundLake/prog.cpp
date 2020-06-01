#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int k, n;

    cin >> k >> n;

    vector<int> house(n);

    int maxDistance = -1;
    int index = -1;

    for(int i = 0; i < n; ++i) {
        cin >> house[i];

        if(i == 0)
            continue;

        if(house[i] - house[i - 1] > maxDistance) {
            index = i;
            maxDistance = house[i] - house[i - 1];
        }

    }

    if(house[0] + (k - house[n - 1]) > maxDistance) {
        index = 0;
        maxDistance = house[0] + (k - house[n - 1]);
    }

    cout << k - maxDistance << endl;

    return 0;


}