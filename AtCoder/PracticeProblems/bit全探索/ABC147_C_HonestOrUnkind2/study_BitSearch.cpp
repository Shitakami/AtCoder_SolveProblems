#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, w;
    cin >> n >> w;

    vector<int> num(n);

    for(int i = 0; i < n; ++i) 
        cin >> num[i];

    int max = 1 << n;
    bool isExist = false;
    for(int bit = 1; bit < max; bit++) {

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(bit & (1 << i))sum += num[i];
        }

        if(sum == w)
            isExist = true;

    }

    if(isExist)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
    

    return 0;


}