#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, k, q;

    cin >> n >> k >> q;

    vector<int> point(n, 0);


    for(int i = 0; i < q; ++i) {
        int num;
        cin >> num;

        point[num - 1]++;

    }

    for(int i = 0; i < n; ++i) {

        if(k - q + point[i] > 0)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;


    }

    return 0;

}