#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

char WinHand(char hand) {

    if(hand == 'r')
        return 'p';
    else if(hand == 's')
        return 'r';

    return 's';    

}

int main() {

    int n, k;
    map<char, int> hand;
    long long int sum = 0;
    int r, s, p;
    queue<char> oldHands;
    string hands;

    cin >> n >> k;

    cin >> r >> s >> p;

    hand['r'] = r;
    hand['s'] = s;
    hand['p'] = p;

    cin >> hands;

    for(int i = 0; i < k; ++i) {
        
        int j = i;
        while(j + k < n) {

            int sameCount = 0;
            int index;
            for(index = j; index + k < n && hands[index] == hands[index + k]; index += k)
                sameCount++;


        }

    }

    cout << endl;
    cout << sum << endl;
    return 0;

}