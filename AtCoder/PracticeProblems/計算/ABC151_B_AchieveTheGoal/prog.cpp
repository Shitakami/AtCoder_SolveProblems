#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k, goal;

    cin >> n >> k >> goal;

    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        sum += num;
    }

    goal *= n;
    goal -= sum;

    if(goal <= k)
        cout << (goal >= 0 ? goal : 0) << endl;
    else
    {
        cout << -1 << endl;
    }
    
    return 0;

}