#include <iostream>
using namespace std;

int main() {

    int n;

    cin >> n;

    if(n == 2) {
        cout << 2 << endl;
        return 0;
    }

    if(n % 2 == 0)
        n++;
    

    while(1) {

        bool isPrime = true;

        for(int i = 3; i * i <= n; i+=2) {
            if(n % i == 0) {
                isPrime = false;
                break;
            }

        }

        if(isPrime)
            break;

        n += 2;

    }

    cout << n << endl;

}

