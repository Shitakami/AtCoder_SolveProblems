#include <iostream>
using namespace std;


int main() {

    long long int a, b;
    long long int money;
    cin >> a >> b >> money;

    auto CalcDigit = [&](long long int num) {

        int x = 1;
        int y = 10;
        while(y <= num) {
            x++;
            y *= 10;

        }

        return x;
    };


    long long int left = 0;
    long long int right = 1000000001;

    while(right - left > 1) {

        long long int mid = (left + right) / 2;
        long long int n = a * mid + b * CalcDigit(mid); 
        if(n > money) {
            right = mid;
        }
        else 
            left = mid;

    }


    cout << left << endl;

    return 0;


}