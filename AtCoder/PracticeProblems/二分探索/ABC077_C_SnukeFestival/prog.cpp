/*
 * WAとなったプログラム
 * 初めに b_i より小さい a_i の個数を求めて
 * それまでの組み合わせの個数として保存
 * 
 * 次に、c_i より小さい b_i のインデックスを求めて
 * 保存された組み合わせの個数を足していく
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

void printVector(vector<int> v) {

    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

}

int main() {

    int n;

    cin >> n;

    vector<int> a(n), b(n), c(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n; ++i)
        cin >> b[i];

    for(int i = 0; i < n; ++i)
        cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    cout << endl;
    printVector(a);
    printVector(b);
    printVector(c);

    vector<ll> bSum(n, 0);

    for(int i = 0; i < n; ++i) {

        if(i)
            bSum[i] = bSum[i - 1];

        int left = 0, right = n;
        int mid;
        while(right - left > 1) {

            mid = (right + left) / 2;

            if(a[mid] >= b[i]) 
                right = mid;
            else
                left = mid;

        }

        
        bSum[i] += (left + 1);


    }

    cout << endl;

    for(int i = 0; i < n; ++i)
        cout << bSum[i] << " ";
    cout << endl;


    ll sum = 0;
    cout << endl;
    for(int i = 0; i < n; ++i) {

        int left = 0, right = n;
        int mid;
        while(right - left > 1) {

            mid = (right + left) / 2;

            if(b[mid] >= c[i])
                right = mid;
            else
                left = mid;

        }

        cout << c[i] << " " << left << " : " << bSum[left] << endl;

        if(left == 0 && c[i] <= b[0])
            continue;

        sum += bSum[left];

    }


    cout << sum << endl;

    return 0;

}