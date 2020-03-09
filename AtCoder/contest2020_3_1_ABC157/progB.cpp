#include <iostream>
#include <vector>
using namespace std;

int main() {

    int bingo[3][3];

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j)
            cin >> bingo[i][j];
    }    

    int n;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        for(int bi = 0; bi < 3; bi++) {
            for(int bj = 0; bj < 3; bj++) {
                if(bingo[bi][bj] == num)
                    bingo[bi][bj] = 0;
            }
        }

    }

    bool isBingo = false;

    for(int i = 0; i < 3; ++i) {

        int Rsum = bingo[i][0] + bingo[i][1] + bingo[i][2];
        if(Rsum == 0)
            isBingo = true;

        int Csum = bingo[0][i] + bingo[1][i] + bingo[2][i];
        if(Csum == 0)
            isBingo = true;

    }


    if(bingo[0][0] + bingo[1][1] + bingo[2][2] == 0)
        isBingo = true;
    
    if(bingo[0][2] + bingo[1][1] + bingo[2][0] == 0)
        isBingo = true;

    if(isBingo)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}