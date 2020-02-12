#include <iostream>
#include <map>
using namespace std;

int main() {

    map<int, bool> numbers = map<int, bool>();

    int n;
    bool isTrue = true;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        int in_num;
        cin >> in_num;

        if(numbers.find(in_num) != numbers.cend()) {
            isTrue = false;

        }
        else {
            numbers[in_num] = true;

        }

    }

    if(isTrue)
        cout << "YES";
    else
        cout << "NO";

    cout << endl;

    return 0;

}