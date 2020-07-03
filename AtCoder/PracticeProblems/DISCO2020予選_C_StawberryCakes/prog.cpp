#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {

    int h, w, k;

    cin >> h >> w >> k;

    vector<vector<int>> cakes(h, vector<int>(w, -1));
    int count = 1;

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            char ch;
            cin >> ch;

            if(ch != '.')
                cakes[i][j] = count++;

        }

    }

    vector<int> hCount(h, 0);

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j)
            if(cakes[i][j] != -1)        
                hCount[i]++;
    }

    for(int j = 0; j < w; ++j) {
        int i = 0;

        while(i < h && cakes[i][j] == -1)
            i++;
    
        if(i == h)
            continue;

        int first_i = i;
        int sValue = cakes[i][j];

        while(--i != -1)
            cakes[i][j] = sValue;


        for(i = first_i + 1; i < h; ++i) {
            if(cakes[i][j] == -1)
                cakes[i][j] = cakes[i - 1][j];
        }

    }

    int first_j;
    int j = 0;

    while(j < w && cakes[0][j] == -1)
        j++;
    
    

    first_j = j;

    if(j != w) {
        while(--j != -1) {
            for(int i = 0; i < h; ++i)
                cakes[i][j] = cakes[i][j + 1];
        }
    }

    for(j = first_j + 1; j < w; ++j) {
        if(cakes[0][j] != -1)
            continue;

        for(int i = 0; i < h; ++i)
            cakes[i][j] = cakes[i][j - 1];


    }
    

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(j)
                cout << " ";
            cout << cakes[i][j];
        }
        cout << endl;
    }

    return 0;

}