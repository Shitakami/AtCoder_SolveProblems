    #include <iostream>
    #include <vector>
    #include <cmath>
    using namespace std;

vector<int> division(int x) {

    vector<int> retV;

    for(int i = 2; i * i < x; i++) {

        if(x % i != 0)
            continue;


        retV.push_back(i);
        
        while(x % i == 0) {
            x /= i;
        }

    }

    if(x != 1)
        retV.push_back(x);

    return retV;
}

    int main() {

        int x, n;

        cin >> x >> n;

        vector<int> v(102, 0);

        for(int i = 0; i < n; ++i) {
            int index;
            cin >> index;
            v[index] = 1;

        }

        int minD = 1000000;
        int minValue = 10000;

        for(int i = 0; i <= 101; ++i) {

            if(i >= 0 && v[i])
                continue;

            int a = abs(x - i);
            if(minD > a) {

                minD = a;
                minValue = i;

            }

        }

        cout << minValue << endl;

        return 0;    

    }