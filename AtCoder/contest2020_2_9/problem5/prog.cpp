#include <iostream>
using namespace std;

int CalcConbination(int a, int b) {

    int x = 1;
    int y = 1;

    for(int i = 0; i < b; i++) {
        x *= (a - i);
        y *= (i + 1);

    }

    return x / y;
}


int main() {

    long long int n;
    int k;
    int numDigit;

    cin >> n >> k;

    numDigit = n / 10;
    
    long long int sum = 0;

    int p = pow(9, k);

    for(int i = 1; i < numDigit; ++i) {

        if(i == 1) {
            if(k == 1) {
                sum += 9;
             
            }
            continue;
        }

        if(i == 2) {
            if(k == 2)
                sum += 9 * 9;
            else if(k == 1)
                sum += 9;
            
            continue;

        }


        sum += CalcConbination(i, k) * p;


    }

}