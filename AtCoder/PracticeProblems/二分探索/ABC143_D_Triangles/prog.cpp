#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    auto isCorrect = [&](int a, int b, int c) {
        return v[c] < v[a] + v[b];
    };

    for(int i = 0; i < n - 2; ++i) {
        for(int j = i + 1; j < n - 1; ++j) {

            if(j == n - 2) {
                sum += isCorrect(i, j, n - 1);
                break;
            }

            int left = j + 1;
            int right = n;
            int mid;
            while(right - left > 1) {
                mid = (left + right) / 2;
                
                if(isCorrect(i, j, mid)) 
                    left = mid;
                else
                    right = mid;
               //  cout << left << " " << right << endl;
            }
            
            if(isCorrect(i, j, left))
                sum += left - j;

/*
            cout << i << ":" << j << " : " << left << endl;
            cout << "left = " << left << ", " << "right = " << right << endl;
            cout << v[i] << "+" << v[j] << " = " << v[i] + v[j] << " : " << v[left] << endl;
            cout << endl;
*/

        }

    }
    
    cout << sum << endl;

    return 0;

}