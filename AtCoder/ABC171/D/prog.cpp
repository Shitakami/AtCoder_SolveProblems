#include <iostream>
#include <vector>
#include <map>
using namespace std;

using ull = unsigned long long;

int main() {

    int n;
    int q;

    cin >> n;

    vector<ull> v(n);
    ull sum = 0;

    map<ull, ull> x;


    for(int i = 0; i < n; ++i) {
        ull num;
        cin >> num;

        if(x.find(num) == x.end())
            x[num] = 1;
        else
            x[num]++;
        
        sum += num;

    }


    cin >> q;

    for(int i = 0; i < q; ++i) {
        ull a, b;

        cin >> a >> b;
        
        if(x.find(a) != x.end()) {

            sum -= x[a] * a;
            sum += x[a] * b;

            if(x.find(b) == x.end())
                x[b] = x[a];
            else
                x[b] += x[a];

            x.erase(a);

        }

        cout << sum << endl;

    }



    return 0;

}