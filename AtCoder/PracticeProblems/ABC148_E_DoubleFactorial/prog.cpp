#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

int main() {

    ull n;
    cin >> n;
    
    if(n % 2) {
        cout << "0" << endl;
        return 0;
    }


    ull count = 0;
    
    n /= 2;

    while(n > 0) {
        count += n / 5;
        n /= 5;
    }


    cout << count << endl;

    return 0;


}