#include <iostream>
#include <string>
using namespace std;

int main() {

    int a, b;
    string s1, s2;
    string lost_ball;
    
    cin >> s1 >> s2;
    cin >> a >> b;
    
    cin >> lost_ball;

    if(s1 == lost_ball)
        a--;
    else
        b--;

    cout << a << " " << b << endl;
    

    

    return 0;
}