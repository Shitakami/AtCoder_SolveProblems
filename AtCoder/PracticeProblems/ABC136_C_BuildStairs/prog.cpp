#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n + 1);
    vector<bool> doneDown(n + 1, false);
    v[0] = -1;

    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    for(int i = 1; i < n; ++i) {

        if(v[i] - v[i + 1] > 1) {

            cout << "No" << endl;
            return 0;
        }
        else if(v[i] - v[i + 1] == 1) {

            v[i]--;
            doneDown[i] = true;
            int j = i;
            while(j > 0 && v[j - 1] - v[j] == 1) {
                j--;
                if(doneDown[j]) {
                    cout << "No" << endl;
                    return 0;
                }

                v[j]--;
                doneDown[j] = true;

            }

        }

    }

    cout << "Yes" << endl;

    return 0;

}