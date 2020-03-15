#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = 0;
    int count = 0;

    for(int i = 0; i < n - 1; ++i) {
        if(a[i] >= a[i + 1])
            count++;
        else
            count = 0;
        
        
        ans = max(count, ans);
    }


    cout << ans << endl;

    return 0;

}