#include <iostream>
using namespace std;

long long int GCD(long long int a, long long int b) {

    if(b > a)
        swap(a, b);

    int c = a % b;
    while(c != 0) {
        a = b;
        b = c;
        c = a % b;
    }

    return b;

}

int main() {

    long long int a, b;

    cin >> a >> b;


  //  cout << GCD(a, b) << endl;

    cout << a * b / GCD(a, b) << endl;

    return 0;

}