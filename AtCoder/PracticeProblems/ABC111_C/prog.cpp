#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    map<int, int> count_odd;
    map<int, int> count_even;
    int n;

    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i];

        if(i % 2) {

            if(count_odd.find(v[i]) == count_odd.end())
                count_odd[v[i]] = 1;
            else
                count_odd[v[i]]++;


        }
        else {

            if(count_even.find(v[i]) == count_even.end())
                count_even[v[i]] = 1;
            else
                count_even[v[i]]++;

        }

    }


       int odd_ans = 0;
       int even_ans = 0;
       for(auto itr = count_odd.begin(); itr != count_odd.end(); ++itr) {
           ans = max(itr->second, ans);

       }
       for(auto itr = count_even.begin(); itr != count_even.end(); ++itr) {
           ans = max(itr->second, ans);

       }
       cout << ans << endl;

    return 0;

}