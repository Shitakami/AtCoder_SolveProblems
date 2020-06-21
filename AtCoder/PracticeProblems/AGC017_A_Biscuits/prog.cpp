#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

ull C(int size, int count) {

    ull x = 1;
    ull y = 1;

    for(int i = 0; i < count; ++i) {
        x *= (size - i);
        y *= (i + 1);

        if(x % y == 0) {
            x /= y;
            y = 1;
        }

    }

    return x / y;
}

int main() {

    int n, p;

    cin >> n >> p;

    int even = 0;
    int odd = 0;

    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if(a % 2 == 0)
            even++;
        else
            odd++;

    }

    ull answer = 0;

    if(p == 0) {

        for(int i = 0; i <= even; ++i)
            answer += C(even, min(i, even - i));

        ull evenC = answer;

        if(evenC != 0) {
            for(size_t i = 2; i <= odd; i+=2)
                answer += evenC * C(odd, min(i, odd - i));
        }

    }
    else {

        for(size_t i = 1; i <= odd; i+=2)
            answer += C(odd, min(i, odd - i));

        ull oddC = answer;

        if(oddC != 0) {
            for(size_t i = 1; i <= even; ++i)
                answer += C(even, min(i, even - i)) * oddC;
        }

    }


    cout << answer << endl;

    return 0;

}