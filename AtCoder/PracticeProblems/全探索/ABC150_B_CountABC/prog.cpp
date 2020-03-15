#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    
    cin >> n;

    char abc[] = {'A', 'B', 'C'};

    int count = 0;

    vector<char> s(n);

    cin >> s[0];
    cin >> s[1];

    for(int i = 2; i < n; ++i) {

        cin >> s[i];

        int j;
        for(j = 0; j < 3 && abc[j] == s[i - 2 + j]; j++) ;

        if(j == 3)
            count++;

    }

    cout << count << endl;

    return 0;

}