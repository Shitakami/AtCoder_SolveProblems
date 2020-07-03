#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;

void PrintV(const vector<ll> v) {

    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << "\t";
    cout << endl;

}

int main() {

    int n;

    cin >> n;

    vector<ll> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    vector<ll> sumV(n, 0);

    sumV[0] = v[0];

    for(int i = 1; i < n; ++i) 
        sumV[i] += sumV[i - 1] + v[i];

 //   PrintV(v);
 //   PrintV(sumV);

    int count = 1;

    for(int i = n - 2; i >= 0; --i) {

        if(v[i + 1] > 2 * sumV[i])
            break;
        
        count++;

    }

    cout << count << endl;

    return 0;

}