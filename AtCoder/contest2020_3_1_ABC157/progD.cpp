/*
 * 未だ解けていない
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int n;

int calc(int p, int index, set<int> &visited, set<int> &acquaintance, int sum) {
        cout << "visit: " << p << " " << index << ", sum = " << sum <<  endl;
        visited.insert(index);
        for(int i = 0; i < n; ++i) {
            if(v[p][i] == -1 || v[index][i] == -1)
                continue;
            if(v[index][i] == 1 && visited.find(i) == visited.end()) {

                sum += calc(p, i, visited, acquaintance, sum);
            }
            else if(v[index][i] == 0) {

                if(acquaintance.find(i) == acquaintance.end()) {
                    sum++;
                    acquaintance.insert(i);
                }
            }
        }

        return sum;
}



int main() {


    int m, k;

    cin >> n >> m >> k;

    v = vector<vector<int>>(n, vector<int>(n, 0));

    for(int i = 0; i < n; ++i)
        v[i][i] = -1;

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a][b] = v[b][a] = 1;
    }

    for(int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        v[a][b] = v[b][a] = -1;
    }



    for(int i = 0; i < n; ++i) {

        set<int> visited;
        set<int> acquaintance;
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(v[i][j] == 1 && visited.find(j) == visited.end())
                sum += calc(i, j, visited, acquaintance, sum);
        }
        cout << sum << " ";

    }
    cout << endl;

    return 0;
}