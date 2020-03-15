#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;

    cin >> n >> k;

    vector<long long int> hp;

    for(int i = 0; i < n; ++i) {
        long long int a;
        cin >> a;

        hp.push_back(a);
    }

    sort(hp.begin(), hp.end(), greater<int>());

    long long int sum = 0;

    for(int i = k; i < n; ++i) {

        sum += hp[i];
    }

    cout << sum << endl;

    return 0;


}