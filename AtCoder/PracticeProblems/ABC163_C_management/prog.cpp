#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> members(n, 0);

    for(int i = 1; i < n; ++i) {
        int top;
        cin >> top;
        members[top - 1]++;
    }

    for(int i = 0; i < n; ++i)
        cout << members[i] << endl;

    return 0;

}