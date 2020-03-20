#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    set<int> canSum;

    int maxBit = 1 << n;
    for(int i = 1; i < maxBit; ++i) {

        int bit = 1;
        int index = 0;
        int sum = 0;
        while(bit < maxBit) {
            
            if(i&bit)
                sum += v[index];
            index++;
            bit = bit << 1;
        }
        
        canSum.insert(sum);
    }


    int q;
    cin >> q;

    int maxN = 1 << n;
    for(int i = 0; i < q; ++i) {

        int num;
        cin >> num;

        if(canSum.find(num) != canSum.end())
            cout << "yes";
        else
            cout << "no";
        cout << endl;

    }

    return 0;

}