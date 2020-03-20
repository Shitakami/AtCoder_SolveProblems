#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> v(n);

    vector<set<int>> numberMap(n);

    for(int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        v[i] = ch - '0';
    }

    for(int i = 0; i < n; ++i) {

        if(i)
            numberMap[i] = numberMap[i - 1];
        numberMap[i].insert(v[i]);

    }

    int sum = 0;
    for(int i = 0; i <= 9; ++i) {
        for(int j = 0; j <= 9; ++j) {
            for(int k = 0; k <= 9; ++k) {

                int v_i = 0;
                for(v_i = 0; v_i < n - 2; ++v_i) 
                    if(v[v_i] == i)
                        break;

                if(v_i == n - 2)
                    continue;

                int v_j = v_i + 1;
                for( ; v_j < n - 1; ++v_j)
                    if(v[v_j] == j)
                        break;
                if(v_j == n - 1)
                    continue;
                
                int v_k = v_j + 1;
                for( ; v_k < n; ++v_k)
                    if(v[v_k] == k)
                        break;
                if(v_k == n)
                    continue;
                
                sum++;
            }
        }
    }

    cout << sum << endl;


    return 0;
}