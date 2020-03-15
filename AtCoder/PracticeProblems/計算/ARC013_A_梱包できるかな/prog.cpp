#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {

    int n, m, l;

    cin >> n >> m >> l;

    vector<int> v(3);
    vector<int> permutation = {0, 1, 2};
    cin >> v[0] >> v[1] >> v[2];

    int maxCount = 0;
    int count = 1;
    while(1) {
        
        int bn = v[permutation[0]], bm = v[permutation[1]], bl = v[permutation[2]];

        int yokoCount = n / bn;
        int tateCount = m / bm;
        int takasaCount = l / bl;

        maxCount = max(maxCount, yokoCount * tateCount * takasaCount);

        if(!next_permutation(permutation.begin(), permutation.end()))
            break;

    }

    cout << maxCount << endl;
    return 0;

}