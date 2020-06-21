#include <iostream>
#include <vector>
using namespace std;

int main() {

    const int maxValue = 100000 + 10;
    vector<bool> isPrime(maxValue, true);
    vector<int> primeSum(maxValue, 0);

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i * i <= maxValue; ++i) {

        if(!isPrime[i])
            continue;

        for(int j = 2; j * i <= maxValue; ++j)
            isPrime[i * j] = false;
    }

    for(int i = 2; i < maxValue; ++i) {
        if(isPrime[i] && isPrime[(i + 1) / 2])
            primeSum[i]++;

        primeSum[i] += primeSum[i - 1];
    }

    int n;

    cin >> n;

    for(int i = 0; i < n; ++i) {

        int a, b;

        cin >> a >> b;

        cout << primeSum[b] - primeSum[a - 1] << endl;

    }

    return 0;

}