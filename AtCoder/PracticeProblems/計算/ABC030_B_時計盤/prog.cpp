#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {

	double hour, minute;
	double a, b;
	cin >> hour >> minute;

	if (hour >= 12)
		hour -= 12;

	a = minute / 60.0 * 360.0;

	hour += minute / 60.0;

	b = hour / 12.0 * 360.0;


	if (a > b)
		swap(a, b);

	double ans = b - a;

	if (ans > 180)
		ans = 360 - ans;

	printf("%.10f\n", ans);

	return 0;

}
