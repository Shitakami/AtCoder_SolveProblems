#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int mod = 1e+9 + 7;

int main() {

    int n;
    cin >> n;

    vector<long long int> num(n);

    for(int i = 0; i < n; ++i) {
        cin >> num[i];
     //   cout << bitset<64>(num[i]) << endl;
    }

    long long int sum = 0;

    for(int bit = 0; bit < 60; ++bit) {
        long long int n0 = 0, n1 = 0;

        for(int i = 0; i < n; ++i) {
            if(num[i] & (1ll << bit))
                n1++;
            else
                n0++; 
        }

   //     cout << bit << " : " << "n1 = " << n1 << ", n0 = " << n0 << endl;

        long long int mul = (n1 * n0) % mod;
        long long int d = (1ll << bit) % mod;
        long long int addVal = (mul * d) % mod;
        sum = (sum + addVal) % mod;

    }
    
    cout << sum << endl;

    return 0;

}