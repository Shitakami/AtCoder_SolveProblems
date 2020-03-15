#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> b(n - 1);
    vector<int> a(n);

    for(int i = 0; i < n - 1; ++i) {
        cin >> b[i];

    }

    a[0] = a[1] = b[0];

    for(int i = 1; i < n - 1; ++i) {

        if(b[i] < a[i]) {
            a[i] = b[i];
        }

        a[i + 1] = b[i];
    }
    
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += a[i];
   //     cout << a[i] << " ";
    }
    //cout << endl;
    cout << sum << endl;

    return 0;

}