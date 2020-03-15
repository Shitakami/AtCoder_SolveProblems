#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    int min_num;
    long long int sum = 1;
    cin >> n;

    cin >> min_num;

    for(int i = 2; i <= n; ++i) {

        int num;
        cin >> num;

        if(min_num >= num)
            sum++;

        min_num = min(min_num, num);


    }

    cout << sum << endl;

    return 0;

}