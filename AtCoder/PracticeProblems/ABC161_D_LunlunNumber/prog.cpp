#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
using namespace std;


int main() {

    using ll = unsigned long long;

    int n;
    ll number = 1;

    cin >> n;

    queue<ll> q;

    for(int i = 1; i <= 9; ++i)
        q.push(i);

    int count = 0;

    while(1) {

        number = q.front(); q.pop();
      //  cout << number << endl;

        count++;
        
        if(count == n)
            break;

        if(number % 10 != 0)
            q.push(number * 10 + number % 10 - 1);
        
        q.push(number * 10 + number % 10);

        if(number % 10 != 9)
            q.push(number * 10 + number % 10 + 1);



    }

   // cout << endl;

    cout << number << endl;

}

