#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int Calc(int x, int p) {

    return (x - p) * (x - p);

}

int main() {

    int n;
    cin >> n;
    
    vector<int> members(n);
    int minD = 200, maxD = 0;

    for(int i = 0; i < n; ++i) {
        cin >> members[i];
        minD = min(members[i], minD);
        maxD = max(members[i], maxD);
    }


    int answer = INT_MAX;
    for(int i = minD; i <= maxD; ++i) {
        int sum = 0;

        for(const auto &m : members)
            sum += Calc(m, i);
        answer = min(sum, answer);
    }

    cout << answer << endl;

    return 0;

}