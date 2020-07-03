#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> v(n + 1);

    vector<int> ans(n + 1, 0);

    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    bool isTrue = true;

    for(int i = n; i >= 1; --i) {

        int sum = 0;
        for(int j = i + i; j <= n; j += i)
            sum ^= ans[j];

        ans[i] = sum ^ v[i];

   }

    vector<int> x;

    for(int i = 1; i <= n; ++i)
        if(ans[i])
            x.push_back(i);

    cout << x.size() << endl;

    for(int i = 0; i < x.size(); ++i)
        cout << x[i] << " ";


    return 0;

}