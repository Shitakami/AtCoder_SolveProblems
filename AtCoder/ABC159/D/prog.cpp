#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

using ll = long long;

int main() {

    int n;

    cin >> n;

    vector<int> v(n);
    map<int, int> vCount;
    vector<ll> num(n + 1);

    num.push_back(0);

    for(int i = 0; i < n; ++i)
        num[i + 1] = num[i] + i;



    for(int i = 0; i < n; ++i) {
        cin >> v[i];

        if(vCount.find(v[i]) == vCount.end())
            vCount[v[i]] = 1;
        else
            vCount[v[i]]++;

    }

        ll sum = 0;
        for(const auto &a : vCount) {
            sum += num[a.second];

        }

        for(int i = 0; i < n; ++i) {

            int count = vCount[v[i]];
            ll s = sum;
            s -= num[count];
        s += num[count - 1];

        cout << s << endl;
        
    }



    return 0;


}