#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> blocks;
    int breakCount = 0;

    blocks.push_back(-1);

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        blocks.push_back(num);
    }

    int i = 1;
    int index = 1;

    while(index <= n) {
        
        while(index <= n && blocks[index] != i) {
            breakCount++;
            index++;
        }

        if(index != n + 1)
            i += 1;
        index += 1;

    }
    

    if(i == 1 && breakCount != 0) {
        cout << -1 << endl;
    }
    else 
        cout << breakCount << endl;

    return 0;

}