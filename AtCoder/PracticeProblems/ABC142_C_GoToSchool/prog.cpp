#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> s(n);

    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        s[num - 1] = i + 1;

    }

    for(int i = 0; i < n; ++i) {
        if(i)
            cout << " ";
        cout << s[i];
    }

    cout << endl;

    return 0;

}