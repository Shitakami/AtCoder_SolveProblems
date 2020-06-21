#include <iostream>
#include <vector>

using namespace std;

using ull = unsigned long long;

int main() {

    ull n;

    cin >> n;

    vector<pair<ull, ull>> a;

    ull num = 2;

    while(num * num <= n) {

        if(n % num != 0) {
            num++;
            continue;
        }

        ull count = 0;

        while(n % num == 0) {
            n /= num;
            count++;
        }

        a.push_back(make_pair(num, count));
        num++;

    }

    if(n != 1)
        a.push_back(make_pair(n, 1));

    ull answer = 0;
    for(int i = 0; i < a.size(); ++i) {

        ull count = 1;

        while(a[i].second >= count) {
            answer++;
            a[i].second -= count;
            count++;
        }

    }

    cout << answer << endl;
    return 0;

}