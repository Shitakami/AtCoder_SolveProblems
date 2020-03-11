#include <iostream>
#include <set>
using namespace std;

int main() {

    int n;
    set<int> s;

    cin >> n;

    int count = 0;
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if(s.find(num) == s.end())
            s.insert(num);
        else
            count++;

    }

    cout << count << endl;

}