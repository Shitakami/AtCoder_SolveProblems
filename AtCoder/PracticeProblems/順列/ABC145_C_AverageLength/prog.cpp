#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    int n;
    double dist[10][10];
    cin >> n;

    vector<pair<int, int>> pos(n);
    vector<int> permutation(n);

    for(int i = 0; i < n; ++i) {
        cin >> pos[i].first >> pos[i].second;
    }

    for(int i = 0; i < n; ++i)
        permutation[i] = i;

    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            dist[i][j] = pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2);
            dist[i][j] = sqrt(dist[i][j]);
            dist[j][i] = dist[i][j];
        }

    }

    double ave = 0;
    while(1) {

        for(int i = 0; i < n - 1; ++i) {
            int pos_i = permutation[i];
            int nextPos_i = permutation[i + 1];
            ave += dist[pos_i][nextPos_i];
        }

        if(!next_permutation(permutation.begin(), permutation.end()))
            break;

    }

    int N = 1;
    for(int i = 2; i <= n; ++i)
        N *= i;

    printf("%.10f\n", ave / N);

    return 0;
}