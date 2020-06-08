#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {

    int n;

    cin >> n;

    ll answer = 0;
    set<int> containTast;
    vector<int> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    int right = 0;

    for(int left = 0; left < n; ++left) {

        while(right < n && containTast.find(v[right]) == containTast.end()) {
            containTast.insert(v[right]);
            right++;
        }

        answer = max(answer, (ll)containTast.size());


        containTast.erase(v[left]);      

    }

    cout << answer << endl;

    return 0;


}