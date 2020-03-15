#include <iostream>
using namespace std;

int main() {

    long long int HP;
    long long int sum = 0;
    long long int MonsterCount = 1;

    cin >> HP;

    while(HP != 0) {

        HP /= 2;

        sum += MonsterCount;
        MonsterCount *= 2;


    }

    cout << sum << endl;

    return 0;


}