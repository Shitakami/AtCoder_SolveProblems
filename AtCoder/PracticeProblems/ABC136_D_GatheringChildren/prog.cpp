#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    string s;

    cin >> s;

    vector<int> ans(s.size(), 0);

    int Rcount = 0;
    int Lcount = 0;

    int i_R = 0;
    int i_L = 0;

    while(1) {

        Rcount = 0;
        Lcount = 0;


        while(s[i_R] == 'R') {
            Rcount++;
            i_R++;
        }

        i_L = i_R;
        i_R--;

        while(s[i_L] == 'L') {
            Lcount++;
            i_L++;
        }
        
        // cout << i_R << " " << i_R + 1 << endl;

        ans[i_R] += (Rcount / 2) + Rcount % 2 + Lcount / 2;
        ans[i_R + 1] += Rcount / 2 + (Lcount / 2) + Lcount % 2;

        if(i_L == s.size())
            break;

        i_R = i_L;

    }

    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;

}
