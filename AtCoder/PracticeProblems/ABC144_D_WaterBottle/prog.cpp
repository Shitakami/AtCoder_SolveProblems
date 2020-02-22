#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double x, y, s;

    cin >> x >> y >> s;

    s /= x;

    double h;
    double theta;
    if(x * y / 2 <= s) {

        h = 2 * (x * y - s) / x;
        theta = atan2(h, x);
    }
    else {
        h = 2 * s / y;
        theta = atan2(y, h);
    }

    double pi = acos(-1);

    printf("%.10f", theta / (pi * 2) * 360);


}