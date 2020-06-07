#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {

    int n;
    string s;

    cin >> n;
    cin >> s;

    vector<int> sint(n);

    for(int i = 0; i < n; ++i) {
        
        switch(s[i]) {
            case 'R':
                sint[i] = 0;
                break;
            case 'G':
                sint[i] = 1;
                break;
            case 'B':
                sint[i] = 2;
                break;
        }

    }

    vector<vector<int>> Count(3, vector<int>(n, 0));

    Count[sint[0]][0]++;

    for(int i = 1; i < n; ++i) {

        if(sint[i] == 0)
            Count[0][i]++;
        else if(sint[i] == 1)
            Count[1][i]++;
        else 
            Count[2][i]++;

        Count[0][i] += Count[0][i - 1];
        Count[1][i] += Count[1][i - 1];
        Count[2][i] += Count[2][i - 1];

    }

    long long sum = 0;

    for(int i = 0; i < n - 2; ++i) {
        for(int j = i + 1; j < n - 1; ++j) {

            if(sint[i] == sint[j])
                continue;

            int color = 3 - sint[i] - sint[j];
            sum += Count[color][n - 1] - Count[color][j];

            int k = 2 * j - i;
            if(k < n && sint[k] == color)
                sum--;

        }
    }

   // cout << endl;
    cout << sum << endl;

    return 0;

}