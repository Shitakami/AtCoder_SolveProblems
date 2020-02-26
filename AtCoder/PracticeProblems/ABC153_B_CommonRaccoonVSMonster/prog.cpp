#include <iostream>
using namespace std;

int main() {

    int h, n;
    cin >> h >> n;

    int sum = 0;
    for(int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        sum += p;

    }

    if(sum >= h)
        cout << "Yes";
    else
    {
        cout << "No";
    }
    
    cout << endl;

    return 0;

}