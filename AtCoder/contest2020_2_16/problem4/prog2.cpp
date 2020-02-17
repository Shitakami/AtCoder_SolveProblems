/*
 * ミス回答
 * TLEになった
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    vector<long long int> numbers;
    vector<long long int> mult;

    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }


    for(int i = 0; i < n - 1; ++i) {

        for(int j = i + 1; j < n; ++j) {
            mult.push_back(numbers[i] * numbers[j]);
        }
    }

    sort(mult.begin(), mult.end());

/*
    for(int i = 0; i < mult.size(); ++i) 
        cout << i + 1 << " "  << mult[i] << endl;
*/
    cout << mult[k - 1] << endl;

    return 0;

}