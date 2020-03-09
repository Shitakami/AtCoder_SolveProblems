#include <iostream>
using namespace std;

int main() {

    int a, b;

    cin >> a >> b;

    int i;
    for(i = 1; i <= 1000; ++i) {

        int at = i * 0.08;
        int bt = i * 0.1;

      //  cout << at << " " << bt << endl;

        if(at == a && bt == b) {
            cout << i << endl;
            return 0;

        }
            
    }

    cout << -1 << endl;

    return 0;

}