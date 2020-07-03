#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, h;

    cin >> n >> h;

    vector<int> attack(n);
    vector<int> throwing(n);

    int maxAttack = 0;

    for(int i = 0; i < n; ++i) {
        cin >> attack[i] >> throwing[i];
        maxAttack = max(maxAttack, attack[i]);

    }

    sort(throwing.begin(), throwing.end(), greater<int>());

    int count = 0;
    int index = 0;
    while(index < n && throwing[index] > maxAttack && h > 0) {
        h -= throwing[index];
        index++;
        count++;
    }

    while(h > 0) {
        h -= maxAttack;
        count++;
    }

    cout << count << endl;

    return 0;
}