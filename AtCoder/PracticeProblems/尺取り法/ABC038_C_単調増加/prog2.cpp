#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    int count = 0;
    int answer = 0;

    for(int i = 0; i < n; ++i) {

        cin >> v[i];

        if(!v[i])
            continue;

        if(v[i - 1] < v[i]) {
            count++;

        }
        else {
            for(int j = 1; j <= count; ++j)
                answer += j;
            count = 1;

        }

    }

    for(int j = 1; j <= count; ++j)
        answer += j;

    cout << answer << endl;
    return 0;

}