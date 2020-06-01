#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {

    int d, n, m;

    cin >> d >> n >> m;

    vector<int> shop(n + 1);
    vector<int> destinations(m);


    shop[1] = 0;
    for(int i = 1; i < n; ++i)
        cin >> shop[i];
    shop[n] = d;

    sort(shop.begin(), shop.end());


    for(int i = 0; i < m; ++i)
        cin >> destinations[i];


    int sum = 0;
    for(int i = 0; i < m; ++i) {

        int left = 0;
        int right = n + 2;
        int mid;
        while(right - left > 1) {
            mid = (left + right) / 2;
            if(shop[mid] > destinations[i])
                right = mid;
            else
                left = mid;
        }
        int a = abs(destinations[i] - shop[left]);
        int b = abs(destinations[i] - shop[left + 1]);
        sum += min(a, b);
    }


    cout << sum << endl;

    return 0;

}