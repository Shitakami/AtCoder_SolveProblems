#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

using ll = long long;



int main() {

    int n;

    cin >> n;

    map<map<char, int>, int> stringList;

    for(int i = 0; i < n; ++i) {
        
        map<char, int> m;

        for(int j = 0; j < 10; ++j) {
            
            char ch;
            cin >> ch;
            
            if(m.find(ch) == m.end())
                m.emplace(ch, 0);
            else
                m[ch]++;

        }

        if(stringList.find(m) == stringList.end()) 
            stringList.emplace(m, 0);
        else {
            stringList[m]++;
        

        }
    }

    ll count = 0;

    for(const auto &m : stringList) {
        
        ll sum = 0;
        for(int i = 1; i <= m.second; ++i) {
            sum += i;

        }
        count += sum;
    }

    cout << count << endl;

    return 0;

}