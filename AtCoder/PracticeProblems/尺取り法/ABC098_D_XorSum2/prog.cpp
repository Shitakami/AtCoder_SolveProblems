#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

int main() {

    int n;
    cin >> n;

    vector<ull> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    
    ull answer = 0;
    int right = 0;

    ull sum = 0;
    ull xorSum = 0;

    for(int left = 0; left < n; ++left) {

        while(right < n && (sum + v[right]) == (xorSum ^ v[right])) {
            sum += v[right];
            xorSum ^= v[right];
            ++right;
        }

        answer += right - left;

        if(right == left) {
            right++;
        }
        else {
            sum -= v[left];
            xorSum ^= v[left];
        }

    }
    
    cout << answer << endl;

    return 0;

}