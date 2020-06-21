#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i) {

        char ch;
        cin >> ch;

        v[i] = ch - '0';

    }

    int sum = 0;

    for(int i = 0; i <= 9; ++i) {
        for(int j = 0; j <= 9; ++j) {
            for(int k = 0; k <= 9; ++k) {

                int index = 0;
                while(index < n && v[index] != i)
                    index++;

                if(index == n)
                    continue;

                index++;

                while(index < n && v[index] != j)
                    index++;

                if(index == n)
                    continue;
                
                index++;

                while(index < n && v[index] != k)
                    index++;

                if(index != n)
                    sum++;

            }
        }

    }


    cout << sum << endl;

    return 0;

}