#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;


int n;


set<vector<int>> done;
set<string> ans;
void search(int index, string s, int maxI) {

   // cout << index << " " << s << endl;

    if(index == n) {
        cout << s << endl;
        return;
    }

    for(int i = 0; i <= maxI; ++i) {

        s[index] = 'a' + i;

        search(index + 1, s, max(i + 1, maxI));
    
    }

}

int main() {

    cin >> n;
    string s(n, 'a');
    search(1, s, 1);


    return 0;

}