#include <iostream>
#include <map>
#include <string>
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
    string hands;

    cin >> n >> k;

    cin >> r >> s >> p;

    hand['r'] = r;
    hand['s'] = s;
    hand['p'] = p;

    cin >> hands;

    for(int i = 0; i < k; ++i) {
        
        int j = i;
        while(j < n) {


            int sameCount = 1;
            int index;
            char nowHand = hands[j];
            for(index = j; index + k < n && hands[index] == hands[index + k]; index += k)
                sameCount++;

            

            if(sameCount == 1) {
                sum += hand[WinHand(nowHand)];
                j += k;
            }
            else {
                if(sameCount % 2 == 0) {
                    sum += hand[WinHand(nowHand)] * sameCount / 2;
                }
                else {
                    sum += hand[WinHand(nowHand)] * (sameCount / 2 + 1);
                }

                j = index + k;
            }


        }

    }
    cout << sum << endl;
    return 0;

}